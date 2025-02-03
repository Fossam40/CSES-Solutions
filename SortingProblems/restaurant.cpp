#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n,a,d;
    cin >> n;
    int arrivals[n];
    int departures[n];
    for(int i = 0; i< n; i++){
        cin >> arrivals[i] >> departures[i];
    }
    sort(arrivals, arrivals + n);
    sort(departures, departures + n);

    int current = 0;
    int maximum = 0;
    ll ap = 0;
    ll dp = 0;
    while(ap < n){
        if(arrivals[ap] == departures[dp]){
            while((ap < n) && (arrivals[ap] == departures[dp])){
                ap++;
                dp++;
            }
        }
        if (arrivals[ap] < departures[dp]){
            current++;
            maximum = max(maximum, current);
            ap++;
        }
        else{
            while(departures[dp] <= arrivals[ap]){
                dp++;
                current--;
            }
        }
    }
    cout << maximum << "\n";
}