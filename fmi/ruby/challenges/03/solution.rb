class String
  def word_wrap(max_width)
    scan(/\S.{0,#{max_width-2}}\S(?=\s|$)|\S+/)
  end
end
