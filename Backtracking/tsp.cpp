#include <bits/stdc++.h>
 
using namespace std;
 
 
int cost[50][50];
int optCost[1 << 20][20];
 
 
int min_cost(int a, int b)
{
    if (a < b) return a;
    return b;
}
 
int TSP(int n, int k, int bM, int lastC){
    if (optCost[bM][lastC] != -1) return optCost[bM][lastC];
    if (k == n)
    {
        return optCost[bM][lastC] = cost[lastC][1];
    }
    optCost[bM][lastC] = 1e9;
    for (int i = 2; i <= n; i ++)
    {
        if (((bM >> i-1) & 1) == 0)
        {
            optCost[bM][lastC] = min_cost(optCost[bM][lastC], cost[lastC][i] + TSP(n, k+1, bM | (1 << i-1), i));
        }
    }
    return optCost[bM][lastC];
}
 
int main()
{
    memset(cost, 0x3f, sizeof cost);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++)
    {
            int tempX, tempY;
            cin >> tempX >> tempY;
            cin >> cost[tempX][tempY];
    }
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j <= n; j++)
        {
            optCost[i][j] = -1;
        }
    cout << TSP(n, 1, 1, 1) << endl;
    return 0;
}