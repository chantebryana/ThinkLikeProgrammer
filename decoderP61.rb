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

def capsFunc 
  capsArray.each_with_index do |valueCaps, indexCaps|
    inputArray.map do |valueInput|
  	  if valueInput.to_i % 27 == indexCaps + 1 
	    print valueCaps
	  end 
	end 
  end 
end 

def downFunc 
  downArray.each_with_index do |valueDown, indexDown|
    inputArray.map do |valueInput|
  	  if valueInput.to_i % 27 == indexDown + 1 
	    print valueDown
	  end 
	end 
  end 
end 

def symbolFunc 
  capsArray.each_with_index do |valueSymbol, indexSymbol|
    inputArray.map do |valueInput|
  	  if valueInput.to_i % 27 == indexSymbol + 1 
	    print valueSymbol
	  end 
	end 
  end 
end 

mode = 1 

if mode == 1 
  if valueInput.to_i % 27 == 0
    mode = 2
  elsif valueInput.to_i % 27 > 0
    capsFunc 
  else 
    print "capsError!"
  end 
elsif mode == 2  
  if valueInput.to_i % 27 == 0
    mode = 3  
  elsif valueInput.to_i % 27 == indexDown + 1 
    downFunc 
  else 
    print "downError!"
  end
elsif mode == 3 
  if valueInput.to_i % 9 == 0
    mode = 1 
  elsif valueInput.to_i % 9 == indexSymbol + 1
    symbolFunc 
  else
    print "symbolError!"
  end 
else 
  print "modeError!"
end
