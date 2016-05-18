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

#this may be going about the problem the wrong way:
digitArray.values_at(* digitArray.each_index.select {|i| i.odd?})

#pseudocode:
digitArray.map do 
  if index % 2 == 1
    element * 2
	  if result > 9
	    separate the numbers out and add them together
	end
  end
end 

