#include<iostream>


using namespace std;

//O(M*(N - M + 1))

bool f(string s, string t){
    if(t.size() == 0) return false;
    bool found = true;
    for(int i = 0; i <= s.size() - t.size(); ++i){
        int k = i;
        found = true;
        for(int j = 0; j < t.size(); ++j){
            if(s[k] == t[j]){
                k++;
            }else{
                found = false;
                break;
            }
        }
        if(found) break;
    }
    return found;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s = "ABCD",t = "";

    if(f(s,t)) cout << "found!" << endl;
    else cout << "not found!";

    return 0;
}