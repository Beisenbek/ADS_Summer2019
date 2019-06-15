#include<iostream>
#include<vector>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    int a[n][m];

    vector<int> vc[m];
    vector<int> vr[n];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];  
        }
    }

    for(int i = 0; i < n; ++i){
        int mr = 1001;
        for(int j = 0; j < m; ++j){
             mr = min(mr, a[i][j]);
        }
        for(int j = 0; j < m; ++j){
             if(mr == a[i][j]){
                 vr[i].push_back(j);
             }
        }
    }

    
    for(int j = 0; j < m; ++j){
        int mc = -1001;
        for(int i = 0; i < n; ++i){
             mc = max(mc, a[i][j]);
        }
        for(int i = 0; i < n; ++i){
             if(mc == a[i][j]){
                 vc[j].push_back(i);
             }
        }
    }

    int cnt = 0;

    for(int i = 0; i < n; ++i){
        for(int k = 0; k < vr[i].size(); ++k){
            int j = vr[i][k];
            for(int l = 0; l < vc[j].size(); ++l){
                if(vc[j][l] == i){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}