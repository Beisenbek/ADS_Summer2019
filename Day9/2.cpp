#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool used[100001];
map<int, vector<int> > e_l;
int n,m;

void dfs(int v){
    cout << v <<  " ";
    used[v] = true;
    vector<int> e = e_l[v];
    for(int i = 0; i < e.size(); ++i){
        int t = e[i];
        if(used[t] == false){
            dfs(t);
        }
    }
}

int main(){
    int x, y;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        e_l[x].push_back(y);
        e_l[y].push_back(x);
    }

    int res = 0;
    
    for(int i = 1; i <= n; ++i){
        if(used[i] == false){
            dfs(i);
            res++;
            cout << endl;
        }
    }

    cout << res << endl;

    return 0;
}