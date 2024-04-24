#pragma warning(disable:4996)
/* Test Towers of Hanoi
Written by:
Date:
*/
#include <stdio.h>

// Prototype Statements
void towers(int n, char source, char dest, char auxiliary);

int main(void) {
	// Local Declarations
	int numDisks;

	// Statements
	printf("Please enter number of disks: ");
	scanf("%d", &numDisks);
	printf("Start Towers of Hanoi.\n\n");
	towers(numDisks, 'A', 'C', 'B');
	printf(
		"\nI Hope you didn't select 64 "
		"and end the world!\n");
	return 0;
}  // main

/* ===================== towers =====================
Move one disk from source to destination through
the use of recursion.
Pre The tower consists of n disks
Source, destination, & auxiliary towers
Post Steps for moves printed
*/
void towers(int n, char source, char dest, char auxiliary) {
	// Local Declarations
	static int step = 0;

	// Statements
	printf("Towers (%d, %c, %c, %c)\n", n, source, dest, auxiliary);
	if (n == 1)
		printf("\t\t\tStep %3d: Move from %c to %c\n", ++step, source, dest);
	else {
		towers(n - 1, source, auxiliary, dest);
		printf("\t\t\tStep %3d: Move from %c to %c\n", ++step, source, dest);
		towers(n - 1, auxiliary, dest, source);
	}  // if ¡¦ else
	return;
}  // towers