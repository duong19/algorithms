    #include <bits/stdc++.h>
    #include <string>

    #define MAX 101

    using namespace std;
    vector<string> fib;
    vector<string> l;
    vector<string> r;
    int N;
    string P;
    int countF[MAX] = {-1};

    int search(string middle)
    {
        int all = 0;
        for (int i = 0; i <= (int) middle.size() - (int) P.size(); i++){
            int count = 1;
            for (int j = 0; j < P.size(); j++){
                if (P[j] != middle[i+j]){
                    count = 0;
                    break;
                }
            }
            all += count;
        }
        cout << all << endl;
        return all;
    }

    int countFib(int n)
    {
        if (countF[n] != -1) return countF[n];
        if (n <= 1) return P == fib[n];
        int res = countFib(n-1) + countFib(n-2);
        cout << res << endl;
        string middle = l[n-1] + r[n-2];
        res += search(middle);
        countF[n] = res;
        return res;
        
    }



    int main()
    {
        fib.push_back("0");
        fib.push_back("1");
        cin >> N >> P;
        l.resize(N+1); r.resize(N+1);
        for (int i = 2; fib.back().size() < 100000; i++)
        {
            fib.push_back(fib.back() + fib[fib.size() - 2]);
        }
        for (int i = 0; i < fib.size() && i <= N; i++)
        {
            if (fib[i].size() <= (P.size()-1))
            {
                l[i] = fib[i];
                r[i] = fib[i];
            }else
            {
                l[i] = string(fib[i].end() - P.size() + 1, fib[i].end());
                r[i] = string(fib[i].begin(), fib[i].begin() + P.size() - 1);
            }
            
        }
        for (int i = fib.size(); i <=N; i++)
        {
            l[i] = l[i-2];
            r[i] = r[i-2];
        }
        cout << countFib(N) << endl;

    }