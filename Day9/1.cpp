#include <iostream>

using namespace std;

int a[101][101];
bool used[101];
int n;
int res = 0;

void dfs(int v){
    used[v] = true;
    res++;
    for(int i = 1; i <= n; ++i){
        if(a[v][i] != 0 && used[i] == false){
            dfs(i);
        }
    }
}

int main(){
    int s;

    cin >> n;
    cin >> s;
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }

    dfs(s);

    cout << res << endl;

    return 0;
}