#include <bits/stdc++.h> 
using namespace std;
map<pair<int,int>, int> memo;

struct
    {
        bool operator()(int a, int b) const { 
            if(memo[{a,b}] != 0) {
                return (memo[{a,b}]-1);
            }
            else{
                cout << "? " << a << " " << b << "\n";
                cout << flush;
                string ans;
                cin >> ans;
                bool res = (ans[0]=='Y');
                memo[{a,b}] = res+1;
                return res;
            }
        }
    }
    customLess;

vector<int>& mergesort(vector<int> & arr){
    if(arr.size()==1){
        return arr; 
    }
    else{
        vector<int> arr1(arr.size()/2);
        vector<int> arr2(arr.size() - (arr.size()/2));
        for(int i = 0; i<arr.size()/2; i++){
            arr1[i] = arr[i];
        }
        for(int i = arr.size()/2; i<arr.size(); i++){
            arr2[i-(arr.size()/2)] = arr[i];
        }
        mergesort(arr1);
        mergesort(arr2);
        int a1 = 0;
        int a2 = 0;
        while(a1 < (arr.size()/2) && a2 < (arr.size() - (arr.size()/2))){
            if(customLess(arr1[a1],arr2[a2])){
                arr[a1 + a2] = arr1[a1];
                a1++;
            }
            else {arr[a1 + a2] = arr2[a2];a2++;}
        }
        while(a1 < (arr.size()/2)){
            arr[a1 + a2] = arr1[a1];
            a1++;
        }
        while(a2 < (arr.size()-(arr.size()/2))){
            arr[a1 + a2] = arr2[a2];
            a2++;
        }
        return arr;
    }
}
int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) arr[i] = i+1;
    mergesort(arr);
    vector<int> realarr(n);
    for(int i = 0; i<n; i++){
        realarr[arr[i]-1] = i+1;
    }
    cout << "! ";
    for(auto u: realarr) cout << u << " ";
    cout << "\n";
}