/*
삼각형부터 십각형의 넓이
입력: 점의 갯수 / (x,y)좌표
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void polygon() {
	int N = 4;

	vector<pair <int, int>> nums;
	/*
	* 입력받기
	for(int i = 0; i < N; i++){
		int x, y;
		string input;
		cin >> input;

		x = input[0];
		y = input[2];

		nums.push_back({x, y});
	*/

	nums.push_back({ 1,1 });
	nums.push_back({ 2,1 });
	nums.push_back({ 2,2 });
	nums.push_back({ 1,2 });
	
	float res = 0;
	int a=0, b=0;
	for (int i = 0; i < N; i++) {
		if ((i + 1) == N) {
			a += (nums[i].first * nums[0].second);
			b += (nums[i].second * nums[0].first);
		}
		else {
			a += (nums[i].first * nums[i + 1].second);
			b += (nums[i].second * nums[i + 1].first);
		}
	}
	res = a - b;
	if (res < 0) res *= -1;
	res /= 2;
	res = floor(res + 0.5);

	cout << res << endl;
}