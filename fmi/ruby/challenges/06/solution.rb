class Class
  def attr_initializer(*args)
    define_method(:initialize) do |*init_args|
      unless args.length == init_args.length
        raise ArgumentError, "wrong number of arguments (#{init_args.length} for #{args.length})"
      end
      args.zip(init_args).each do |arg, init_arg|
        self.instance_eval("@#{arg} = #{init_arg}")
      end
    end
  end
end
