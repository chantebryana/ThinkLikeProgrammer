print "User, enter positive integers separated by a comma and a space \n"
  + "(eg, \"12, 31, 527\"), then press Enter: "
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

if mode == 1 
  if integer % 27 == 0
    mode = 2
  elsif integer % 27 < 0
    capsFunc 
  else 
    print "capsError!"
  end 
elsif mode == 2  
  if integer % 27 == 0
    mode = 3  
  elsif integer % 27 < 0
    downFunc 
  else 
    print "downError!"
  end
elsif mode == 3 
  if integer % 9 == 0
    mode = 1 
  elsif integer % 9 < 0
    symbolFunc 
  else
    print "symbolError!"
  end 
else 
  print "modeError!"
end

capsArray.each_with_index do |valueCaps, indexCaps|
  inputArray.map do |valueInput|
    if valueInput.to_i % 27 == indexCaps + 1 
	  print valueCaps + "\n"
	end 
  end 
end 