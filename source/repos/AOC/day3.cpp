#include <fstream>
#include <string>
#include <stdio.h>

void day3() {
	int slope = 3;
	int lengthOfFile = 0;
	ifstream input;
	input.open("day3.txt");
	string temp;
	while (getline(input, temp)) {
		lengthOfFile++;
	}
	printf("%d\n", lengthOfFile);
}