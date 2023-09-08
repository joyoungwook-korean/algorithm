#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    int minHeight = 101;
    int maxHeight = 0;

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> board[i][j];
            minHeight = min(minHeight, board[i][j]);
            maxHeight = max(maxHeight, board[i][j]);
        }
    }

    int result = 0;
    for(int i=minHeight-1; i<=maxHeight; i++){
        int result_tmp = 0;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int y=0; y<n; y++){
            for (int x=0; x<n; x++){
                if (!visited[y][x] && board[y][x] > i){
                    result_tmp++;
                    q.push({y,x});
                    visited[y][x] = true;

                    while(!q.empty()){
                        int now_y = q.front().first;
                        int now_x = q.front().second;
                        q.pop();

                        for(int k=0; k<4; k++){
                            int nx = now_x + dx[k];
                            int ny = now_y + dy[k];

                            if(nx < 0 || ny <0 || nx >=n || ny >=n) continue;
                            if(visited[ny][nx]) continue;
                            if(board[ny][nx] <= i) continue;

                            q.push({ny, nx});
                            visited[ny][nx] = true;
                        }
                    }
                }
            }
        }
        result = max(result, result_tmp);
    }

    cout << result;

    return 0;
}
