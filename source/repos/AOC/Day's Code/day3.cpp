#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

void day3() {
	string filename = "Input Files/day3.txt";
	int slope = 3;
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
	int replica = ceil((lengthOfFile / (lengthOfString / slope)));
	string* arr = new string[lengthOfFile];
	for (int i = 0; i < lengthOfFile; i++) {
		getline(input, temp);
		arr[i] = temp;
	}
	input.close();

	string final = arr[lengthOfFile - 1];
	int t = 0, placement = 0;
	int trees = 0;
	while (arr[t] != final) {
		if ((placement + slope) > arr[t].length()) {
			placement = 0;
		}
		if (arr[t + 1].at(placement + slope) == '#') {
			trees++;
		}
		t++;
		placement += slope;
	}
	printf("Trees: %d\n", trees);
	delete[] arr;
}