#include "c210816.h"

//void c210815::croatiaAlpha_2941_1()
//{
//	std::string alphas;
//	std::cin >> alphas;
//
//	int res = 0;
//	int alphaSize = alphas.size();
//
//	for (int i = 0; i < alphaSize; ++i) 
//	{
//		std::cout << i << std::endl;
//		if ('c' == alphas[i])
//		{
//			std::cout << "in C" << std::endl;
//			++res;
//			++i;
//			if ('=' == alphas[i])
//			{
//				std::cout << "=" << std::endl;
//				continue;
//			}
//			else if ('-' != alphas[i])
//			{
//				std::cout << "-" << std::endl;
//				continue;
//			}
//			else
//			{
//				--i;
//			}
//		}
//		else if ('d' == alphas[i])
//		{
//			++res;
//			++i;
//			if ('z' == alphas[i])
//			{
//				++i;
//				if ('=' == alphas[i])
//				{
//					continue;
//				}
//				else
//				{
//					i -= 2;
//				}
//			}
//			else if ('-' == alphas[i])
//			{
//				continue;
//			}
//			else {
//				--i;
//			}
//		}
//		else if ('l' == alphas[i])
//		{
//			++res;
//			++i;
//			if ('j' == alphas[i])
//			{
//				continue;	
//			}
//			else
//			{
//				--i;
//			}
//		}
//		else if ('n' == alphas[i])
//		{
//			++res;
//			++i;
//			if ('j' == alphas[i])
//			{
//				continue;				
//			}
//			else
//			{
//				--i;
//			}
//		}
//		else if ('s' == alphas[i])
//		{
//			++res;
//			++i;
//			if ('=' == alphas[i])
//			{
//				continue;
//			}
//			else
//			{
//				--i;
//			}
//		}
//		else if ('z' == alphas[i])
//		{
//			++res;
//			++i;
//			if ('=' == alphas[i])
//			{
//				continue;
//			}
//			else
//			{
//				--i;
//			}
//		}
//		else
//		{
//			++res;
//		}
//	}
//
//	std::cout << res << std::endl;
//}

void c210816::croatiaAlpha_2941()
{
	int checkAlphaSize = 8;
	std::string checkAlpha[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	std::string input;
	std::cin >> input;
	int idx;
	for (int i = 0; i < 8; ++i) {
		idx = input.find(checkAlpha[i]);

		while (std::string::npos != idx) {
			input.replace(idx, checkAlpha[i].size(), "@");
			idx = input.find(checkAlpha[i]);
		}
	}

	std::cout << input.size();
}
