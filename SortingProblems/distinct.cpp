#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;;
    int numbers[n];
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    int counter = 1;
    int found = numbers[0];
    for(int i = 1; i<n; i++){
        if(numbers[i] != found){
            counter ++;
            found = numbers[i];
        }
    }
    cout << counter << "\n";
}