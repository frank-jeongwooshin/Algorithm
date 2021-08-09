#include "c210809.h"

int c210809::SumofNums_11720()
{
	int N;
	std::string nums;

	std::cin >> N;
	std::cin >> nums;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		result += int(nums[i]) - '0';
	}

	std::cout << result << std::endl;
	return result;
}

void c210809::FindAlpha_10809()
{
	std::string S;
	std::cin >> S;
	
	int cnt = S.size();
	char temp = 'a';
	bool flag = false;

	for (int i = 0; i < ('z' - 'a' + 1); ++i) {
		for (int j = 0; j < cnt; ++j) {
			if (temp == S[j]) {
				std::cout << j << " ";
				flag = true;
				break;
			}
		}
		if (true == flag) {
			flag = false;
		}
		else {
			std::cout << "-1 ";
		}

		temp += 1;
	}

}

void c210809::RepeatString_2675()
{
	int T;
	std::cin >> T;
	std::string S;
	for (int i = 0; i < T; ++i) {
		int R;
		std::cin >> R;
		std::cin >> S;

		int cnt = S.size();
		for (int j = 0; j < cnt; ++j) {
			for (int k = 0; k < R; ++k) {
				std::cout << S[j];
			}
		}
		std::cout << std::endl;
	}
}
