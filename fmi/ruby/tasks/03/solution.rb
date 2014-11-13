module RBFS
  class File
    attr_reader :data
    attr_reader :data_type

    def initialize(data = nil)
      self.data = data
    end

    def data=(new_data)
      @data = new_data
      case new_data
        when NilClass              then @data_type = :nil
        when String                then @data_type = :string
        when Symbol                then @data_type = :symbol
        when TrueClass, FalseClass then @data_type = :boolean
        when Fixnum, Float         then @data_type = :number
      end
    end

    def serialize
      "#{@data_type}:#{@data}"
    end

    def self.parse(string_data)
      type, data = string_data.split(':')
      case type
        when "string"  then new(data)
        when "symbol"  then new(data.to_sym)
        when "boolean" then new(check_boolean(data))
        when "number"  then new(format_num(data))
        when "nil"     then new(nil)
      end
    end

    def self.check_boolean(data)
      data == "true" ? true : false
    end

    def self.format_num(data)
      data.include?('.') ? data.to_f : data.to_i
    end

    private_class_method :check_boolean, :format_num
  end

  class Directory
    attr_reader :files
    attr_reader :directories

    def initialize
      @files = {}
      @directories = {}
    end

    def add_file(name, file)
      @files[name] = file
    end

    def add_directory(name, directory = Directory.new)
      @directories[name] = directory
    end

    def [](name)
      if @directories.has_key? name then @directories[name]
      elsif @files.has_key? name then @files[name]
      end
    end

    def serialize
      result = "#{files.length}:"
      @files.each do |key, value|
        result << "#{key}:#{value.serialize.length}:#{value.serialize}"
      end
      result << "#{directories.length}:"
      @directories.each do |key, value|
        result << "#{key}:#{value.serialize.length}:#{value.serialize}"
      end
      result
    end

    def self.parse(string_data)
      parsed_dir = Directory.new
      files, remaining_data = parse_files(string_data)
      files.each { |name, file| parsed_dir.add_file(name, file) }
      directories = parse_directories(remaining_data)
      directories.each { |name, directory| parsed_dir.add_directory(name, directory) }
      parsed_dir
    end

    def self.parse_files(string_data)
      files = {}
      number_of_files, remaining_data = string_data.split(':', 2)
      number_of_files.to_i.times do
        file_name, file_length, remaining_data = remaining_data.split(':', 3)
        file_contents = remaining_data.slice!(0, file_length.to_i)
        files[file_name] = File.parse(file_contents)
      end
      [files, remaining_data]
    end

    def self.parse_directories(string_data)
      directories = {}
      number_of_directories, remaining_data = string_data.split(':', 2)
      number_of_directories.to_i.times do
       dir_name, dir_length, remaining_data = remaining_data.split(':', 3)
       dir_contents = remaining_data.slice!(0, dir_length.to_i)
       directories[dir_name]= Directory.parse(dir_contents)
      end
      directories
    end

    private_class_method :parse_files, :parse_directories
  end
end
