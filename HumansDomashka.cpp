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
#include<climits>
#include<unordered_set>
#include<sstream>
#include<map>

using namespace std;



int main() {

	int N;
	cout << "vvedite pari Huamns: " << endl;
	cin >> N;
	int limit;
	map<string, int> Humans;

	for (auto i = 0; i < N; i++) {
		string str;
		int height;
		cin.ignore();
		getline(cin, str);
		cin >> height;
		Humans[str] = height;
	}
	cout << "vvedite limit dlya propuska: " << endl;
	cin >> limit;

	for (auto& e : Humans) {
		if (e.second > limit) {
			cout << e.first << ":" << e.second << endl;
		}
	}
	return 0;
}