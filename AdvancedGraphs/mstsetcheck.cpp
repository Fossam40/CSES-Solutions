#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;

vl parents;
vl sizes;

int get_parent(int a){
    if(a == parents[a]) return a;
    else return get_parent(parents[a]);
}

bool join(int a, int b, stack<pair<pl,pl>>& undo){
    int x1 = get_parent(a);
    int x2 = get_parent(b);
    if(x1 != x2){
        if(sizes[x1]< sizes[x2]) swap(x1,x2);
        parents[x2] = x1;
        undo.push({{x2,x1},{sizes[x2], sizes[x1]}});
        sizes[x1] += sizes[x2];
        return true;
    }
    else return false;
}

int main(){
    int n, m, q; cin >> n >> m >> q;
    parents = vl(n);
    sizes = vl(n,1);
    for(int i = 0; i<n; i++) parents[i] = i;
    vector<pair<ll,pl>> edges;
    ll a,b,c;
    for(int i = 0; i<m; i++) {
        cin >>a >> b >> c; a--;b--;
        edges.push_back({c,{a,b}});
    }
    vector<vector<pair<ll,pl>>> sets(q);
    vector<pair<ll,int>> queriesset;
    vector<int> ans(q, 1);
    for(int i = 0; i<q; i++){
        cin >> a;
        for(int j = 0; j<a; j++){
            cin >> b; b--;
            sets[i].push_back(edges[b]);
            queriesset.push_back({edges[b].F, i});
        }
        sort(sets[i].rbegin(), sets[i].rend());
    }
    sort(edges.begin(), edges.end());
    sort(queriesset.begin(), queriesset.end());
    int l = 0; int r = 1;
    int arp = 0;
    int qs = queriesset.size();
    while(l < qs){
        stack<pair<pl,pl>> trash;
        while(edges[arp].F < queriesset[l].F){
            join(edges[arp].S.F, edges[arp].S.S, trash);
            arp++;
        }
        while(queriesset[r].F == queriesset[l].F && r <qs) r++;
        while(l<r){
            // << "Considering weights " << queriesset[l].F << " " << edges[r-1].F << "\n";
            int prevset = queriesset[l].S;
            stack<pair<pl,pl>> undo;
            while(l<r && queriesset[l].S == prevset){
                if(ans[prevset]!= false){
                    int prevset_size = sets[prevset].size()-1;
                    ans[prevset] = join(sets[prevset][prevset_size].S.F, sets[prevset][prevset_size].S.S,undo);
                    //if(ans[prevset]==false) cout << "   - Incorrect fuse "<< sets[prevset][prevset_size].S.F+1 <<"/" <<1+ sets[prevset][prevset_size].S.S << "\n";
                    //else cout << "  - Correct fuse "<< sets[prevset][prevset_size].S.F+1 <<"/" <<1+ sets[prevset][prevset_size].S.S << "\n";
                    sets[prevset].pop_back();
                }
                l++;
            }
            while(!undo.empty()){
                auto curr = undo.top(); undo.pop();
                parents[curr.F.F] = curr.F.F;
                sizes[curr.F.F] = curr.S.F;
                sizes[curr.F.S] = curr.S.S;
            } 
        }
    }
    for(auto a: ans){
        if(a) cout << "YES\n";
        else cout << "NO\n";
    }
}