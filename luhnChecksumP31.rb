print "Enter a digit then press ENTER: "
digit = gets.to_i

digitArray = digit.to_s.chars.map(&:to_i)

digitArray.each_with_index do |value, index|
  valueDouble = 0
  valueArray = []
  valueSum = 0
  if index % 2 == 0
    print "even indeces: " + value.to_s + "\n"
  end
  if index % 2 == 1
    valueDouble = value * 2
    print "odd indeces: " + value.to_s + "\n"
	print "valueDouble: " + valueDouble.to_s + "\n"
	if valueDouble > 9
	  valueArray = valueDouble.to_s.chars.map(&:to_i)
	  valueArray.each do |a| 
	    valueSum += a 
      end
	  print "valueSum: " + valueSum.to_s + "\n"
	end
  end 
end

sum = 0
digitArray.each do |a|
  sum+=a
end
print "sum.to_s: " + sum.to_s + "\n"

digitDouble = digit * 2
print "digitDouble: " + digitDouble.to_s + "\n"