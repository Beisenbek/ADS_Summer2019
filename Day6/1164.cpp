#include<iostream>

using namespace std;


struct heap{
    private:
        int * val;
        int hs;
        int n;

    public:
        heap(int _n){
            val = new int[_n];
            n = _n;
            hs = 0;
        }

        void add(int v){
            val[hs] = v; 
            sift_up(hs);
            hs++;
        }

        int get_max(){
            return val[0];
        }
        
        void del(){
            val[0] = val[hs - 1];
            hs--;
            int rootp = 0, maxp, lcpos, rcpos;

            while(2 * rootp + 1 < hs){
                lcpos = 2 * rootp + 1;
                rcpos = 2 * rootp + 2;
                
                if(rcpos < hs && val[lcpos] < val[rcpos]){
                    maxp = rcpos;
                }else{
                    maxp = lcpos;
                }

                if(val[rootp] < val[maxp]){
                    swap(val[rootp], val[maxp]);
                    rootp = maxp;
                }else{
                    break;
                }
            }
        }

        int sift_up(int pos, int ppos){
            if(ppos < 0 || val[ppos] >= val[pos]) return pos;
            swap(val[pos],val[ppos]);
            return sift_up(ppos,(ppos - 1) / 2);
        }

        int sift_up(int pos){
            return sift_up(pos, (pos - 1) / 2);
            /*
            int ppos = (pos - 1) / 2;
            while(ppos >=0 && val[ppos] < val[pos] ){
                swap(val[pos],val[ppos]);
                pos = ppos;
                ppos = (pos - 1) / 2;
            }    
            return pos;*/
        }

        int update(int pos, int d){
            val[pos] += d;
            return sift_up(pos);
        }

        void print(){
            for(int i = 0; i < hs; ++i){
                cout << val[i] << " ";
            }
            cout << endl;
        }

};

int main(){

    int n;
    cin >> n;

    heap h(n);
    int x;

    for(int i = 0; i < n; ++i){
        cin >> x;
        h.add(x);
    }

    int m, pos, d;
    cin >> m;

    for(int i = 0; i < m; ++i){
        cin >> pos >> d;
        cout << h.update(pos - 1, d)  + 1 << endl;
    }

    h.print();


    return 0;
}