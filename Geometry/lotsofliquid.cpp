#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double tot = 0;
    double x;
    while(n--){
        cin >> x;
        tot += x*x*x;
    }
    cout << tot << "\n";
    cout << pow(tot, 1/3) << "\n";
}