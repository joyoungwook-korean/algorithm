#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> board;
string result = "";

void recursion(int x, int y, int size){
    if(size == 1){
        result += to_string(board[y][x]);
        return;
    }

    int tmp = board[y][x];
    bool is_same = true;
    for(int i=y;i<size + y; i++){
        for(int j=x; j<size +x; j++){
            if(board[i][j] != tmp){
                is_same = false;
            }
        }
        if(!is_same) break;
    }

    if(is_same) {
        result += to_string(tmp);
    }else{
        result += '(';
        int new_size = size/2;
        recursion(x,y,new_size);
        recursion(x + new_size, y, new_size);
        recursion(x, y+ new_size, new_size);
        recursion(x +new_size, y+new_size, new_size);
        result += ')';
    }
}

int main(){
    int n;
    cin >> n;
    board.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            char tmp;
            cin >> tmp;
            board[i][j] = tmp-'0';
        }
    }
    recursion(0, 0, n);

    cout << result;
}