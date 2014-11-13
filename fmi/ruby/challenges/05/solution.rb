class String
  def anagrams(words = [])
    if block_given?
      words.each do |word|
        yield word if downcase.chars.sort == word.downcase.chars.sort
      end
    else
      result = []
      words.each do |word|
        result << word if downcase.chars.sort == word.downcase.chars.sort
      end
      result.to_enum
    end
  end
end
