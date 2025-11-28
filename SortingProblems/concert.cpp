#include <bits/stdc++.h>

using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    int tickets[n];
    for(int i = 0; i<n; i++){
        cin >> tickets[i];
    }
    sort(tickets, tickets + n);
    int* dispo[n];
    for(int i = 0; i<n; i++){
        dispo[i] = NULL;
    }
    int x;
    int search = 0;
    for(int i = 0; i<m; i++){
        cin >> x;
        search = 0;
        for(int b = n/2; b >= 1; b /= 2) {
            while((b+ search < n)&& (tickets[b+search] <= x)) {
                search+=b;
                }
        }
        while(search >= 0 && dispo[search] != NULL){
            if(*(dispo[search]) >= 0 && dispo[*(dispo[search])] != NULL){
                *(dispo[search]) = *(dispo[*(dispo[search])]);            
            }
            search = *(dispo[search]);
        }
        if(search >=0 && (tickets[search] <= x)){
            if(search > 0 && (dispo[search-1] != NULL)){
                if(search < (n-1) && (dispo[search + 1] != NULL)){
                    *(dispo[search + 1]) = *(dispo[search - 1]);
                }
                dispo[search] = dispo[search - 1];
            }
            else if((search < (n-1) && (dispo[search + 1] != NULL))){
                dispo[search] = dispo[search + 1];
                *(dispo[search]) = search - 1;
            }
            else {
                dispo[search] = new int;
                *(dispo[search]) = search - 1;
            }
            cout << tickets[search] << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    

}