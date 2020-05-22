// timetransfer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"timetype.h"

using namespace std;

//通用时转换成儒略日
jdt ut2jd(ut ti)
{
    int ans ;
    double ans2;
    int y, m;
    if (ti.month <= 2) 
    {  
        y = ti.year - 1;
        m = ti.month + 12;
    }
    else 
    {
        y = ti.year;
        m = ti.month;
    }
    ans2 = floor(365.25 * y) + floor(30.6001 * (m + 1)) + ti.day + 1720981.5 + double(ti.hour) / 24 + double(ti.minute) / 60 / 24 + double(ti.second) / 3600 / 24;
    ans = floor(ans2);
    ans2 -= ans;
    jdt t(ans,ans2);
    return t;
}

//儒略日转换成通用时
ut jd2ut(jdt ti) 
{
    double jd = ti.day + ti.second;
    int a, b, c, d, e;
    int D, M, Y, h, m;
    double s,g,f;

    a = floor(jd+0.5);
    b = a + 1537;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor((long(b) - d) / 30.6001);
    g = a - floor(a);
    f = (g * 24 - floor(g * 24))*60;

    D = b - d - floor(30.6001 * e);
    M = e - 1 - 12 * floor(e / 14);
    Y = c - 4715 - floor((7 + M) / 10);
    h = floor(g * 24);
    m = floor(f);
    s = f - m;

    ut t1(Y,M,D,h,m,s);
    return t1;
}

//儒略日转换成gps时
gpst jd2gpst(jdt ti) 
{
    double JD = ti.day + ti.second;
    int w;
    double s,t;
    
    t = (JD - 2444244.5) / 7;
    w = floor(t);
    s = t - w ;

    gpst t1(w, s);
    return t1;
}

//gps时转换成儒略日
jdt gpst2jd(gpst ti) 
{
    double gt = ti.week + ti.second;
    int d;
    double s,n;

    n = gt * 7 + 2444244.5;
    d = floor(n);
    s = n - d;

    jdt t(d,s);
    return t;
}

//儒略日转换成年积日
act jd2act(jdt ti) 
{
    ut t1 = jd2ut(ti);
    int y, d;
    double s,n;
    

    y = t1.year;
    ut t2(y,1,1,0,0,0.0);
    jdt t2s = ut2jd(t2);
    n = ti.day+ti.second - t2s.day-t2s.second;
    d = floor(n);
    s = n - d;

    act ts(d,y,s);
    return ts;
}

//年纪日转换成儒略日
jdt act2jd(act ti) 
{
    int d,y;
    double s,n;

    y = ti.year;
    ut t1(y, 1, 1, 0, 0, 0.0);
    jdt t2 = ut2jd(t1);
    n = t2.day + t2.second + ti.day + ti.second;
    d = floor(n);
    s = n - d;

    jdt t(d, s);
    return t;
}

int main()
{
    //测试
    ut t1;
    act t3;
    jdt t = ut2jd(t1);
    act t2 = jd2act(t);
    jdt t4 = act2jd(t3);
    cout << t.day << endl;
    cout << t4.day << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
