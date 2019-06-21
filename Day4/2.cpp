#include<iostream>

using namespace std;

struct x_pos{
    int fa;
    int la;
    x_pos(int a, int b){
        fa = a;
        la = b;
    }
};

int find(int * arr, int l, int r, int x){
    while(l < r){
        int m = (l + r) / 2;
        if(x > arr[m]){
            l = m + 1;
        }else{
            r = m;
        }
    }
    if(arr[r] != x) return -1;
    return r;
}

int find_first_app(int * arr, int l, int r, int n,  int x){
    if(r > 0){
        int pos = find(arr, l, r - 1, x);
        if(pos != -1) return find_first_app(arr, l, pos, n, x);
    }
    return r;
}

int find_last_app(int * arr, int l, int r, int n, int x){
    if(l < n-1){
        int pos = find(arr, l + 1, r, x);
        if(pos != -1) return find_last_app(arr, pos, r, n, x);
    }
    return l;
}

x_pos find2(int * arr, int n, int x){
    x_pos res(-1, -1);

    int pos = find(arr, 0, n - 1, x);
    
    if(pos != -1){
        res.fa = find_first_app(arr, 0, pos, n, x) + 1;
        res.la = find_last_app(arr, pos, n - 1, n, x) + 1;
    }

    return res;
}

int main(){

    /* 
    int a[] = {1,2,3,3,3,3,3,3,3,4,5,6,7};
    int n = sizeof(a)/sizeof(int);

    int x;
    cin >> x;

    x_pos res = find2(a, n, x);
    cout << res.fa << " " << res.la << endl;
    */

   int n, m, x;
   cin >> n >> m;
   int a[n];

   for(int i = 0; i < n; ++i){
       cin >> a[i];
   }
    
   for(int i = 0; i < m; ++i){
       cin >> x;
       x_pos res = find2(a, n, x);
        if(res.fa == -1){
            cout << 0 << endl;
        }else{
            cout << res.fa << " " << res.la << endl;
        }
   }




    return 0;
}