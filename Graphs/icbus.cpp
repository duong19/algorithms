#include <bits/stdc++.h>
using namespace std;
#define MAXN 10001
int N,K;
int dist[MAXN][MAXN], c[MAXN], D[MAXN];
vector<int> adj[MAXN];
vector<int> newA[MAXN];


void BFS(int u)
{
	queue<int> Q;
	Q.push(u);
	int d = 0;
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		dist[u][u] = 0;
		for (int i = 0; i < adj[v].size(); i++)
		{
			int t = adj[v][i];
			if (dist[u][t] == -1 && d <= D[u])
			{
				dist[u][t] = c[u];
				Q.push(t);
			}
		}
	}

}

void DIJKSTRA(int u)
{
	
}



int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> c[i] >> D[i];
	}
	for (int i = 0; i < K; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		adj[temp1].push_back(temp2);
		adj[temp2].push_back(temp1);
	}
	for (int i = 1; i <= N; i++)
	{
		BFS(i);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			int v = adj[i][j];
			if (dist[i][v] != -1)
			{
				newA[i].push_back(v);
			}
		}
	}


}