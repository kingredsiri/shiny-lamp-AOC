#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void day2()
{
    string filename = "Input Files/day2.txt";
    ifstream input;
    int count = 0, size = 0;
    string temp;
    int part1Correct = 0, part2Correct = 0;
    input.open(filename);
    string numsExpected = "", letterExpected = "";
    while (input >> temp) {
        count++;
        if (count == 1) {
            numsExpected = temp;
        }
        else if (count == 2) {
            letterExpected = temp;
        }
        else if (count == 3) {
            int counter = 0;
            for (int i = 0; i < temp.length(); i++) {
                if (temp.at(i) == letterExpected.at(0)) {
                    counter++;
                }
            }
            int dashIndex = numsExpected.find("-");
            int greaterThan = stoi(numsExpected.substr(0, dashIndex).c_str());
            int lesserThan = stoi(numsExpected.substr(dashIndex + 1).c_str());
            if (counter >= greaterThan && counter <= lesserThan) {
                part1Correct++;
            }
            if (greaterThan - 1 < temp.length() && lesserThan - 1 < temp.length()) {
                if ((temp.at(greaterThan - 1) == letterExpected.at(0) && temp.at(lesserThan - 1) != letterExpected.at(0)) || (temp.at(greaterThan - 1) != letterExpected.at(0) && temp.at(lesserThan - 1) == letterExpected.at(0))) {
                    part2Correct++;
                }
            }
            else if (greaterThan - 1 < temp.length() && lesserThan - 1 > temp.length()) {
                if (temp.at(greaterThan - 1) == letterExpected.at(0)) {
                    part2Correct++;
                }
            }
            count = 0;
        }
        size++;
    }
    printf("Day 2 Solution\n");
    printf("Part 1 Solution: %d\n", part1Correct);
    printf("Part 2 Solution: %d\n", part2Correct);
    input.close();
    return;
}
