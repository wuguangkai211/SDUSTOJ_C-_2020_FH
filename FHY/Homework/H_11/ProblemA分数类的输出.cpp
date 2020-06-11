#include <bits/stdc++.h>
using namespace std;

class Fract
{
protected:
    int n$, m$;
public:
    Fract(int n, int m) : n$(n), m$(m)
    {
        if(m$ < 0){ m$ *= -1, n$ *= -1;}
        int gcd, num1 = abs(n$), num2 = abs(m$);
        gcd = __gcd(num1, num2);
        n$ /= gcd, m$ /= gcd;
    }
    operator double(){ return (double)n$ / m$;}
    void show() const
    {
        if (n$ == 0 || m$ == 1)  cout << n$ << endl;
        else cout << n$ << '/' << m$ << endl;
    }
};

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        Fract fr(n, m);
        fr.show();
    }
}/* 





Problem A: 分数类的输出
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 6652  Solved: 3077
[Submit][Status]
Description
封装一个分数类Fract，用来处理分数功能和运算，支持以下操作：
1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。
2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。
-----------------------------------------------------------------------------
你设计一个Fract类，使得main()函数能够运行并得到正确的输出。调用格式见append.cc
Input
输入多行，每行两个整数，分别为分子和分母，至EOF结束。输入的分母不会为0；
Output
每行输出一个分数，与输入顺序一致。
分数输出时为最简形式，负号只会出现在最前面，若分母为1或分子为0，则只输出一个整数，即分子部分，而没有“/”和分母部分。
Sample Input
1 3
20 -15
80 150
-9 1
6 6
12 16
-33 -48
6 11
0 -10
Sample Output
1/3
-4/3
8/15
-9
1
3/4
11/16
6/11
0
HINT
Append Code
append.c, append.cc,
 */