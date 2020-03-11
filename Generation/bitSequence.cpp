#include <bits/stdc++.h>

using namespace std;

void bitSequence(int n){
    int len = n - 1;
    int *arr = new int[len];

    //Khoi tao chuoi
    for (int i = 0; i < n; i++){
        arr[i] = 0;
    }

    while (len != 0){
        for (int i = 0; i < n; i++){
            cout << arr[i];
        }
        cout << "\n";

        while (len > 0 && arr[len] == 1){
            len--;
        }
        

        if(arr[len] == 0){
            arr[len] = 1;
            for (int j = len + 1; j < n; j++){
                arr[j] = 0;
            }
            len = n - 1;
        }
    }

}

int main(){
    int n;
    cin >> n;
    bitSequence(n);
    return 0;
}