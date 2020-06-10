#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000001
vector<int> a[MAXN];
int color[MAXN];
int m,n,isOK = true;

void dfs(int u)
{
	for (int i = 0; i < a[u].size(); i++)
	{
		int v = a[u][i];
		if ( color[v] == -1)
		{
			color[v] = !color[u];
			dfs(v);
		}else if (color[v] == color[u])
		{
			isOK = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t;

	int i = 1;
	while (i <= t)
	{
		
		cin >> m >> n;
		for (int i = 0; i < n; i++)
		{
			int tempX, tempY;
			cin >> tempX >> tempY;
			a[tempX].push_back(tempY);
			a[tempY].push_back(tempX);
		}
		for (int i = 1; i <= m; i++) color[i] = -1;
		for (int i = 1; i <=m ; i++)
		{
			if (isOK == false) break;
			if (color[i] == -1)
			{
				color[i] = 0;
				dfs(i);
			}
		}
		cout << "Scenario #" << i << ":" << endl;
		if (isOK)
		{
			cout << "No suspicious bugs found!" << endl;
		}else{
			cout << "Suspicious bugs found!" << endl;
		}
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		isOK = true;
		i++;
	}
}