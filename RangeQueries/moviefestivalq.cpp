#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define S second
#define F first

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n,q; cin >> n >> q;
    vector<pi> mov(n);
    vi time((int)1e6+1,-1);
    for(int i = 0; i<n;i++){
        cin >> mov[i].S >> mov[i].F;
    }
    sort(mov.begin(), mov.end());
    vector<vi> bins(18, vi(n, -1));
    queue<pi> monos;
    for(int i = 0; i<n; i++){
        int cursor = mov[i].S;
        while(cursor>=0 && time[cursor]==-1){
            time[cursor] = i;
            cursor--;
        }
        while(!monos.empty() && monos.front().F <= mov[i].S){
            bins[0][monos.front().S] = i;
            monos.pop();
        }
        monos.push({mov[i].F,i});
    }
    while(!monos.empty()){
        bins[0][monos.front().S] = -1;
        monos.pop();
    }
    for(int i = 1; i<18; i++){
        for(int j = 0; j<n; j++){
            if(bins[i-1][j]!=-1) bins[i][j] = bins[i-1][bins[i-1][j]];
        }
    }
    int startt, endt;
    for(int i = 0; i<q; i++){
        cin >> startt >> endt;
        if(time[startt]==-1) cout << "0\n";
        else{
            int nbmov = (mov[time[startt]].F<=endt);
            for(int i = 17; i>=0;i--){
                while((time[startt] != -1) && (bins[i][time[startt]] != -1) && mov[bins[i][time[startt]]].F<=endt){
                    startt = mov[bins[i][time[startt]]].S;
                    nbmov += (1<<i);
                }
            }
            cout << nbmov << "\n";
        }
    }
}