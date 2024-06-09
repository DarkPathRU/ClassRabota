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

	int orders;
	cout << "koli4estvo zakazov: " << endl;
	cin >> orders;

	const int limit = 1000; // po zadaniu
	const int radius = 16; // po zadaniu

	for (auto i = 0; i < orders; i++) {
		int L; //dlina
		int W; //shirina
		int H; //visota
		cout << "vvedite L, W, H " << endl << i + 1 << ": " << endl;; // nomer/o4ered zakaza 
		cin >> L;
		cin >> W;
		cin >> H;
		if (L >= limit || W >= limit || H >= limit) {
			cout << "ne doljno previshat 1000 po zadaniu " << endl;
			/*break;*/
			continue;

			// tyt ne ponyal 4to pravilnee bydet.. tipa esli est drygie zakazi to prosto k nim perehodit
		}

		int wall = 2 * H * (L + W);

		int banka = wall / radius; // krashy 
		if (wall % radius != 0) { //smotru esli ostalos kraska eshe v banke 
			banka += 1; 
		}

		cout << "koli4estvo banok: " << banka << endl;
	}
	return 0;
}
