// 50. Pow(x, n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

#include <iostream>
using namespace std;

// previous
double myPow1(double x, int n)
{
    int flag = 0;
    double result = 1;
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n < 0)
    {
        flag = 1;
        n = n * (-1);
    }
    while (n > 0)
    {
        result = x * result;
        --n;
    }
    if (flag == 1)
    {
        return 1 / result;
    }
    return result;
}

// updated
double myPow(double x, int n)
{
    double ans = 1;

    long long nn = n;
    if(n<0) nn = (-1)*n;
    while(nn){
        if(nn%2){
            ans = ans * x;
            nn = nn-1;
        }
        else{
            x = x*x;
            nn = nn/2;
        }
    }
    if(n<0) ans = (double)1/double(ans);
    return ans;
}

int main()
{
    cout << "Result of x^n = " << myPow(2, -2);
    return 0;
}