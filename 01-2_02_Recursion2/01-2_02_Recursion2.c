/* This program determines the greatest common divisor
of two numbers.
Written by:
Date:
*/
#include <ctype.h>
#include <stdio.h>

// Prototype Statements
int gcd(int a, int b);

int main(void) {
	// Local Declarations
	int gcdResult;

	// Statements
	printf("Test GCD Algorithm\n");
	gcdResult = gcd(10, 25);
	printf("GCD of 10 & 25 is %d", gcdResult);
	printf("\nEnd of Test\n");
	return 0;
}  // main

/* ================= gcd =================
Calculates greatest common divisor using the
Euclidean algorithm.
Pre a and b are positive integers greater than 0
Post greatest common divisor returned
*/
int gcd(int a, int b) {
	// Statements
	if (b == 0) return a;
	if (a == 0) return b;
	return gcd(b, a % b);
}  // gcd