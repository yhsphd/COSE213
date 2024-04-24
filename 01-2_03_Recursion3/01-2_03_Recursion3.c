/* This program prints out a Fibonacci series.
Written by:
Date:
*/
#include <stdio.h>

// Prototype Statements
long fib(long num);

int main(void) {
	// Local Declarations
	int seriesSize = 10;

	// Statements
	printf("Print a Fibonacci series.\n");

	for (int looper = 0; looper < seriesSize; looper++) {
		if (looper % 5)
			printf(", %8ld", fib(looper));
		else
			printf("\n%8ld", fib(looper));
	}  // for
	printf("\n");
	return 0;
}  // main

/* ================= fib =================
Calculates the nth Fibonacci number
Pre num identifies Fibonacci number
Post returns nth Fibonacci number
*/
long fib(long num) {
	// Statements
	if (num == 0 || num == 1)
		// Base Case
		return num;
	return (fib(num - 1) + fib(num - 2));
}  // fib