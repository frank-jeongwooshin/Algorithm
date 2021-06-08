/*
실수를 입력받고 정렬
입력 : -1,10,3,5.0,12.34,0.9,-5.0,-11
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void real_number_sort() {
	string input = "-1,10,3,5.0,12.34,0.9,-5.0,-11,0.0", tmp;
	//getline(cin, input);

	vector<pair<float, int>> minus_nums, plus_nums;
	vector<string> ans;
	int i = 0;
	for(char c : input){
		if (c == ',') {
			if (tmp[0] == '-') {
				minus_nums.push_back({ stof(tmp), i });
			}
			else {
				plus_nums.push_back({ stof(tmp), i });
			}
			ans.push_back(tmp);
			
			tmp = "";
			i++;
		}
		else {
			tmp.push_back(c);
		}
	}
	if (tmp[0] == '-') {
		minus_nums.push_back({ stof(tmp), i });
	}
	else {
		plus_nums.push_back({ stof(tmp), i });
	}
	ans.push_back(tmp);
	
	sort(minus_nums.begin(), minus_nums.end());
	sort(plus_nums.begin(), plus_nums.end());
	
	for (int i = minus_nums.size() - 1; i >= 0; i--) {
		cout << ans[minus_nums[i].second] << ' ';
	}
	for (auto k : plus_nums) {
		cout << ans[k.second] << ' ';
	}
	cout << endl;
}