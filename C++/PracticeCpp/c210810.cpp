#include "c210810.h"

void c210810::num_2908()
{
	std::string A;
	std::string B;

	std::cin >> A >> B;
	char tmp = A[0];
	A[0] = A[2];
	A[2] = tmp;

	tmp = B[0];
	B[0] = B[2];
	B[2] = tmp;

	if (std::stoi(A) > std::stoi(B)) {
		std::cout << A << std::endl;
	}
	else {
		std::cout << B << std::endl;
	}
}

void c210810::dial_5622()
{
	std::string S;

	std::cin >> S;
	int cnt = S.size();

	int result = 0;
	for (int i = 0; i < cnt; ++i) {
		int tmp = int(S[i]) - 'A';
		if (tmp < 15) {
			result += (tmp / 3) + 3;
		}
		else if (tmp < 19) {
			result += 8;
		}
		else if (tmp < 22) {
			result += 9;
		}
		else {
			result += 10;
		}
	}

	std::cout << result << std::endl;
}
