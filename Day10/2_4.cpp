#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n + 1][n + 1];
    int d[n + 1];
    int p[n + 1];
    queue<int> q;
    bool used[n+1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
        d[i] = 100000;
        used[i] = false;
    }

    int s, t;
    cin >> s >> t;

    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;


    while(q.size() != 0){
        int cur = q.front();
        q.pop();
        for(int i = 1; i <= n; ++i){
            if(a[cur][i] && !used[i]){
                q.push(i);
                used[i] = true;
                d[i] = d[cur] + 1;
                p[i] = cur;
            }
        }
    }

    if(d[t] >= 100000){
        cout << -1 << endl;
    }else if(d[t] == 0){
        cout << 0 << endl;
    }else{
        cout << d[t] << endl;
        int px = t;
        vector<int> v;
        while(px != -1){
            v.push_back(px);
            px = p[px];
        }
        for(int i = v.size() - 1; i >= 0; --i){
            cout << v[i] << " ";
        }
    }

    return 0;
}