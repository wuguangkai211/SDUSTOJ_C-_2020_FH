#include <bits/stdc++.h>
using namespace std;
 
class Base
{
protected:
    int x$;
public:
    Base(int x):x$(x){cout << "Base = " << x$ << " is created." << endl;}
    Base(const Base& tt):x$(tt.x$){cout << "Base = " << x$ << " is copied." << endl;}
    ~Base(){cout << "Base = " << x$ << " is erased." << endl;}
 
 
};
 
class Derived: public Base
{
protected:
    int a$;
public:
    Derived(int x, int a):Base(x), a$(a){cout << "Derived = " << a$ << " is created." << endl;}
    Derived(const Derived& tt):Base(tt), a$(tt.a$){cout << "Derived = " << a$ << " is copied." << endl;}
    ~Derived(){cout << "Derived = " << a$ << " is erased." << endl;}
 
 
};
 
int main()
{
    int cases, data1, data2;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>data1>>data2;
        Base base1(data1), base2(base1);
 
        Derived derived1(data1, data2), derived2(derived1);
    }
}


/* 
Problem D: 还会用继承吗？
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4158  Solved: 3078
[Submit][Status]
Description
定义一个Base类，包括1个int类型的属性，以及满足输出格式要求的构造函数、拷贝构造函数和析构函数。

定义Base类的子类Derived，包括1个int类型的属性， 以及满足输出格式要求的构造函数、拷贝构造函数和析构函数。

Input
第1行N>0表示测试用例个数。

每个测试包括2个int类型的整数。

Output
见样例。

Sample Input
1
10 20
Sample Output
Base = 10 is created.
Base = 10 is copied.
Base = 10 is created.
Derived = 20 is created.
Base = 10 is copied.
Derived = 20 is copied.
Derived = 20 is erased.
Base = 10 is erased.
Derived = 20 is erased.
Base = 10 is erased.
Base = 10 is erased.
Base = 10 is erased.
HINT
Append Code
append.cc, */