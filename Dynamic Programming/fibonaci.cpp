#include <bits/stdc++.h>

using namespace std;

int mem[1000];

int fibonaci(int n)
{
	if (n < 2) return 1;
	if (mem[n] != -1) return mem[n];

	mem[n] = fibonaci(n-1) + fibonaci(n-2);
	return mem[n];
}
int main()
{
	for (int i=0; i < 1000; i++)
	{
		mem[i] = -1;
	}
	cout << fibonaci(5) << endl;
	return 0;

}

