#include <iostream>

using namespace std;

#define inf 1000000

int main(){

    int n, s, t;
    cin >> n >> s >> t;

    int a[n + 1][n + 1];
    int d[n + 1];
    bool used[n + 1];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
        used[i] = false;
        d[i] = inf;
    }

    d[s] = 0;

    for(int i = 1; i <= n; ++i){
        int v = -1;
        for(int j = 1; j <= n; ++j){
            if(used[j] == false && (v == -1 || d[v] > d[j]) ){
                v = j;
            }
        }
        if(v == -1){
            break;
        }
        used[v] = true;

        for(int to = 1; to <= n; ++to){
            if(a[v][to] > 0){
                d[to] = min(d[to], d[v] + a[v][to]);
            }
        }
    }

    if(d[t] >= inf){
        cout << -1 << endl;
    }else{
        cout << d[t] << endl;
    }


    return 0;
}