def series(type, position)
  if(type == "fibonacci") then fibonacci(position)
  elsif(type == "lucas") then lucas(position)
  else fibonacci(position) + lucas(position)
  end
end

def fibonacci(position)
  position <= 2 ? 1 : fibonacci(position - 1) + fibonacci(position - 2)
end

def lucas(position)
  if(position == 1) then 2
  elsif(position == 2) then 1
  else lucas(position - 1) + lucas(position - 2)
  end
end
