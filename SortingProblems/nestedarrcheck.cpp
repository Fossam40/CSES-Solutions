#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;

typedef pair<int,int> pi;
typedef tree<tuple<int,int,int,int>, null_type, less<tuple<int,int,int,int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, f,s;
    cin >> n;
    int contains[n] = {};
    int is_contained[n] = {};
    indexed_set o;
    pi tl[2*n];
    map<pi,int> p_i;
    for(int i = 0; i< n; i++){
        cin >> f >> s;
        tl[2*i].F = f;
        tl[2*i].S = -s;
        tl[2*i + 1].F = s;
        tl[2*i + 1].S = 1e9-f;
        p_i[{f,s}] = i;
    }
    sort(tl, tl + 2*n);
    int closed = 0;
    int size = 0;
    for(int i = 0; i< 2*n; i++){
        if(tl[i].S < 0){
            //cout << "Opening Range [" <<tl[i].F << " , " << -tl[i].S<<"] with closed = " << closed << " and size " <<size<< "\n";
            o.insert({tl[i].F, tl[i].S, closed, size});
            size++;
            
        }
        else{
            tl[i].S = 1e9 - tl[i].S;
            //cout << "Closing Range [" <<tl[i].S << " , " << tl[i].F<<"]\n";
            int j = p_i[{tl[i].S, tl[i].F}];
            //cout << "It was the " << j << "th range !\n";
            auto e = o.lower_bound({tl[i].S,-tl[i].F, 0, 0});
            //cout << o.order_of_key(*e) << " ranges contain ["<< get<0>(*e) <<" , " <<get<1>(*e) << " ]\n";
            is_contained[j] = o.order_of_key(*e);
            //cout << "Since then, we chave closed " << closed -  get<2>((*e)) - (get<3>(*e) - is_contained[j])<< " ranges\n";
            contains[j] = closed - get<2>((*e)) - (get<3>(*e) - is_contained[j]);
            closed++;
            size--;
            o.erase(e);
        }
    }
    for(int i = 0; i< n-1; i++){
        cout << min(1, contains[i]) << " ";
    }
    cout << min(1,contains[n-1]) << "\n";
    for(int i = 0; i< n-1; i++){
        cout << min(1,is_contained[i]) << " ";
    }
    cout << min(1,is_contained[n-1]) << "\n";
}