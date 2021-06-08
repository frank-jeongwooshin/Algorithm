/*
���� ��ȯ �Լ� �����
2����
8����
16����
*/

#include <iostream>
#include <string>

using namespace std;

string to2(int n) {
	string res;
	res = "0b";

	string tmp;
	while (n / 2 != 0 || n % 2 != 0) {
		tmp += to_string(n % 2);
		n /= 2;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		res += tmp[i];
	}
	
	return res;
}

string to8(int n) {
	string res;
	res = "0 ";

	string tmp;
	while (n / 8 != 0 || n % 8 != 0) {
		tmp += to_string(n % 8);
		n /= 8;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		res += tmp[i];
	}

	return res;
}

string to16(int n) {
	string res;
	res = "0x";
	string code_hex = "0123456789ABCDEF";

	string tmp;
	while (n / 16 != 0 || n % 16 != 0) {
		tmp += code_hex[n % 16];
		n /= 16;
	}

	for (int i = tmp.size() - 1; i >= 0; i--) {
		res += tmp[i];
	}

	return res;
}

void transformation_2_8_16() {
	int N = 123;
	//cout << "��ȯ�� ��: ";
	//cin >> N;
	cout << "��ȯ�� ��: " << N << endl;

	string ans;
	ans = to2(N);
	cout << "10���� -> 2 ���� : " << ans << endl;

	ans = to8(N);
	cout << "10���� -> 8 ���� : " << ans << endl;

	ans = to16(N);
	cout << "10���� -> 16���� : " << ans << endl;
}