// Jason Mann
//
//                   Fibonacci sequence
// Fibonacci sequence is characterized by the fact that every
// number after the first two is the sum of the two preceding
// ones.

#include <stdio.h>

int main()
{
	int fib_one = 0;    // first number in the sequence.
	int fib_two = 1;    // second number in the sequence.
	int new_fib_two = 0;    // placeholder for next number in the sequence.

    printf("The first six digits in the Fibonacci sequence are: ");
	printf("%d, ", fib_one);  // print first number in the sequence.
	printf("%d, ", fib_two);  // print second number in the sequence.

	for (int i = 0; i < 4; i++) {   // Compute the next four numbers
		new_fib_two = fib_one + fib_two;    // sum of the two preceding numbers.
		printf("%d, ", new_fib_two);    // print the next number in the sequence.
		fib_one = fib_two;          // Shift the numbers out.
		fib_two = new_fib_two;      // Shift the numbers out.
		}

	return 0;   // End proggram.
}
