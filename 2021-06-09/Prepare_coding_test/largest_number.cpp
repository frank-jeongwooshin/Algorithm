/*
큰 수 만들기
입력: 84, 878, 18, 898, 9
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	string tmp_a, tmp_b;
	if (a.size() == 1) {
		tmp_a = a + a + a;
	}
	else if (a.size() == 2) {
		tmp_a = a + a[1];
	}
	else {
		tmp_a = a;
	}

	if(b.size() == 1) {
		tmp_b = b + b + b;
	}
	else if (b.size() == 2) {
		tmp_b = b + b[1];
	}
	else {
		tmp_b = b;
	}

	if (a.size() == b.size()) {
		return a > b;
	}
	else if (tmp_a == tmp_b) {
		return a.size() > b.size();
	}else{
		return tmp_a > tmp_b;
	}
}
void largest_number() {
	vector<string> nums;

	//52, 515, 5, 15, 155
	string input = "52, 515, 53, 15, 155, 565, 156, 5, 56", tmp;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ',') continue;
		if (input[i] == ' ') {
			nums.push_back(tmp);
			tmp = "";
			continue;
		}

		tmp += input[i];
	}
	nums.push_back(tmp);
	sort(nums.begin(), nums.end(), compare);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	cout << endl;
}