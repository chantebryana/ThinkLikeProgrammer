print "Enter a digit then press ENTER: "
digit = gets.to_i
digitDouble = digit * 2
print digitDouble.to_s + "\n"

digitArray = digit.to_s.chars.map(&:to_i)
digitArray

sum = 0
digitArray.each do |a|
  sum+=a
end
print sum.to_s + "\n"
# I could also use "inject"

digitArray.each_with_index do |value, index|
  if index % 2 == 1
    print value.to_s + ", "
  end 
end

