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


//
//
//															//dz1
//set<string>getSet(string& str) {
//	set<string> nums;
//	stringstream newNums(str);
//	while (getline(newNums, str, ' '));
//	if (str.size() > 0) {
//		nums.insert(str);
//	}
//	return nums;
//}
//
//
//	
//int main()
//{
//	int n = 1;
//	string test1;
//	cout << "vvedite stroky 4isel: " << endl;
//	getline(cin, test1); 
//	set<char> setNum(test1.begin(), test1.end());
//		if (test1.size() > setNum.size()) {
//			cout << "v stroke est odnikaovie 4isla" << endl;
//		}
//		else {
//			cout << "v stoke net odinakovih 4isel" << endl;
//		}
//	return 0;
//
//}





																//dz2


//int main() {
//	string test1;
//	string test2;
//	cout << "vvedite 2 test stroki 4isel: " << endl;
//	cin >> test1;
//	cin >> test2;
//
//
//	set<char> Num1(test1.begin(), test1.end());
//	set<char> Num2(test2.begin(), test2.end());
//	set<char> result;
//	set_union(Num1.begin(), Num1.end(), Num2.begin(), Num2.end(), inserter(result, result.begin()));
//	if (result.size() != 10) {
//		cout << "nevernii" << endl;
//	}
//	else{
//		cout << "vernii" << endl;
//	}
//	return 0;
//
//}






														//dz3



s/*et<string>getSet(string& str) {
	set<string> nums;
	stringstream newNums(str);
	string temp;
	while (newNums >> temp) {
		nums.insert(temp);
	}
	return nums;
}
int main() {

	string test1;
	string test2;
	cout << "vvedite 2 test stroki: " << endl;
	getline(cin, test1);
	getline(cin, test2);
	set<string> v1 = getSet(test1);
	set<string> v2 = getSet(test2);
	set<string> result;

	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(result, result.begin()));

	for (const auto& e : result) {
		cout << e << '\t';
	}
	return 0;
}*/
