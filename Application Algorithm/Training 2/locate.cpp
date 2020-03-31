#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAXL 2001

typedef struct coordinate{
    int x;
    int y;
} cdnate;

int locate(vector<cdnate>picA, vector<cdnate>picB, int L, int C){
    static int count[MAXL][MAXL];
    for(int i = 0; i < MAXL; i++){
        for(int j = 0; j < MAXL; j++){
            count[i][j] = 0;
        }
    }
    int maxCount = 0;
    for(int i = 0; i < picA.size(); i++){
        for(int j = 0; j < picB.size(); j++){
            int maxTemp = ++count[(picA[i].x - picB[j].x + 1000)][(picA[i].y - picB[j].y + 1000)];
            maxCount = max(maxCount, maxTemp);
        }
    }
    return maxCount;
}
int main(){
    int n;
    cin >> n;
    for(int k = 0;k < n ; k++){
        int L,C;
        cin >> L >> C;
        vector<cdnate> picA, picB;
        int temp;
        for(int i = 0; i < L; i++ ){
        for(int j = 0; j < C; j++){
            cin >> temp;
            cdnate tempA;
            tempA.x = i;
            tempA.y = j;
            if(temp == 1){
                picA.push_back(tempA);
                }
            }
        }
     for(int i = 0; i < L; i++ ){
        for(int j = 0; j < C; j++){
            cin >> temp;
            cdnate tempB;
            tempB.x = i;
            tempB.y = j;
            if(temp == 1){
                picB.push_back(tempB);
            }
        }
    }

    cout << locate(picA,picB,L,C) << endl;

    }
}
