#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int isValid(char c1, char c2){
    if(c1 == '(' && c2 == ')'){
        return 1;
    }
     if(c1 == '[' && c2 == ']'){
        return 1;
    }
     if(c1 == '{' && c2 == '}'){
        return 1;
    }
    return 0;
}

int checkParentheses(string str){
    stack<char> s;

    char temp;
    for (int i = 0; i < str.size(); i++){

        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            s.push(str[i]);
            continue;
        }else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
            if(s.empty()) return 0;
            temp = s.top();
            s.pop();
            if(!isValid(temp, str[i])) return 0;
        }
               
    }
    if(s.empty()){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> kq;
    for (int i = 0;i < n; i++){
        string str;
        cin >> str;
        kq.push_back(checkParentheses(str));


    }
    for(int i = 0;i < n ; i++){
       cout << kq[i] << endl;
    }
    return 0;
    
}