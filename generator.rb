numbers = Array.new(ARGV[0].to_i) { |i|
	i.to_s
}

str = String.new
numbers.shuffle!.each { |n|
	str += n + " "
}

puts str.chomp(" ")
