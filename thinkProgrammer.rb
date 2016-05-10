i = 1
while i < 4
  i.times {print "#"}
  print "\n"
  i += 1
end

x = 4
while x > 0
  y = 0
  while y < x
    print "#"
	y += 1
  end
  x -= 1
  print "\n"
end

n = 1
while n < 5
  print "#" * n
  print "\n"
  n += 1
end 

y = 3
while y > 0
  y.times {print "#"}
    print "\n"
	y -= 1
end 

triangleArray = [1, 2, 3, 4, 3, 2, 1]

for value in triangleArray 
  print "#" * value
  print "\n"
end

=begin
I don't know how to represent this in a program, but the mathematical equation for this sideways triangle, if represented on an x- / y-axis graph would be the following: y = -|x-4| + 4 
=end