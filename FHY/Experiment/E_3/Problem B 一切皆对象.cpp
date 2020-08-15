#include <bits/stdc++.h>
using namespace std;

class Thing
{
private:
    string ss$;
public:
    Thing(string tt):ss$(tt){cout << "A thing named by " << ss$ << " is created!" << endl;}
    Thing(){cout << "A thing without name is created!" << endl;}
    Thing(const Thing &tt):ss$(tt.ss$)
    {
        if(ss$.empty())
        {
            cout << "A thing without name is copied!" <<endl;
        }
        else
        {
             cout << "A thing named by " << ss$ << " is copied!" <<endl;
        }
    }
    ~Thing()
    {
        if(ss$.empty())
        {
            cout << "A thing without name is erased!" <<endl;
        }
        else
        {
             cout << "A thing named by " << ss$ << " is erased!" <<endl;
        }
    }
};






int main()
{
    string name;
    Thing Thing1, Thing2(Thing1);
    cin>>name;
    Thing Thing3(name);
    Thing Thing4(Thing3);
    return 0;
}
/* 
Problem B: 一切皆对象
Time Limit: 1 Sec  Memory Limit: 128 MB
Submit: 4758  Solved: 3229
[Submit][Status]
Description
一切都是对象 —— Everything is an object。 所以，现在定义一个类Thing，来描述世界上所有有名字的事物。该类只有构造函数、拷贝构造函数和析构函数，并具有一个字符串数据成员来存储其名字。

Input
输入只有1行，是一个没有空白符的字符串。

Output
见样例。

Sample Input
NAME
Sample Output
A thing without name is created!
A thing without name is copied!
A thing named by NAME is created!
A thing named by NAME is copied!
A thing named by NAME is erased!
A thing named by NAME is erased!
A thing without name is erased!
A thing without name is erased!
HINT
Append Code
append.cc, */