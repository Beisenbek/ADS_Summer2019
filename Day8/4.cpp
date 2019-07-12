#include<iostream>

using namespace std;

int f(string s, string t){
    if(s.size() == 0) return 0;
    
    int res = 0;

    long long p = 31;
    long long q = 101;

    long long p_i[max(s.size(),t.size()) + 1];
    p_i[0] = 1;

    for(int i = 1; i <= s.size(); ++i){
        p_i[i] = (p_i[i-1] * p) % q;
    }

    long long h_p[s.size()];
    h_p[0] = s[0] - 'a' + 1;

    for(int i = 1; i < s.size(); ++i){
        h_p[i] = (h_p[i-1] + (p_i[i] * (s[i] - 'a' + 1))% q);
    }

    long long x, y;

    long long ht = t[0] - 'a' + 1;
    for(int i = 1; i < t.size(); ++i){
        ht = ht + (p_i[i] * (t[i] - 'a' + 1)) % q;
    }
    
    for(int i = 0; i <= s.size() - t.size(); ++i){
        if(i == 0){
            x = 0;
        } 
        else{
            x = h_p[i - 1];
        }
        y = h_p[i + t.size() - 1];
        long long z = (ht * p_i[i]) % q;
        if( y - x  == z){
            res++;
        }
    }
    return res;
}

int main(){
    
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string t;
    string s = "";
    int k;
    cin >> k;
    for(int i = 0; i < k; ++i){
        cin >> t;
        int x = f(s,t);
        if(x == 0){
            cout << "OK" << endl;
        }else{
            cout << t  << x << endl;
        }
        s = s + "#"  + t;
    }

    f(s,t);
    
    return 0;
}