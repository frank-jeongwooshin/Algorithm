/*
36진수 사칙연산 프로그램
연산자: +, -
입력: "36진수""연산자""36진수"
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string to64(int n) {
	string res;
	string d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n < 0) {
		res = "-";
		n *= -1;
	}

	string tmp;
	while (n / 64 != 0 || n % 64 != 0) {
		tmp += d[n % 64];
		n /= 64;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		res += tmp[i];
	}

	return res;
}

int to10(string s) {
	int res = 0;

	for (int i = 0; i < s.size(); i++) {
		int a = s[s.size() - (i + 1)];
		if (a >= 65) a -= 55;
		res += pow(64, i) * a;
	}

	return res;
}

void calc() {
	string input = "Z-AZ";
	//cin >> input;

	string a, b, oper, tmp;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+' || input[i] == '-') {
			oper = input[i];
			a = tmp;
			tmp = "";
			continue;
		}

		tmp += input[i];
	}
	b = tmp;

	cout << a << ' ' << oper << ' ' << b << endl;
	int num_a = to10(a), num_b = to10(b), res;
	if (oper == "+") {
		res = num_a + num_b;
	}
	else {
		res = num_a - num_b;
	}

	tmp = to64(res);
	cout << tmp << endl;
}