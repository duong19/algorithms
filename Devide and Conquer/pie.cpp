#include <bits/stdc++.h>


using namespace std;


#define MAX 100011

double pi = acos(-1);
long long N, F;
long long radi[MAX];

long long maxFriend(double v)
{
    long long num = 0;
    for (int i = 1; i <= N; i++)
    {
        num += floor(radi[i]*radi[i]*pi/ v);
    }
    return num;
}

double PIE(double left, double right)
{
    double mid = (left + right) / 2.0;
    while (abs(right - left) > 1e-7)
    {
        mid = (left + right) / 2.0;
        if (maxFriend(mid) >= F+1)
        {
            left = mid;
        }else
        {
            right = mid;
        }
    }
    return right;
}


int main()
{
    vector<double> res;
    int test;
    cin >> test;
    while (test--)
    {
        cin >> N >> F;
        for (int i = 1; i <= N; i++)
        {
            cin >> radi[i];
        }
        res.push_back(PIE(0.0, 1000000.0));
        
    }
    for (int i =0; i < res.size(); i++)
        printf("%.6f", res[i]);
}
