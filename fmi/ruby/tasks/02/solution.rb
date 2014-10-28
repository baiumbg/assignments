class NumberSet
  include Enumerable

  def initialize
    @numbers = Array.new
  end

  def <<(number)
    @numbers << number if ! @numbers.include? number
  end

  def size
    @numbers.size
  end

  def empty?
    @numbers.empty?
  end

  def [](filter)
    @numbers.select { |number| filter.passes? number }
  end

  def each(&block)
   @numbers.each do |number|
     yield number
   end
  end
end


class Filter
  def initialize(&block)
    @block = block
  end

  def passes?(number)
    @block.call(number)
  end

  def &(other_filter)
    Filter.new { |number| passes? number and other_filter.passes? number}
  end

  def |(other_filter)
    Filter.new { |number| passes? number or other_filter.passes? number}
  end
end

class TypeFilter
  def initialize(type)
    @type = type
  end

  def passes?(number)
    case @type
    when :integer then number.is_a? Fixnum
    when :real then number.is_a? Float or number.is_a? Rational
    when :complex then number.is_a? Complex
    end
  end

  def &(other_filter)
    Filter.new { |number| passes? number and other_filter.passes? number}
  end

  def |(other_filter)
    Filter.new { |number| passes? number or other_filter.passes? number}
  end
end

class SignFilter
  def initialize(sign)
    @sign = sign
  end

  def passes?(number)
    case @sign
    when :positive then number > 0
    when :negative then number < 0
    when :non_negative then number >= 0
    when :non_positive then number <= 0
    end
  end

  def &(other_filter)
    Filter.new { |number| passes? number and other_filter.passes? number}
  end

  def |(other_filter)
    Filter.new { |number| passes? number or other_filter.passes? number}
  end
end
