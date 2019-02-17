#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string A;
std::string binary(int& p, std::string& pp)
{
	while (p > 0)
	{
		int m = p % 2;
		switch (m)
		{
		case 1:
			pp += "1";
			break;
		case 0:
			pp += "0";
			break;
		}
		p = p / 2;
	}
	return pp;
}
std::vector<bool> MyBoolFunc(const std::string &p)
{
	std::vector<bool> arr;
	for (size_t i = 0; i < pow(2, p.size()); ++i)
	{
		std::string stt;
		int k = i;
		switch (k)
		{
		case 0:
			for (size_t j = 0; j < p.size(); ++j)
			{
				arr.push_back(0);
			}
			continue;
			break;
		default:
			binary(k, stt);
			break;
		}
		while (stt.size() != p.size())
		{
			stt += "0";
		}
		std::reverse(stt.begin(), stt.end());
		for (size_t l = 0; l < p.size(); ++l)
		{
			switch (stt[l])
			{
			case '1':
				arr.push_back(1);
				break;
			default:
				arr.push_back(0);
				break;
			}
		}
	}
	return arr;
}
std::vector<bool> SortBinariFunc(const int& p)
{
	std::vector<bool> arr;
	for (size_t i = 0; i < MyBoolFunc(A).size(); i += A.size())
	{
		int k = i;
		int count = 0;
		std::vector<bool> vec = MyBoolFunc(A);
		for (size_t j = 0; j < A.size(); ++j)
		{
			if (A[j] == '1' && vec[k] == false || A[j] == '0' && vec[k] == true)
			{
				++count;
			}
			++k;
		}
		k = i;
		if (count == p)
		{
			for (size_t m = 0; m < A.size(); ++m)
			{
				arr.push_back(vec[k]);
				++k;
			}
		}
	}
	return arr;
}
int main()
{
	int R = 0;
	std::cout << "R = ";
	std::cin >> R;
	std::cout << "A = ";
	std::cin >> A;
	std::vector<bool> vec = SortBinariFunc(R);
	for (size_t i = 0; i < vec.size() ; i += A.size())
	{
		int k = i;
		for (size_t j = 0; j < A.size(); ++j)
		{
			std::cout << vec[k];
			++k;
		}
		std::cout << std::endl;
	}
	system("pause");
}
