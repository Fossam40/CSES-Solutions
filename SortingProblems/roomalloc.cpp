#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
typedef pair<int,int> pi;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    tuple<int,int,int> tab[n];
    int x,y;
    vector<int> a(n);
    for(int i = 0; i< n; i++){
        cin >> x >> y;
        tab[i] = {y,x,i};
    }
    sort(tab, tab + n);
    multiset<pi> r;
    int rooms = 0;
    for(int i = 0; i< n; i++){
        auto it = r.lower_bound({get<1>(tab[i]), 0});
        if(it == r.begin()){
            rooms++;
            r.insert({get<0>(tab[i]), rooms});
            a[get<2>(tab[i])] = rooms;
        }
        else{
            it--;
            int ra = (*it).S;
            a[get<2>(tab[i])] = ra;
            r.erase(it);
            r.insert({get<0>(tab[i]), ra});
        }
    }
    cout << rooms << "\n";
    for(auto i: a){
        cout << i << " ";
    }
}