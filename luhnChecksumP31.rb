print "Enter a digit then press ENTER: "
digit = gets.to_i
digitDouble = digit * 2
print digitDouble.to_s + "\n"

digitArray = digit.to_s.chars.map(&:to_i)

sum = 0
digitArray.each do |a|
  sum+=a
end
print sum.to_s + "\n"
# I could also use "inject"

digitArray.each_with_index do |value, index|
  valueDouble = 0
  valueArray = []
  valueSum = 0
  if index % 2 == 1
    valueDouble = value * 2
    print value.to_s + ", "
	if valueDouble > 9
	  valueArray = valueDouble.to_s.chars.map(&:to_i)
#valueArray.each {|i| print i.to_s + ", "}
	  valueArray.each do |a| 
	    valueSum += a 
      end
	  print valueSum.to_s
	end
  end 
end

