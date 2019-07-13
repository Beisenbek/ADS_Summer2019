#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n + 1][n + 1];
    int d[n + 1];
    queue<int> q;
    bool used[n+1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
        d[i] = -1;
    }

    int s, t;
    cin >> s >> t;

    q.push(s);
    used[s] = true;
    d[s] = 0;

    stringstream res;

    while(q.size() != 0){
        int cur = q.front();
        res << cur << " ";
        q.pop();
        for(int i = 1; i <= n; ++i){
            if(a[cur][i] && !used[i]){
                q.push(i);
                used[i] = true;
                d[i] = d[cur] + 1;
            }
        }
    }

    if(d[t] == -1){
        cout << -1 << endl;
    }else if(d[t] == 0){
        cout << 0 << endl;
    }else{
        cout << d[t] << endl;
        cout << res.str();
    }

    return 0;
}