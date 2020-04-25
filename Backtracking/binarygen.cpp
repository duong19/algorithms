#include <bits/stdc++.h>

using namespace std;


int x[10000];

void nextP (int n)
{
    int i;
    for (i = n; i >= 1; i--)
    {
        if (x[i] == 1)
            break;

    }
    if (i == n)
    {
        for (int j = i; j >= 1; j--)
        {
            if (x[j] == 1) x[j] = 0;
            else
            {
                x[j] = 1;
                break;
            }
        }
    }
    else
    {
        x[n] = 1;
    }

}

int main()
{
   int n;
   string p;
   cin >> n >> p;

    for (int i = 0; i < n; i++)
        x[i+1] = p[i] - '0';
    int isFull = 1;
    for (int i = 1; i <= n; i++)
        if (x[i] == 0)
        {
            isFull = 0;
            break;
        }
    if (isFull == 1) cout << -1;
    else {nextP(n);
    for (int i = 1; i <= n; i++) cout << x[i];
    }
}
