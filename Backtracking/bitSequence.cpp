#include <bits/stdc++.h>

using namespace std;

void printResult(int *arr, int n){
    for (int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << "\n";
}

void bitSequence(int i, int n, int *arr){

    for (int j = 0; j <= 1; j++){
        arr[i] = j;
        if (i == (n - 1)){
            printResult(arr, n);
        }else{
            bitSequence(i+1, n, arr);
        }
    }
}
int main(){
    int *arr = new int[3];
    bitSequence(0,3,arr);
}