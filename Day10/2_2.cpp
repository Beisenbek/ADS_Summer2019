#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n][n];
    int d[n];
    int p[n];
    queue<int> q;
    bool used[n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
        d[i] = 10000;
        used[i] = false;
    }

    int s, t;
    cin >> s >> t;
    s--;
    t--;

    q.push(s);
    used[s] = true;
    d[s] = 0;
    p[s] = -1;


    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < n; ++i){
            if(a[cur][i] && used[i] == false){
                q.push(i);
                used[i] = true;
                d[i] = d[cur] + 1;
                p[i] = cur;
            }
        }
    }
    if(d[t] == 0){
        cout << 0 << endl;
    }
    else 
    if(d[t] >= 10000){
        cout << -1 << endl;
    }
    else{
        cout << d[t] << endl;
        int px = t;
        vector<int> v;
        while(px != -1){
            v.push_back(px + 1);
            px = p[px];
        }
        for(int i = v.size() - 1; i >= 0; --i){
            cout << v[i] << " ";
        }
    }

    return 0;
}