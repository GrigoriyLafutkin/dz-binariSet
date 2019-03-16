#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::string Conversion_from_decimal_to_binary(size_t p)
{
    std::string new_str;
    while (p > 0)
    {
        int m = p % 2;
        switch (m)
        {
        case 1:
            new_str += "1";
            break;
        case 0:
            new_str += "0";
            break;
        }
        p = p / 2;
    }
    return new_str;
}
std::vector<bool> Search_all_sets(const std::string p)
{
    std::vector<bool> arr;
    for (size_t i = 0; i < pow(2, p.size()); ++i)
    {
        std::string stt;
        if (i == 0)
        {
            for (size_t j = 0; j < p.size(); ++j)
            {
                arr.push_back(0);
            }
        } else {
            stt = Conversion_from_decimal_to_binary(i);
        }
        while (stt.size() != p.size())
        {
            stt += "0";
        }
        std::reverse(stt.begin(), stt.end());
        for (size_t l = 0; l < p.size(); ++l)
        {
            if (stt[l] == '1')
            {
                arr.push_back(1);
            }
            else
            {
                arr.push_back(0);
            }
        }
    }
    return arr;
}
std::vector<bool> Finding_the_right_sets(const int& p, const std::string str)
{
    std::vector<bool> new_sets;
    for (size_t i = 0; i < Search_all_sets(str).size(); i += str.size())
    {
        int count = 0;
        std::vector<bool> vec = Search_all_sets(str);
        for (size_t j = 0; j < str.size(); ++j)
        {
            if (str[j] == '1' && vec[i + j] == false
                || str[j] == '0' && vec[i + j] == true)
            {
                ++count;
            }
        }
        if (count == p)
        {
            for (size_t m = 0, k = i; m < str.size(); ++m, ++k)
            {
                new_sets.push_back(vec[k]);
            }
        }
    }
    return new_sets;
}
int main()
{
    std::string A;
    int R = 0;
    std::cout << "R = ";
    std::cin >> R;
    std::cout << "A = ";
    std::cin >> A;
    std::vector<bool> vec = Finding_the_right_sets(R, A);
    for (size_t i = 0; i < vec.size(); i += A.size())
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
