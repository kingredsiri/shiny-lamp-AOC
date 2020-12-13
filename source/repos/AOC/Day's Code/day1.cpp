#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

void day1() 
{
	ifstream input;
	input.open("day1.txt");
	int temp;
	int size = 0;
	while (input >> temp) {
		size++;
	}
	int* arr = new int[size];
	input.close();
	input.open("day1.txt");
	for (int i = 0; i < size; i++) {
		input >> arr[i];
	}

	int sum = 2020;
	int twoSum = 0, threeSum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if ((arr[i] + arr[j]) == sum) {
				twoSum = (arr[i] * arr[j]);
				break;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				if ((arr[i] + arr[j] + arr[k]) == sum) {
					threeSum = (arr[i] * arr[j] * arr[k]);
					break;
				}
			}
		}
	}
	printf("Day 1 Solution\n");
	printf("Part 1 Solution: %d\n", twoSum);
	printf("Part 2 Solution: %d\n", threeSum);
	delete arr;
	return;
}