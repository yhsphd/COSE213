#pragma warning(disable:4996)
#include <stdio.h>

int factorial(int);

int main() {
	int number, result;

	printf("정수값 입력 : ");
	scanf("%d", &number);

	result = factorial(number);  // 함수 호출

	printf("result = %d", result);

	return 0;
}

int factorial(int n) {  // 함수 factorial
	if (n == 1)
		return 1;
	else
		return (n * factorial(n - 1));  // 순환 호출
}