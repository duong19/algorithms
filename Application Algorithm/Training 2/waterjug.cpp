#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define pi pair<int, int>
#define mp make_pair


typedef struct State{
    int x;
    int y;
    int numSt;
} state;


int BFS(int a, int b, int c){
    queue<state> q;
    map<pi, int> isVisited;
    q.push({0,0,0});
    isVisited[mp(0,0)] = 1;
    while(!q.empty()){
        state temp = q.front();
        q.pop();
        if (temp.x == c || temp.y == c){
            return temp.numSt;
        }
        if (temp.x < a){
            if(!isVisited[mp(a,temp.y)]){
                isVisited[mp(a,temp.y)] = 1;
                q.push({a, temp.y, temp.numSt+1});
            }
            if(temp.y > 0){
                int minW = min((a - temp.x),temp.y);
                if(!isVisited[mp(temp.x + minW,temp.y - minW)]){
                    isVisited[mp(temp.x + minW,temp.y - minW)] = 1;
                    q.push({temp.x + minW,temp.y - minW,temp.numSt+1});
                } 
            }
        }
        if (temp.y < b){
            if(!isVisited[mp(temp.x,b)]){
                isVisited[mp(temp.x,b)] = 1;
                q.push({temp.x, b, temp.numSt+1});
            }
            if(temp.x > 0){
                int minW = min(temp.x,(b - temp.y));
                if(!isVisited[mp(temp.x - minW,temp.y + minW)]){
                    isVisited[mp(temp.x - minW,temp.y + minW)] = 1;
                    q.push({temp.x - minW,temp.y + minW,temp.numSt+1});
                } 
            }
        }
        if (temp.x > 0){
            if(!isVisited[mp(0,temp.y)]){
                isVisited[mp(0,temp.y)] = 1;
                q.push({0, temp.y, temp.numSt+1});
            }
            
        }
        if (temp.y > 0){
            if(!isVisited[mp(temp.x,0)]){
                isVisited[mp(temp.x,0)] = 1;
                q.push({temp.x, 0, temp.numSt+1});
            }
        }
        
        
    }
    return -1;
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << BFS(a,b,c);
}