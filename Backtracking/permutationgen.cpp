#include <bits/stdc++.h>

using namespace std;

int n;
int findMaxAfter(int a, int i, int* v){
	for (int j = n-1; j > i; j--){
		if(v[j] > a){
			return j;
		}
	}
}

int main(){
	cin >> n;
	int *curPermutation = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> curPermutation[i];
	}
	int hasNext = 0;
	for (int i = n - 1; i > 0; i--){
		if (curPermutation[i] > curPermutation[i-1]){
			hasNext = 1;
			int id = findMaxAfter(curPermutation[i-1], i-1, curPermutation);
			swap(curPermutation[i-1], curPermutation[id]);
			reverse(curPermutation + i, curPermutation + n);
			break;
		}
	}
	if (hasNext == 0){
		cout << -1;
	}else{
		for (int i = 0; i < n; i++){
			cout << curPermutation[i] << " ";
		}
	}




	return 0;
}

