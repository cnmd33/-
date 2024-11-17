/*
请编写一个 C++ 程序，将输入的数字各个位上的数字反转得到一个新数。这个数可以是小数、分数、百分数或整数。
- **整数**：将所有数位对调。
- **小数**：将整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分。
- **分数**：将分母的数反转，再将分子的数反转，不交换分子与分母。
- **百分数**：百分数的分子一定是整数，只改变数字部分。
## 注意  除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零。
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 去掉字符串前导零
string removeLeadingZeros(string str) 
{
    str.erase(0, str.find_first_not_of('0'));
    if (str.empty()) 
    {
        return "0";
    }
    return str;
}

// 反转字符串并去掉前导零
string reverseAndRemoveLeadingZeros(string str) 
{
    reverse(str.begin(), str.end());
    return removeLeadingZeros(str);
}

int main() 
{
    string num;
    cin >> num;

    if (num.find('%') != string::npos) 
    {       // 百分数
        num.pop_back(); // 去掉百分号
        num = reverseAndRemoveLeadingZeros(num) + '%';
    } 
    else if (num.find('/') != string::npos) 
    {       // 分数
        size_t pos = num.find('/');
        string numerator = num.substr(0, pos);
        string denominator = num.substr(pos + 1);
        numerator = reverseAndRemoveLeadingZeros(numerator);
        denominator = reverseAndRemoveLeadingZeros(denominator);
        num = numerator + '/' + denominator;
    } 
    else if (num.find('.') != string::npos) 
    {       // 小数
        size_t pos = num.find('.');
        string integerPart = num.substr(0, pos);
        string decimalPart = num.substr(pos + 1);
        integerPart = reverseAndRemoveLeadingZeros(integerPart);
        decimalPart = reverseAndRemoveLeadingZeros(decimalPart);
        num = integerPart + '.' + decimalPart;
    } 
    else 
    {       // 整数
        num = reverseAndRemoveLeadingZeros(num);
    }

    cout << num << endl;

    return 0;
}