=begin
x = 5
while x > 0 
  5.times {print "#"}
  x -= 1
  print "\n"
end

y = 0
while y < 5
  print "#"
  y += 1
end
print "\n"
=end

=begin
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
=end

=begin
x = 0
while x < 40
  (x+1).times {print "#"; x += 1}
  print "\n"
end
=end

i = 1
while i < 4
  i.times {print "#"}
  print "\n"
  i += 1
end

i = 1 
j = 1 
while i < 4 
  while j < 4 
    print "#"
	j += 1 
  end
  print "\n l"
  i += 1 
end

=begin
i = 4  
j = 1 
while i > 0 
  while j < i
    print "#"
	print "\n"
	j += 1 
  end
  i -= 1
end
=end

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
