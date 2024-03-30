#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void slice(const char* str, char* result, int start, int end) {
	for (int i = start; i < end; i++) {
		result[i] = str[i];
	}
}

void print_int_array(int *nums, int length) {
	/* Print items in nums */
	printf("[");
	for (int i = 0; i < length; i++) {
		if (i == length-1) {
			printf("%i", nums[i]);
			continue;
		}

		printf("%i,", nums[i]);
	}
	printf("]\n");
}

void bubblesort(int *nums, int length) {
	/* Sort the array using bubblesort */
	for (int i = 0; i < length; i++) {
		bool sorted = true;
		for (int j = 0; j < length; j++) {
			if (nums[j] > nums[j+1]) {
				sorted = false;
				int key = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = key;
			}

		}
		if (sorted == true) {
			break;
		}
	}
}

void read_csv_file(int* nums) {
	/* Read CSV file */
	FILE *fptr;

	fptr = fopen("../nums.csv", "r");

	char myString[100];

	int i = 0;
	while(fgets(myString, 100, fptr)) {
		char s_number[100] = "";
		slice(myString, s_number, 0, strlen(myString)-3);
		int number = atoi(s_number);
		nums[i] = number;
		i = i + 1;
	}
}

int main() {
	int nums[5000] = {};
	const int length = sizeof(nums)/sizeof(nums[0]);

	int total_time = 0;

	for (int i = 0; i < 10; i++) {

		read_csv_file(nums);

		clock_t start = clock();
		bubblesort(nums, length);
		clock_t end = clock();

		double time_sec = (double)(end - start) / CLOCKS_PER_SEC;
		double time_ms = time_sec * 1000;
		total_time += time_ms;
	}

	int avg_time = total_time / 10;

	print_int_array(nums, 100);
	printf("%i ms\n", avg_time);

	return 0;
}
