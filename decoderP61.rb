print "User, enter a integer, then press Enter: "
userInput = gets.to_i

symbolArray = ["!", "?", ",", ".", " ", ";", "\"", "\'"]
#symbolArray.each {|i| print i + "\n"}

capsArray = %w[A B C D E F G H I J K L M N O P Q R S T U V W X Y Z]
#capsArray.each {|i| print i + "\n"}

downArray = %w[a b c d e f g h i j k l m n o p q r s t u v w x y z]
#downArray.each {|i| print i + "\n"}

message = "Hello World!"
messageCode = [35, 27, 32, 39, 39, 42, 27, 14, 9, 50, 27, 42, 45, 39, 31, 27, 10]



capsArray.each_with_index do |value, index|
  if userInput % 27 == index + 1 
    print value + "\n"
  end 
end 