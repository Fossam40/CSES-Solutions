#include <bits/stdc++.h>
using namespace std;
//Merci à Nico <3
typedef long long ll;

int backtrack(bool** arr, char* parcours, int line, int col, int visited){
    if((visited == 48)){
        return ((line == 7 && col == 1));
    }
    if(line == 7 && col == 1){
        return 0;
    }
    else{
        int count = 0;
        arr[line][col] = false;
        if(parcours[visited] == '?'){
            if((line != 7) && (line != 1) && (col != 1) && (col != 7)){
                if(arr[line + 1][col]){count += backtrack(arr, parcours, line + 1, col, visited + 1);}
                else if(arr[line][col - 1] && arr[line][col + 1] && !(arr[line-1][col])){
                    arr[line][col] = true;
                    return 0;
                }
                if(arr[line-1][col]){count += backtrack(arr, parcours, line - 1, col, visited + 1);}
                if(arr[line][col+1]){count += backtrack(arr, parcours, line , col + 1, visited + 1);}
                if(arr[line][col-1]){count += backtrack(arr, parcours, line, col - 1, visited + 1);}
                else if(arr[line -1][col] && arr[line + 1][col] && !(arr[line][col+1])){
                    arr[line][col] = true;
                    return 0;
                }
            }
            else {
                if(line == 7){ //L
                    if(arr[line][col + 1]){
                        arr[line][col] = true;
                        return 0;
                    }
                    if(arr[line-1][col]){count += backtrack(arr, parcours, line - 1, col, visited + 1);}
                    if(arr[line][col-1]){count += backtrack(arr, parcours, line, col - 1, visited + 1);}
                }   
                else if(line == 1){ //U
                    if(arr[line][col-1]){
                        arr[line][col] = true;
                        return 0;
                    }
                    if(arr[line + 1][col]){count += backtrack(arr, parcours, line + 1, col, visited + 1);}
                    if(arr[line][col+1]){count += backtrack(arr, parcours, line , col + 1, visited + 1);}
                }
                else if(col == 1){ //R
                    if(arr[line-1][col]){
                        arr[line][col] = true;
                        return 0;
                    }
                    if(arr[line + 1][col]){count += backtrack(arr, parcours, line + 1, col, visited + 1);}
                    if(arr[line][col+1]){count += backtrack(arr, parcours, line , col + 1, visited + 1);}
                }
                else if(col == 7){ //D
                    if(arr[line-1][col]){
                        arr[line][col] = true;
                        return 0;
                    }
                    if(arr[line][col-1]){count += backtrack(arr, parcours, line, col - 1, visited + 1);}
                    if(arr[line + 1][col]){count += backtrack(arr, parcours, line + 1, col, visited + 1);}
                }
            }
        }
        else if((parcours[visited] == 'D')&& (arr[line + 1][col])){
                count += backtrack(arr, parcours, line + 1, col, visited + 1);
            }
        else if( (parcours[visited] == 'U')&& (arr[line - 1][col])){
                count += backtrack(arr, parcours, line - 1, col, visited + 1);
            }
        else if((parcours[visited] == 'R')&& (arr[line][col+1])) {
                count +=  backtrack(arr, parcours, line , col + 1, visited + 1);
            }
        else if((parcours[visited] == 'L') && (arr[line][col-1])){
                count +=  backtrack(arr, parcours, line , col - 1, visited + 1);
            }
        arr[line][col] = true;
        return count;
    }
}

int main(){//
    string parcours;
    cin >>parcours;
    bool** arr = new bool*[9];
    for(int i = 0; i<9; i++){
        arr[i] = new bool [9];
        for(int j = 0; j < 9; j ++){
            arr[i][j] = (i % 8 > 0)&&(j%8 > 0);
        }
    }
    int ans = backtrack(arr, parcours.data(), 1, 1, 0);
    printf("%d\n", ans) ;
}