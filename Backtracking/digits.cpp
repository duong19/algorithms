#include <bits/stdc++.h>

using namespace std;

int isPicked[11];
int kq[11];
int c = 0;

int isOK (int Q)
{
    int sum = kq[1]*100 + kq[2]*10 + kq[3] - kq[4]*100 - 62 + kq[5]*1000 + kq[6]*100 + kq[7]*10 + kq[3];
    if (sum == Q) return 1;
    return 0;
}
void DIGITS(int Q, int k)
{
    for (int i = 1; i <= 9; i++)
    {
        if (!isPicked[i])
        {
            kq[k] = i;
            isPicked[i] = 1;
            if (k == 7)
            {
                if (isOK(Q))
                    c++;
            }
            else DIGITS(Q,k+1);
            isPicked[i] = 0;
        }
    }
}

int main()
{
    int Q;
    cin >> Q;
    DIGITS(Q,1);
    cout << c;
}
