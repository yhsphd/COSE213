#pragma warning(disable:4996)
#include <stdio.h>

int factorial(int);

int main() {
	int number, result;

	printf("������ �Է� : ");
	scanf("%d", &number);

	result = factorial(number);  // �Լ� ȣ��

	printf("result = %d", result);

	return 0;
}

int factorial(int n) {  // �Լ� factorial
	if (n == 1)
		return 1;
	else
		return (n * factorial(n - 1));  // ��ȯ ȣ��
}