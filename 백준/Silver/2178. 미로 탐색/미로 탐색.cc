#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    vector<vector<bool>> visited(x, vector<bool>(y, false));
    vector<vector<int>> board;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for(int i=0; i<x; i++){
        vector<int> row;
        for(int j=0; j<y; j++){
            char tmp;
            cin >> tmp;
            row.push_back(tmp - '0');
        }
        board.push_back(row);
    }   

    queue<pair<int,int>> q;
    visited[0][0] = true;
    q.push({0,0});
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= x || ny <0 || ny >= y){
                continue;
            }
            if (board[nx][ny] == 0 ){
                continue;
            }
            if(board[nx][ny] == 1 || board[nx][ny] > board[cur.first][cur.second] + 1){
                board[nx][ny] = board[cur.first][cur.second] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << board[x-1][y-1] << endl;
}