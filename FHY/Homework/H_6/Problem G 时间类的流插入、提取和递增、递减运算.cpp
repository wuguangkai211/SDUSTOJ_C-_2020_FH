#include <bits/stdc++.h>
using namespace std;

class Time
{
private:
    int hour$, min$, sec$;

public:
    //Constructor & Destructor :
    Time() : sec$(0), min$(0), hour$(0) {}
    Time(int hour, int minute, int second) : sec$(second), min$(minute), hour$(hour) {}
    Time(const Time &tt) : sec$(tt.sec$), min$(tt.min$), hour$(tt.hour$) {}
    ~Time() {}
    //Method in class Time :
    void showTime() const;
    Time &inputTime();
    friend ostream& operator<<(ostream &os, const Time &tt); //声明输出运算符重载，一般设为友元
    friend istream& operator>>(istream &is, Time &tt); //声明输入运算符重载，一般设为友元

    Time operator++(int) //后自增
    {
        Time tt(*this);
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            ssec = (ssec + 1) % 86400;
            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return tt;
    }
    Time& operator++() //前自增
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            ssec = (ssec + 1) % 86400;
            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return *this;
    }

    Time operator--(int)
    {
        Time tt(*this);
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            if (ssec >= 1)
            {
                ssec -= 1;
            }
            else
            {
                ssec = ssec + 86400 - 1;
            }

            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return tt;
    }
    Time& operator--()
    {
        if (((*this).hour$ < 24) && ((*this).hour$ >= 0) && ((*this).min$ < 60) && ((*this).min$ >= 0) && ((*this).sec$ < 60) && ((*this).sec$ >= 0))
        {
            int ssec = 0;
            ssec += (*this).hour$ * 3600;
            ssec += (*this).min$ * 60;
            ssec += (*this).sec$;
            if (ssec >= 1)
            {
                ssec -= 1;
            }
            else
            {
                ssec = ssec + 86400 - 1;
            }

            (*this).hour$ = (ssec / 3600) % 24;
            (*this).min$ = (ssec % 3600) / 60;
            (*this).sec$ = (ssec % 60);
        }
        return *this;
    }
};

ostream& operator<<(ostream &os, const Time &tt)
{
    if ((tt.hour$ < 24) && (tt.hour$ >= 0) && (tt.min$ < 60) && (tt.min$ >= 0) && (tt.sec$ < 60) && (tt.sec$ >= 0))
    {
        os << setw(2) << setfill('0') << tt.hour$ << ':' << setw(2) << setfill('0') << tt.min$ << ':' << setw(2) << setfill('0') << tt.sec$;
    }
    else
    {
        os << "error!!!";
    }
    return os;
}
istream& operator>>(istream &is, Time &tt)
{
    int hour, min, sec;
    is >> hour; is >> min; is >> sec;
    tt.hour$ = hour; tt.min$ = min; tt.sec$ = sec;
    return is;
}

inline Time &Time::inputTime()
{
    int hour, min, sec;
    cin >> hour;
    cin >> min;
    cin >> sec;
    hour$ = hour;
    min$ = min;
    sec$ = sec;
    return *this;
}
inline void Time::showTime() const
{
    if ((hour$ < 24) && (hour$ >= 0) && (min$ < 60) && (min$ >= 0) && (sec$ < 60) && (sec$ >= 0))
    {
        cout << setw(2) << setfill('0') << (*this).hour$ << ':' << setw(2) << setfill('0') << (*this).min$ << ':' << setw(2) << setfill('0') << (*this).sec$ << endl;
    }
    else
    {
        cout << "Time error" << endl;
    }
}

int main()
{
    Time t;
    int cases;
    cin >> cases;
    cout << setw(8) << left << "++t"
         << " ";
    cout << setw(8) << left << "--t"
         << " ";
    cout << setw(8) << left << "t"
         << " ";
    cout << setw(8) << left << "t--"
         << " ";
    cout << setw(8) << left << "t++"
         << " ";
    cout << setw(8) << left << "t" << right << endl;
    for (int i = 1; i <= cases; ++i)
    {
        cin >> t;
        cout << (++t) << " ";
        cout << (--t) << " ";
        cout << t << " ";
        cout << t-- << " ";
        cout << t++ << " ";
        cout << t << endl;
    }
}


/* Problem G: 时间类的流插入、提取和递增、递减运算
Time Limit: 3 Sec  Memory Limit: 128 MB
Submit: 5363  Solved: 3610
[Submit][Status]
Description
封装一个时间类Time，在类上重载以下运算符，使得main()函数能够正确运行。
流插入操作符“>>”，按照输入格式从标准输入读取三个整数：hh,mm,ss，分别表示时、分、秒，其值在int范围内。
流提取操作符“<<”；按照“hh:mm:ss”输出Time类的对象，不合法的时间输出“error!!!”。
前置自增运算符“++”：把时间对象的秒数加1并返回。
前置自减运算符“--”：把时间对象的秒数减1并返回。
后置自增运算符“++”：把时间对象的秒数加1，返回原值。
后置自减运算符“--”：把时间对象的秒数减1，返回原值。
以上4个自增、自减仅对合法的时间操作，并且不会产生不合法的时间。比如：
若原时间对象为“00:00:00”，自减运算后的对象为“23:59:59”;
若原时间对象为“23:59:59”，自增运算后的对象为“00:00:00”;
若原时间对象为“24:60:60”，自增或自减运算后对象仍为“24:60:60”。
函数调用格式见append.cc。
append.cc中已给出main()函数
Input
输入的第一个整数n，表示有n组测试数据，每组3个整数：hh,mm,ss，分别表示时、分、秒，其值都在int范围内。
Output
输出一张表：每列8个字符宽，两列之间有一个空格。
首先，输出一个表头：“++t      --t      t        t--      t++      t       ”，
其次，对应每组测试数据在一行内依次以下内容：
前置++、前置--、原值、后置--、后置++、原值。
若输入的日期合法，输出格式为“hh:mm:ss”，不足两位的输出需要前面补0。如果输入的时间不合法，则输出“error!!!”。格式见sample。
Sample Input
6
0 0 1
0 59 59
1 1 60
23 0 0
23 59 59
24 1 0
Sample Output
++t      --t      t        t--      t++      t       
00:00:02 00:00:01 00:00:01 00:00:01 00:00:00 00:00:01
01:00:00 00:59:59 00:59:59 00:59:59 00:59:58 00:59:59
error!!! error!!! error!!! error!!! error!!! error!!!
23:00:01 23:00:00 23:00:00 23:00:00 22:59:59 23:00:00
00:00:00 23:59:59 23:59:59 23:59:59 23:59:58 23:59:59
error!!! error!!! error!!! error!!! error!!! error!!!
HINT
输出格式用头文件<iomanip>中流操作算子：

setw(w)   ：设置数据的输出宽度为w个字符

setfill(c)：设置用字符c作为填充字符

left      ：设置输出左对齐

right     ：设置输出优对齐

Append Code
append.cc, */