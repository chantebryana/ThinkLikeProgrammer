print "Enter a digit then press ENTER: "
digit = gets.to_i
digitDouble = digit * 2
print digitDouble.to_s + "\n"

digitArray = digit.to_s.chars.map(&:to_i)
digitArrayLong = digit.to_s.each_char.to_a.map{|char| char.to_i}
# chars returns array of characters in string.  it's shorthand for: str.each_char.to_a
# map(&:to_i) is also shorthand for map{|char| char.to_i} The & calls to_proc on the object, and passes it as a block to the method.

sum = 0
digitArray.each do |a|
  sum+=a
end
print sum.to_s + "\n"
#put "print" method after the each loop so that I only get the sum of the whole array, not the sum as the function's iterating through the array.
