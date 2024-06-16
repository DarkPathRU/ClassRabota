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
	cout << "vvedite N strok: " << endl;
	cin >> N;

	map<string, double> products; // shablon s key and value

	string name;
	double price;

	for (auto i = 0; i < N; i++) {
		cin >> name;
		cin >> price;
		products[name] = price; // kajdomy klu4u zapisivau ego value
	}
	
	auto max_p = max_element(products.begin(), products.end(), [](const auto& a, const auto& b) { // 4erez lambda function nahojy max value. dymau ly4she 4em otdelnaya function
		return a.second < b.second; //vernul result
		});
	auto min_p = max_element(products.begin(), products.end(), [](const auto& a, const auto& b) { //toje samoe tolko min
		return a.second > b.second; 
		});

	double avg = (max_p-> second + min_p-> second) / 2.0; // 4erez to4ky ne rabotaet po4emy to, nashel v google takoi variant. prosto delenie na 2.0 ot max i min. 
												//tak kak double poetomy 2.0

	cout << "Max product price: " << max_p->first << " : " << max_p->second << endl;
	cout << "Min product price: " << min_p->first << " : " << min_p->second << endl;
	cout << "Avg product price: " << avg << endl;


	vector<pair<string, double>> topProduct(products.begin(), products.end()); //sozdal vector par i zasunul tyda vse svoi key value kotorii zapisal do etogo

	sort(topProduct.begin(), topProduct.end(), [](const pair<string, double>&a, const pair<string, double>&b) { //zatem otsortiroval vse pari key value po vozrastaniu
		return a.second > b.second;
	});

	cout << "top 3 products: " << endl;
	for (auto i = 0; i < 3; i++) { // po zadaniu 3
		cout << topProduct[i].first << ":" << topProduct[i].second << endl; // vivel top3 produkta posle sortirovki
	}

	return 0;
}



