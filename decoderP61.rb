print "User, enter integers separated by a comma and a space (eg, \"12, 31, 527\"), \nthen press Enter: "
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



capsArray.each_with_index do |valueCaps, indexCaps|
  inputArray.map do |valueInput|
    if valueInput.to_i % 27 == indexCaps + 1 
	  print valueCaps + "\n"
	end 
  end 
end 