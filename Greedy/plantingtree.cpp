#include <bits/stdc++.h>
using namespace std;

#define MAXN 100002

int t[MAXN];
int N;


void PTREE()
{
	for (int i = 0; i < N; i++)
	{
		t[i] += i;	
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t[i];
	}
	sort(t, t+ N);
	for (int i = 0; i < N; i++)
	{
		t[i] += i;	
	}
	cout << *max_element(t, t+ N) + 2 << endl;

}
