#include <bits/stdc++.h>
#include <algorithm>
using namespace std;



int countRoad(vector<int> road){
     int count = 1;
    for (int i = 1;i < road.size(); i++){
        if(road[i] != road[i-1]){
            count += 1;
        }
    }
    
    
    return count;
}

int main(){
    int n;
    cin >> n;
    vector<int> road;
    int temp;
    for (int i = 0; i < n; i++){
        cin>>temp;
        road.push_back(temp);
    }
    
    int count = countRoad(road);

    int q, pos;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> pos >> temp;
        int tempN = 0, tempO = 0;
        if (pos != 1 && temp != road[pos-2]) tempN += 1;
        if (pos != n && temp != road[pos]) tempN += 1;
        if (pos != 1 && road[pos-1] != road[pos-2]) tempO += 1;
        if (pos != n && road[pos-1] != road[pos]) tempO += 1;
        if (tempN == tempO){
            road[pos - 1] = temp;
        }else {
            road[pos - 1] = temp;
            count = count + tempN - tempO;
        }
        cout << count << endl;

    }

}