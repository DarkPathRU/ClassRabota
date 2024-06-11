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

	map<string, int> dict1 = {
		{ "a", 100},
		{ "b", 200},
		{ "c", 300}
	};


	map<string, int> dict2 = {
		{ "a", 300},
		{ "b", 200},
		{ "d", 400}
	};

	map<string, int> result;

	for (auto& KeyValue1 : dict1) {
		result[KeyValue1.first] = KeyValue1.second;
	}
	//zatem
	for (auto& KeyValue2 : dict2) {
		result[KeyValue2.first] += KeyValue2.second; // vtoroi slovar probegaet po result(dict1) i esli est yje odinakovii klu4 v nashem sly4ae a i b 
													//togda prosto pribavlyaem tolko value iz 2 slovarya a uniklanii stroki zapisivaet kak polojeno key and value
	}

	for (const auto& e : result) { 
		cout << e.first << ":" << e.second << endl; // komy to nado alfavit poy4it :D y tebya v zadanii "d" posle "b"
	}
	return 0;

}