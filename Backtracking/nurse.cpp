#include <bits/stdc++.h>

using namespace std;


int x[1000];
int N, K1, K2;
int ans = 0;
int tempK = 0;

int check(int i,int k)
{
    if (i == 0)
    {
        if (x[k-1] == 0) return 0;
        if (tempK != 0 && tempK < K1) return 0;
    }
    if (i == 1)
    {
        if (tempK+1 > K2) return 0;
    }
    return 1;
}
void Nurse( int k)
{
    for (int i = 0; i <= 1; i++)
    {
        if (check(i, k))
        {
            x[k] = i;
            int t = tempK;
            if (i == 1) tempK++;
            else{
                if (k != N) tempK = 0;
            }
            if(k == N)
            {
                if (tempK >= K1 && tempK <= K2)
                {
                    ans ++;
                    /*for (int i =1; i<=N;i++){
                            cout << x[i] << "\t" ;
                    }
                    cout << "\n";*/
                }
            }
            else
            {
                Nurse(k+1);
            }
            if (i == 1) tempK--;
            else tempK=t;

        }
    }
}

int main()
{
  cin >> N >> K1 >> K2;
    x[0] = 1;
    Nurse(1);
    cout << ans;

}
