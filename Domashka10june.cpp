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

int main() {
	int N;
	cout << "vvedite koli4estvo elementov dlya vvoda v vektor: " << endl;
	cin >> N;
	while(N <= 2 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "nado >2" << endl;
		cin >> N;
	}
	vector<int> v1; 

	cout << "elementi vectora:" << endl;
	for (auto i = 0; i < N; i++) {
		int elem;
		cin >> elem;
		v1.push_back(elem);
	}

	auto min_i = min_element(v1.begin(), v1.end());
	auto max_i = max_element(v1.begin(), v1.end());

	if (min_i > max_i) {
		swap(min_i, max_i);
	}


	if (min_i != max_i) { 
		reverse(++min_i, --max_i);
	}

	for (auto const& e : v1) {
		cout << e << endl;
	}

	return 0;
}