#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<int>> board;
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    queue<pair<int, int>> q;
    bool is_zero = false;
    for(int i = 0; i < y; i++){
        vector<int> row;
        for(int j = 0; j < x; j++){
            int tmp;
            cin >> tmp;
            if (tmp == 0){
                is_zero = true;
            }
            if (tmp == 1){
                q.push({i, j});
                visited[i][j] = true;
            }
            if (tmp == -1){
                visited[i][j] = true;
            }
            row.push_back(tmp);
        }
        board.push_back(row);
    }
    if (!is_zero){
        cout << 0;
        return 0;
    }
    int result = 0;
    while (!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= y || ny < 0 || ny >= x){
                continue;
            }
            if (visited[nx][ny]){
                continue;
            }
            board[nx][ny] = board[cur.first][cur.second] + 1;
            visited[nx][ny] = true;
            if (board[nx][ny] > result){
                result = board[nx][ny];
            }
            q.push({nx, ny});
        }
    }
    result -= 1;
    for (int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if (board[i][j] == 0){
                result = -1;
                break;
            }
        }
        if (result == -1){
            break;
        }
    }
    cout << result;
}
