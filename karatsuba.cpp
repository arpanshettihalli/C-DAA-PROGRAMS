#include<bits/stdc++.h>
using namespace std;
long long karatsuba(long long x,long long y)
{
    if(x<10 || y<10)
    {
        return x*y;
    }
    int n=max(to_string(x).size(),to_string(y).size());
    int m=n/2;
    long long power=pow(10,m);
    long long a=x/power;
    long long b=x%power;
    long long c=y/power;
    long long d=y%power;
    long long P = karatsuba(a, c);
    long long Q = karatsuba(b, d);
    long long R = karatsuba(a + b, c + d);
    return P * power * power + (R - P - Q) * power + Q;
}