#include<iostream>

using namespace std;

//O(N + N + M + K(N - M) 

bool f(string s, string t){
    if(t.size() == 0) return false;
    bool found = false;

    int p = 31;

    int p_i[s.size() + 1];
    p_i[0] = 1;

    for(int i = 1; i <= s.size(); ++i){
        p_i[i] = p_i[i-1] * p;
    }

    int h_p[s.size()];
    h_p[0] = s[0] - 'a' + 1;

    for(int i = 1; i < s.size(); ++i){
        h_p[i] = h_p[i-1] + p_i[i] * (s[i] - 'a' + 1);
    }

    int x, y;

    int ht = t[0] - 'a' + 1;
    for(int i = 1; i < t.size(); ++i){
        ht += p_i[i] * (t[i] - 'a' + 1);
    }

    for(int i = 0; i <= s.size() - t.size(); ++i){
        if(i == 0){
            x = 0;
        } 
        else{
            x = h_p[i - 1];
        }
        y = h_p[i + t.size() - 1];
        if( y - x  == ht * p_i[i]){
            found = true;
            break;
        }
    }
    return found;
}

int main(){
    
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;

    if(f(s,t)) cout << "found!" << endl;
    else cout << "not found!";

    return 0;
}