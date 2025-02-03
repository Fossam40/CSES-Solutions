#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x, y;
    cin >> n;
    vector<pair<int,int>> hor;
    int number = 1;
    for(int i = 0; i<n; i++){
        cin >> x >> y;
        hor.push_back({y,x});
    }
    sort(hor.begin(), hor.end());
    int endc = hor[0].first;
    for(int i = 1; i<n; i++){
        if(hor[i].second >= endc){
            endc = hor[i].first;
            number++;
        }
    }
    cout << number << "\n";
}