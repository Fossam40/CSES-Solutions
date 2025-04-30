#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
 
int get_nb_moves(vector<vi>& board, int x, int y){
    int count = 0;
    if(board[y][x]==0){
        vector<pair<int,int>> moveset = {{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
        for(int i = 0; i<8; i++){
            int nx = x + moveset[i].first;
            int ny = y + moveset[i].second;
            if(board[ny][nx]==0) count++;
        }
    }
    return count;
}
 
pi* get_moves(vector<vi>& board, int x, int y, int len){
    pi* moves = (pi*)malloc(sizeof(pi)*len);
    vector<pair<int,pi>> premoves;
    vector<pair<int,int>> moveset = {{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    for(int i = 0; i<8; i++){
        int nx = x + moveset[i].first;
        int ny = y + moveset[i].second;
        premoves.push_back({get_nb_moves(board, nx, ny),{nx,ny}});
    }
    sort(premoves.begin(), premoves.end());
    int curr = 0;
    for(int i = 0; i<8; i++){
        if(board[premoves[i].S.S][premoves[i].S.F]==0){
            moves[curr].F = premoves[i].S.F;
            moves[curr].S = premoves[i].S.S;
            curr++;
        }
    }
    return moves;
}
 
bool backtrack(vector<vi>& board, int x, int y, int curr){
    if(curr== 64) {board[y][x]=64;return true;}
    else{
        int nbmoves = get_nb_moves(board, x, y);
        board[y][x] = curr;
        pi* moves = get_moves(board, x, y, nbmoves);
        int i = 0;
        bool pos = false;
        while(i<nbmoves && !pos){
            pos = backtrack(board, moves[i].F, moves[i].S, curr+1);
            i++;
        }
        if(!pos){
            board[y][x] = 0;
            return pos;
        }
        else return pos;
    }
 
}
 
int main(){
    int x, y;
    cin >> x >> y;x++;y++;
    vector<vi> board(12, vi(12,0));
    for(int i = 0; i<12; i++){
        board[i][0] = 1;
        board[i][1] = 1;
        board[i][10] = 1;
        board[i][11] = 1;
        board[0][i] = 1;
        board[1][i] = 1;
        board[10][i] = 1;
        board[11][i] = 1;
    }
    backtrack(board, x, y, 1);
    for(int i = 2; i<10; i++){
        for(int j = 2; j<10; j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}