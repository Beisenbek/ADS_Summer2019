#include <iostream>
#include <map>
#include <vector>

using namespace std;

int color[101];
map<int, vector<int> > e_l;
int n,m;

vector<int> res;
bool possible = true;

void dfs(int v){
    color[v] = 1;
    vector<int> e = e_l[v];
    for(int i = 0; i < e.size(); ++i){
        int t = e[i];
        if(color[t] == 0){
            dfs(t);
        }else if(color[t] == 1){
            possible = false;
            break;
        }
    }
    color[v] = 2;
    res.push_back(v);
}

int main(){
    int x, y;
    cin >> n >> m;

    for(int i = 1; i <= n; ++i){
        color[i] = 0;
    }

    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        e_l[x].push_back(y);
    }

    for(int i = 1; i <= n; ++i){
        if(color[i] == 0){
            dfs(i);
        }
    }

    if(possible){
        cout << "Yes" << endl;
        for(int i = res.size() - 1; i >= 0; --i){
            cout << res[i] << " ";
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}