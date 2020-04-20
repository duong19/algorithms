#include <bits/stdc++.h>

using namespace std;

#define MAX 100
int n, K, Q;
int first[MAX];
int route[MAX];
int d[MAX], cost[MAX][MAX];
int isVisited[MAX];
int load[MAX];
int road = 0, ans = 0, tempCost = 0, minCost = INT_MAX;


int isValid(int i, int k)
{
    if (i > 0)
    {
        if (isVisited[i]) return 0;
        if (load[k] + d[i] > Q) return 0;
    }
    return 1;
}

void cvrpcount(int last, int k)
{

        for (int i = 0; i <= n; i ++)
        {
            if (isValid(i, k))
            {
                if (tempCost > minCost) return;
                route[last] = i;
                isVisited[i] = 1;
                road++;
                tempCost += cost[last][i];
                load[k] += d[i];
                if (i == 0)
                {
                    if (k == K)
                    {
                        if (road == n + K)
                            if (tempCost < minCost) minCost = tempCost;
                    }else
                    {
                        cvrpcount(first[k+1], k+1);
                    }
                }
                else
                {
                    cvrpcount(i, k);
                }
                isVisited[i] = 0;
                tempCost -= cost[last][i];
                load[k] -= d[i];
                road--;

            }
        }

}

void findFirst(int k)
{
    if (k > K)
    {
        cvrpcount(first[1],1);
    }
    else
    {
        for (int i = first[k-1] + 1; i <= n; i ++)
        {
            if (!isVisited[i])
            {
                if (tempCost > minCost) return;
                isVisited[i] = 1;
                first[k] = i;
                load[k] += d[i];
                tempCost += cost[0][i];
                road++;
                findFirst(k+1);
                isVisited[i] = 0;
                load[k] -= d[i];
                tempCost -= cost[0][i];

                road--;
            }
        }
    }
}

int main()
{
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <=n; j ++)
            cin >> cost[i][j];
    }
    first[0] = 0;
    findFirst(1);
    cout << minCost;

}
