#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int x, y ,n;
    cin >> y >> x >> n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    vector<vector<int>> board(y, vector<int>(x, 0));
    queue<pair<int,int>> q;
    vector<int> result;
    while(n != 0){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for(int i=y1; i<y2; i++){
            for(int j=x1; j<x2; j++){
                board[i][j] = 1;
                visited[i][j] = true;
            }
        }
        n--;
    }

    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            if(!visited[i][j] && board[i][j] != 1){
                int tmp_result = 1;
                q.push({i,j});
                visited[i][j] = true;
                
                while(!q.empty()){
                    int now_y = q.front().first;
                    int now_x = q.front().second;
                    q.pop();

                    for(int k=0; k<4; k++){
                        int nx = now_x + dx[k];
                        int ny = now_y + dy[k];

                        if(nx<0 || ny <0 || nx>=x || ny>=y || visited[ny][nx] || board[ny][nx] == 1){
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
    for(auto &i: result){
        cout << i << " ";
    }
}