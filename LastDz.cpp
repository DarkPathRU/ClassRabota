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

    template<typename T>
    void print(const vector<T>&content, const string& value) {
        for (auto i = 0; i < content.size(); ++i) {
            cout << content[i];
            if (i != content.size() - 1) {
                cout << value;
            }
        }
       cout << endl;
    }

    int main() {
        vector<int> data = { 1, 2, 3 };
        print(data, ", "); // 1, 2, 3
        return 0;
    }