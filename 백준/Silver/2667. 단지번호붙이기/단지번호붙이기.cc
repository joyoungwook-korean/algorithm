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
    vector<vector<int>> board(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    vector<int> result;
    for(int i=0; i<n; i++){
        string line;
        cin >> line;
        for(int j=0; j<n; j++){
            board[i][j] = (line[j] - '0');
            if (board[i][j] == 0){
                visited[i][j] =true;
            } 
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j] && board[i][j] ==1){
                q.push({i, j});
                visited[i][j] = true;
                int tmp_result = 1;
                while(!q.empty()){
                    int now_y = q.front().first;
                    int now_x = q.front().second;
                    q.pop();

                    for(int k =0; k<4; k++){
                        int ny = now_y + dy[k];
                        int nx = now_x + dx[k];

                        if(nx <0 || ny <0 || nx >=n || ny >= n || visited[ny][nx] || board[ny][nx] == 0){
                            continue;
                        }
                        q.push({ny, nx});
                        visited[ny][nx] = true;
                        tmp_result++;
                    }
                }
                result.push_back(tmp_result);
            }
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";

    for(auto &r: result){
        cout << r << "\n";
    }

}