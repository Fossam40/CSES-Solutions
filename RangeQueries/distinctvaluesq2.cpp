#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000001
typedef pair<int,int> pi;
#define S second
#define F first
const int N = 200001;
int n;
int t[2*N];

void build(){
    for(int i = n-1; i>0; i--) t[i] = min(t[i<<1], t[(i<<1)|1]);
}

void update(int a, int v){
    for(t[a+=n]=v; a>1; a/=2) t[a>>1] = min(t[a], t[a^1]);
}

int query(int l,int r){
    int ans = MAX;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) ans = min(ans,t[l++]);
        if(r&1) ans = min(ans, t[--r]);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    for(int i = 0; i<2*n; i++) t[i] = MAX;
    set<pi> elts;
    vector<int> arr(n);
    int ty, a, b;
    for(int i = 0; i<n; i++){
        cin >> a;
        arr[i] = a;
        elts.insert({a,i});
    }
    auto it = elts.begin();
    for(auto nit = ++elts.begin(); nit != elts.end(); it++, nit++){
        if((*nit).F == (*it).F){
            update((*it).S, (*nit).S);
        }
    }
    for(int i = 0; i<q; i++){
        cin >> ty >> a >> b;
        if(ty==2){
            if(query(--a,b)>=b) cout << "YES\n";
            else cout << "NO\n";
        }
        else{
            auto celt = (elts.find({arr[a-1], a-1}));
            auto nelt = celt; nelt++;
            if(celt != elts.begin()){
                auto pelt = celt; pelt--;
                if(nelt != elts.end() && (*nelt).F==(*pelt).F){
                    update((*pelt).S, (*nelt).S);
                }
                else{
                    update((*pelt).S, MAX);
                }
            }
            elts.erase(celt);
            arr[a-1] = b;
            elts.insert({arr[a-1],a-1});
            auto pelt = (elts.find({arr[a-1], a-1}));
            nelt = pelt; nelt++;
            if(nelt != elts.end() && (*nelt).F==(*pelt).F){
                update(a-1, (*nelt).S);
            }
            else{
                update(a-1, MAX);
            }
            if(pelt != elts.begin()){
                nelt--; pelt--;
                if(nelt != elts.end() && (*nelt).F==(*pelt).F){
                    update((*pelt).S, (*nelt).S);
                }
            }

        }
    }
}

