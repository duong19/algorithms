
#include<bits/stdc++.h> 
using namespace std; 
  

int areParanthesisBalanced(string expr) 
{ 
    stack<char> s; 
    char x; 
  
     
    for (int i=0; i<expr.length(); i++) 
    { 
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{') 
        { 
            
            s.push(expr[i]); 
            continue; 
        } 
  
        
        if (s.empty()) 
           return 0; 
  
        switch (expr[i]) 
        { 
        case ')': 
  
             
            x = s.top(); 
            s.pop(); 
            if (x=='{' || x=='[') 
                return 0; 
            break; 
  
        case '}': 
  
            
            x = s.top(); 
            s.pop(); 
            if (x=='(' || x=='[') 
                return 0; 
            break; 
  
        case ']': 
  
             
            x = s.top(); 
            s.pop(); 
            if (x =='(' || x == '{') 
                return 0; 
            break; 
        } 
    } 
  
    
    return (s.empty()); 
} 
typedef struct coordinate{
    int x;
    int y;
} cdnate;
 
int main() 
{
    vector<cdnate> a;
    for (int i = 0; i < 10; i ++){
        for (int j = 0; j <8 ; j++){
            a.push_back({i,j});
        }
    }
    cout << a[0].x << a[0].y ;
}