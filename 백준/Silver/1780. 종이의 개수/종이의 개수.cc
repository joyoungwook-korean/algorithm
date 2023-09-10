#include <iostream>
#include <vector>
using namespace std;

int count_minus_one = 0;
int count_zero = 0;
int count_one = 0;
vector<vector<int>> board;

void recursion(int x, int y, int size){
    if(size == 1){
        if (board[y][x] == -1){
            count_minus_one++;
        }else if(board[y][x] == 0) {
            count_zero++;
        }else{
            count_one++;
        }
        return;
    }

    int tmp = board[y][x];
    bool tmp_find = false;
    for(int i=y; i<y+size; i++){
        for(int j=x; j<x+size; j++){
            if (tmp != board[i][j]){
                tmp_find =true;
                break;
            }
        }
        if (tmp_find) break;
    }


    if(tmp_find) {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                recursion(x + i * (size / 3), y + j * (size / 3), size / 3);
            }
        }
    }else {
        if (board[y][x] == -1){
            count_minus_one++;
        }else if(board[y][x] == 0) {
            count_zero++;
        }else{
            count_one++;
        }
        return;
    }
}

int main(){
    int n;
    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }
    recursion(0,0,n);
    cout << count_minus_one << "\n";
    cout << count_zero << "\n";
    cout << count_one;
}