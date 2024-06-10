#include <iostream>
#include <vector>
#include <optional>
#include <string>
#include <math.h>
#include <memory>
#include <tuple>
#include <forward_list>
#include <algorithm>
#include <string>
#include <numeric>
#include <regex>
#include <fstream>
#include<set>
#include<unordered_set>
#include<sstream>
#include<map>

using namespace std;



int func(string& str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower); //preobrazit vce v malenkie bykvi

	map<char, int> dict;
	for (auto& e : str) {
		dict.count(e) ? dict[e]++ : dict[e] = 1;
	}
	if (str.empty()) {
		return 1;
	}
	
	int counter = 0; //s4et4ik dlya povtronix symbols
	for (auto& e2 : dict) {

		if (e2.second > 1) { // esli value povtoryaetsa bolshe 4em odin raz
			counter++;
		}
	}
	return counter;
}



int main()
{
	string test = "abcde";
	string test1 = "aabbcde";
	string test2 = "aabBcde";
	string test3 = "indivisibility";
	cout << func(test3) << endl;
	return 0;
}
