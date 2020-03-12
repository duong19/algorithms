#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << '\n';
}

void permutation(int i, int n, int *arr){
    if (i == n-1){
        printArray(arr, n);
    }
    for (int j = i; j < n; j++){
        swap(arr[j], arr[i]);
        permutation(i+1, n, arr);
        swap(arr[j], arr[i]);   
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    permutation(0,n,arr);
}