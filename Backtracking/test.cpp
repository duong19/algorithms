#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int findSignal(vector<int> v, vector<int> maxR, vector<int> maxL, int b){
    int maxTemp = INT_MIN;
    int found = -1;
    for (int i = 1; i < v.size() - 1; i++){
        if(maxL[i] - v[i] >= b && maxR[i] - v[i] >=b){
            maxTemp = max(maxTemp, (maxL[i] - v[i] + maxR[i] - v[i]));
            found = 1;
        } 
    }
    if (found == -1){
        return found;
    }
    return maxTemp;
    
}

int main(){
    int n, b;
    int temp;
    cin >> n >> b;
    vector<int> v;
    for (int i = 0; i < n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    int maxTemp = INT_MIN;
    vector<int> maxL, maxR;
    maxL.push_back(maxTemp);
    for (int i = 1; i < n; i++){
        maxTemp = max(maxTemp, v[i-1]);
        maxL.push_back(maxTemp);
    }
     maxTemp = INT_MIN;
         maxR.push_back(maxTemp);

     for (int i = n - 2; i >= 0; i--){
        maxTemp = max(maxTemp, v[i+1]);
        maxR.push_back(maxTemp);
    }
    reverse(maxR.begin(), maxR.end());
    cout << findSignal(v, maxR, maxL, b);
    

}