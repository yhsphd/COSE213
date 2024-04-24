#include <stdio.h>

int BinarySearch(int values[], int left, int right, int key);

int main(void) {
	int numbers[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

	printf("%d\n", BinarySearch(numbers, 0, sizeof(numbers) / sizeof(int) - 1, 50));
	printf("%d\n", BinarySearch(numbers, 0, sizeof(numbers) / sizeof(int) - 1, 45));

	return 0;
}

int BinarySearch(int values[], int left, int right, int key) {
	int ret = -1;
	int middle = 0;

	if (left <= right) {
		middle = (left + right) / 2;

		if (key < values[middle])
			ret = BinarySearch(values, left, middle - 1, key);
		else if (key == values[middle])
			ret = middle;
		else
			ret = BinarySearch(values, middle + 1, right, key);
	}
	return ret;
}