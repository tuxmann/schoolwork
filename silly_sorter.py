### IOT Course 4 Week 3 ###

while True:
	numbers = [1,2,3]
	i = 0
	while i < 3:
		numbers[i] = input("Enter a number: ")
		print ("")
		i += 1
	numbers.sort(key=int)
	print (', '.join(map(str, numbers)))
	print ("")
	again = input("Would you like to play again? Type Y or N. ")
	if again == 'n' or again == 'N':
		break
	else:
		print ("")
		

