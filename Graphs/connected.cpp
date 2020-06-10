#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000001

int isVisited[MAXN];
vector<int> adj[MAXN];
int v,e, numC = 0;


void DFS(int u)
{
	if(isVisited[u]) return;
	isVisited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (!isVisited[v])
			DFS(v);
	}
}

int main()
{
	cin >> v >> e;
	for (int i = 0; i < e;i ++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);

	}
	for (int i = 1; i<= v; i++)
	{
		if (!isVisited[i])
		{
			DFS(i);
			numC++;
		}
	}
	cout << numC << endl;
}