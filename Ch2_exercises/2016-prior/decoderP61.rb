print "User, enter positive integers separated by a comma and a space \n"
print "(eg, \"12, 31, 527\"), then press Enter: "
inputArray = gets.split(", ")

#inputArray << gets.to_i 
inputArray.map {|x| print x + "\n"}

symbolArray = ["!", "?", ",", ".", " ", ";", "\"", "\'"]
#symbolArray.each {|i| print i + "\n"}

capsArray = %w[A B C D E F G H I J K L M N O P Q R S T U V W X Y Z]
#capsArray.each {|i| print i + "\n"}

downArray = %w[a b c d e f g h i j k l m n o p q r s t u v w x y z]
#downArray.each {|i| print i + "\n"}

message = "Hello World!"
messageCode = [35, 27, 32, 39, 39, 42, 27, 14, 9, 50, 27, 42, 45, 39, 31, 27, 10]

mode = 1 

inputArray.map do |valueInput| 
  if mode == 1 
	capsArray.each_with_index do |valueCaps, indexCaps| 
	  if valueInput.to_i % 27 == indexCaps + 1 
		print valueCaps + "\n"
	  elsif valueInput.to_i % 27 == 0
		mode = 2 
		break 
	  end 
	end 
  elsif mode == 2 
    downArray.each_with_index do |valueDown, indexDown| 
	  if valueInput.to_i % 27 == indexDown + 1 
	    print valueDown + "\n"
	  elsif valueInput.to_i % 27 == 0 
	    mode = 3 
		break 
	  end 
	end 
  elsif mode == 3  
    symbolArray.each_with_index do |valueSymbol, indexSymbol| 
	  if valueInput.to_i % 9 == indexSymbol + 1 
	    print valueSymbol + "\n"
	  elsif valueInput.to_i % 9 == 0 
	    mode = 1 
		break 
	  end 
	end  
  end 
end 

print mode.to_s + "\n"

=begin 
mode = 1 

if mode == 1 
	capsArray.each_with_index do |valueCaps, indexCaps|
	  inputArray.map do |valueInput| 
		if valueInput.to_i % 27 == indexCaps + 1 
		  print valueCaps + "\n"
		elsif valueInput.to_i % 27 == 0 
		  mode = 2 
		  break 
		end 
	  end
	end
end 

if mode == 2 
	downArray.each_with_index do |valueDown, indexDown|
	  inputArray.map do |valueInput| 
		if valueInput.to_i % 27 == indexDown + 1 
		  print valueDown + "\n"
		elsif valueInput.to_i % 27 == 0 
		  mode = 3 
		  break 
		end 
	  end
	end
end

print "mode: " + mode.to_s + "\n" 

=end 
