#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll A, B, C;
ll res = 0;
int main()
{
	
	ll S[3];
	for (int i = 0; i < 3; i++)
		cin >> S[i];
	sort(S, S + 3);
	ll res = 0;
	if (S[1] == S[2] && S[0] == S[2]){ 
		cout << res << endl;
		return 0;
	}
	ll temp = (S[1] - S[0]);
	S[2] += temp;
	S[0] += temp;
	res += temp;
	res += S[2] - S[0];
	cout << res;
}