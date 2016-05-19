print "Enter a digit then press ENTER: "
digit = gets

digitArray = digit.chars.map(&:to_i)

digitArray.each_with_index do |value, index|
  valueDouble = 0
  valueArray = []
  valueSum = 0
  masterArray = []
  if index % 2 == 0
    masterArray << value
#    print "even indeces: " + value.to_s + "\n"
  elsif index % 2 == 1
    valueDouble = value * 2
#    print "odd indeces: " + value.to_s + "\n"
#	print "valueDouble: " + valueDouble.to_s + "\n"
	if valueDouble > 9
	  valueArray = valueDouble.to_s.chars.map(&:to_i)
	    valueArray.each do |a| 
	      valueSum += a 
        end
#	  print "valueSum: " + valueSum.to_s + "\n"
	  masterArray << valueSum 
	end
  end 
  masterArray.map do |value| 
    print "masterArray: " + value.to_s + ", "
  end 
  masterSum = 0
  masterArray.each do |value| 
    masterSum += value
  end 
  print "masterSum: " + masterSum.to_s + "\n"
end

sum = 0
digitArray.each do |a|
  sum+=a
end
print "sum.to_s: " + sum.to_s + "\n"

digitDouble = digit * 2
print "digitDouble: " + digitDouble.to_s + "\n"
