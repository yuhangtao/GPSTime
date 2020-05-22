#include <iostream>
#include"timetype.h"

using namespace std;

//通用时转换成儒略日
jdt ut2jd(ut ti)
{
    int ans;
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
    jdt t(ans, ans2);
    return t;
}

//儒略日转换成通用时
ut jd2ut(jdt ti)
{
    double jd = ti.day + ti.second;
    int a, b, c, d, e;
    int D, M, Y, h, m;
    double s, g, f;

    a = floor(jd + 0.5);
    b = a + 1537;
    c = floor((b - 122.1) / 365.25);
    d = floor(365.25 * c);
    e = floor(double((b - d)) / 30.6001);
    g = jd + 0.5 - a;
    f = (g * 24 - floor(g * 24)) * 60;

    D = b - d - floor(30.6001 * e);
    M = e - 1 - 12 * floor(e / 14);
    Y = c - 4715 - floor((7 + M) / 10);
    h = floor(g * 24);
    m = floor(f);
    s = (f - m) * 60;

    ut t1(Y, M, D, h, m, s);
    return t1;
}

//儒略日转换成gps时
gpst jd2gpst(jdt ti)
{
    double JD = ti.day + ti.second;
    int w;
    double s, t;

    t = (JD - 2444244.5) / 7;
    w = floor(t);
    s = t - w;

    gpst t1(w, s);
    return t1;
}

//gps时转换成儒略日
jdt gpst2jd(gpst ti)
{
    double gt = ti.week + ti.second;
    int d;
    double s, n;

    n = gt * 7 + 2444244.5;
    d = floor(n);
    s = n - d;

    jdt t(d, s);
    return t;
}

//儒略日转换成年积日
act jd2act(jdt ti)
{
    ut t1 = jd2ut(ti);
    int y, d;
    double s, n;


    y = t1.year;
    ut t2(y, 1, 1, 0, 0, 0.0);
    jdt t2s = ut2jd(t2);
    n = ti.day + ti.second - t2s.day - t2s.second;
    d = floor(n);
    s = n - d;

    act ts(d, y, s);
    return ts;
}

//年纪日转换成儒略日
jdt act2jd(act ti)
{
    int d, y;
    double s, n;

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
    jdt t4 = act2jd(t2);
    cout.precision(15);
    cout << t.second << endl;
    cout << t4.second << endl;
    return 0;
}