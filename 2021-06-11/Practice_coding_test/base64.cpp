/*
base 64 Encoder/Decoder
input : Hello 
output : SGVsbG8=
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 문자열 -> ASCII -> 이진수
string to2(string n) {
	string res;
	for (int i = 0; i < n.size(); i++) {
		string tmp;
		int word = n[i];

		while (word / 2 != 0 || word % 2 != 0){
			tmp += to_string(word % 2);
			word /= 2;
		}

		while (tmp.size() != 8) {
			tmp += "0";
		}

		for (int i = tmp.size()-1; i >= 0; i--) {
			res += tmp[i];
		}

	}
	return res;
}

// 십진수 -> 이진수
string to2(int n) {
	string res;
	string tmp;
	
	while (n / 2 != 0 || n % 2 != 0) {
		tmp += to_string(n % 2);
		n /= 2;
	}

	while (tmp.size() + res.size() != 6) {
		res += "0";
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		res += tmp[i];
	}
	return res;
}

// 이진수 -> 십진수
int to10(string s) {
	int res = 0;

	for (int i = 0; i < s.size(); i++) {
		int a = s[s.size() - (i + 1)]-48;
		res += pow(2, i) * a;
	}

	return res;
}

string encoder(string s) {
	char base64_ascii[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string res, bi, tmp;
	vector<string> six_bits;

	bi = to2(s);
	int flag = 0;
	for (int i = 0; i < bi.size(); i++) {
		if (flag == 6) {
			six_bits.push_back(tmp);
			tmp = "";
			flag = 0;
		}
		tmp += bi[i];
		flag++;
	}
	
	if (tmp != "") {
		while (tmp.size() != 6) {
			tmp += "0";
		}

		six_bits.push_back(tmp);
	}
	
	while (six_bits.size() % 4 != 0) {
		six_bits.push_back("=");
	}

	int toB;
	for (int i = 0; i < six_bits.size(); i++) {
		if (six_bits[i].size() != 6) {
			res += six_bits[i];
			continue;
		}

		toB = to10(six_bits[i]);
		res += base64_ascii[toB];
	}
	
	return res;
}

string decoder(string s) {
	string base64_ascii = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	string res, bi, tmp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '=') continue;

		bi += (to2(base64_ascii.find(s[i])));
	}

	vector<int> nums;
	int flag = 0;
	for (int i = 0; i < bi.size(); i++) {
		if (flag == 8) {
			nums.push_back(to10(tmp));
			tmp = "";
			flag = 0;
		}
		tmp += bi[i];
		flag++;
	}

	for (int i = 0; i < nums.size(); i++) {
		res += char(nums[i]);
	}

	return res;
}

int main() {
	string mode;
	while (true) {
		cout << "> Input mode (E: Encode, D: Decode, Q:quit)" << endl;
		getline(cin, mode);
		if (mode == "E" || mode == "D" || mode == "Q") {
			 break;
		}
		else {
			cout << "again" << endl;
		}

	}
	string input, res;
	
	if (mode == "E") {
		getline(cin, input);
		res = encoder(input);
		cout << res << endl;
	}
	else if (mode == "D") {
		getline(cin, input);
		res = decoder(input);
		cout << res << endl;
	}
	else {
		cout << "The Program has ended" << endl;
	}
}