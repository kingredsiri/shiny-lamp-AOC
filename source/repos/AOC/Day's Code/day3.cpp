#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int day3Helper(std::string*, int, int, std::string, int);

void day3() {
	string filename = "Input Files/day3.txt";
	int x = 3, y = 1;
	int lengthOfFile = 0, lengthOfString = 0;
	ifstream input;
	input.open(filename);
	string temp;
	while (getline(input, temp)) {
		lengthOfFile++;
		lengthOfString = temp.length();
	}
	input.close();
	input.open(filename);
	string* arr = new string[lengthOfFile];
	for (int i = 0; i < lengthOfFile; i++) {
		getline(input, temp);
		arr[i] = temp;
	}
	input.close();

	string final = arr[lengthOfFile - 1];
	int trees = day3Helper(arr, x, y, final, lengthOfFile);
	int slopes_X[5] = {1, 3, 5, 7, 1};
	int slopes_Y[5] = {1, 1, 1, 1, 2};
	long long int mul = 1;
	for(int i = 0; i < 5; i++) {
		int temp = day3Helper(arr, slopes_X[i], slopes_Y[i], final, lengthOfFile-1); 
		mul *= temp;
	}
	printf("Day 3 Solution\n");
	printf("Part 1 Solution: %d\n", trees);
	cout << "Part 2 Solution: " << mul << endl;
	delete[] arr;
}

int day3Helper(string* arr, int x, int y, string compare, int length) { 
	int t = 0, placement = 0, trees = 0;
	while (arr[t] != compare) {
		if ((placement + x) >= arr[t].length()) {
			placement = ((placement) - arr[t].length());
		}
		if((t+y) <= length) {
			if (arr[t + y].at(placement + x) == '#') {
				trees++;
			}
		}
		t += y;
		placement += x;
	}
	return trees;
}