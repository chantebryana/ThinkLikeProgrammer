print "Enter an integer then press ENTER: "
digit = gets.to_i 

digitArray = digit.to_s.chars.map(&:to_i)

$masterSum = 0
digitArray.each_with_index do |value, index|
# define internal variables
  valueDouble = 0
  valueArray = []
  valueSum = 0
  masterArray = []
# begin interal loops
    if digitArray.length % 2 == 0 #if digitArray is even
	  if index % 2 == 0
		masterArray << value
	  elsif index % 2 == 1
		valueDouble = value * 2
		if valueDouble > 9
		  valueArray = valueDouble.to_s.chars.map(&:to_i)
			valueArray.each do |value| 
			  valueSum += value 
			end
		  masterArray << valueSum 
		else 
		  masterArray << valueDouble 
		end
	  end 
	  masterArray.each do |value| 
		$masterSum += value
	  end
	else #if digitArray is odd 
	  if digitArray.length % 2 == 1 
	    if index % 2 == 1 
		  masterArray << value
		elsif index % 2 == 0 
		  valueDouble = value * 2 
		  if valueDouble > 9 
		    valueArray = valueDouble.to_s.chars.map(&:to_i) 
			  valueArray.each do |value| 
			    valueSum += value 
			  end 
			masterArray << valueSum 
	      else 
		    masterArray << valueDouble 
		  end 
		end 
	  end 
	  masterArray.each do |value| 
		$masterSum += value
	  end
    end 
# add verification check:  
  print "masterArray value: " + masterArray.join("") + "\n"
end
print "masterSum: " + $masterSum.to_s + "\n"

if $masterSum % 10 == 0
  print "Success! Data passes the test! \n"
else 
  print "Dope! Data failed. \n"
end
