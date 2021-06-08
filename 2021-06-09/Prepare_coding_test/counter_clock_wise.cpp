#include <iostream>
#include <stdio.h>

using namespace std;

void counter_clock_wise() {
	int N = 10;
	//cin >> N;

	int m[10][10] = { 0, };

	int x = 0, y = 0, d = 1;
	int i, j, num = 1;

	for (i = 0; i < N; i++) {
		m[x][y] = num;
		num++;
		x += 1;
	}
	x -= 1;

	for (i = N-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			y += d;
			m[x][y] = num;
			num++;
		}
		d *= -1;

		for (j = 0; j < i; j++) {
			x += d;
			m[x][y] = num;
			num++;
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%4d", m[i][j]);
		}
		cout << endl;
	}
}