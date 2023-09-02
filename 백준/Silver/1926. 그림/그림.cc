#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    vector<vector<bool>> visited(x, vector<bool>(y, false));
    vector<vector<int>> board;
    queue<pair<int, int>> q;
    for(int i=0; i< x; i++){
        vector<int> row;
        for(int j=0; j<y; j++){
            int tmp;
            cin >> tmp;
            row.push_back(tmp);
        }
        board.push_back(row);
    }

    int result = 0;
    int count_result = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(visited[i][j] || board[i][j] != 1){
                continue;
            }
            count_result++;
            q.push({i,j});
            visited[i][j] = true;
            int tmp_result = 0;
            while(!q.empty()){
                pair<int,int> cur = q.front(); 
                q.pop();
                tmp_result++;
                for (int k=0; k<4; k++){
                    int nx = cur.first +dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || nx >= x || ny <0 || ny >= y){
                        continue;
                    }
                    if (visited[nx][ny] || board[nx][ny] == 0 ){
                        continue;
                    }
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
            if (tmp_result > result) {
                result = tmp_result;
            }
        }
    }
    cout << count_result << "\n";
    cout << result;
}