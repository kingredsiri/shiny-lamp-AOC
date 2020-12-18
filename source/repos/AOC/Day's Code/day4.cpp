#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int day4HelperPart1(string* values, string& password);
int day4HelperPart2(string* values, string& password);

void day4() {
	string filename = "Input Files/day4.txt";
    ifstream input;
    input.open(filename);
    string temp;
    string values[] = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
    int part1Correct = 0, part2Correct = 0;
    string password = "";
    while(getline(input, temp)) {
        if(!temp.empty()) {
            if(password == "") {
                password += temp;
            }
            else {
                password += " " + temp;
            }
        }
        else {
            part1Correct += day4HelperPart1(values, password);
            part2Correct += day4HelperPart2(values, password);
        }
        if(input.peek() == EOF) {
            part1Correct += day4HelperPart1(values, password);
            part2Correct += day4HelperPart2(values, password);
        }
    }
    printf("Day 4 Solution\n");
    printf("Part 1 Solution: %d\n", part1Correct);
    printf("Part 2 Solution: %d\n", part2Correct-1);
}

int day4HelperPart1(string* values, string& password) {
    int counter = 0;
    for(int i = 0; i < 7; i++) {
        if(password.find(values[i]) != string::npos) {
            counter++;
        }
    }
    if(counter == 7) {
        return 1;
    }
    return 0;
}

int day4HelperPart2(string* values, string& password) {
    int counter = 0;
    for(int i = 0; i < 7; i++) {
        if(password.find(values[i]) != string::npos) {
            smatch sm;
            if(values[i] == "byr") {
                regex byr ("byr:(19[2-9][0-9]|200[0-2])");
                regex_search(password, sm, byr);
            }
            else if(values[i] == "iyr") {
                regex iyr ("iyr:(201[0-9]|2020)");
                regex_search(password, sm, iyr);
            }
            else if(values[i] == "eyr") {
                regex eyr ("eyr:(202[0-9]|2030)");
                regex_search(password, sm, eyr);
            }
            else if(values[i] == "hgt") {
                regex hgt ("hgt:(1[5-8][0-9]cm|19[0-3]cm|59in|6[0-9]in|7[0-6]in)");
                regex_search(password, sm, hgt);
            }
            else if(values[i] == "hcl") {
                regex hcl ("hcl:#([0-9]|[a-f]){6}");
                regex_search(password, sm, hcl);
            }
            else if(values[i] == "ecl") {
                regex ecl ("ecl:(amb|blu|brn|gry|grn|hzl|oth)");
                regex_search(password, sm, ecl);
            }
            else if(values[i] == "pid") {
                regex pid("pid:[0-9]{9}");
                regex_search(password, sm, pid);
            }
            if(sm.size() > 0) {
                counter++;
            }
        }
    }
    string temp = password;
    password = "";
    if(counter == 7) {
        return 1;
    }
    return 0;
}