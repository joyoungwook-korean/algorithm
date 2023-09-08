#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;

    while(n!=0){
        int x,y;
        cin >> x >> y;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        vector<vector<bool>> visited(y, vector<bool>(x, false));   
        vector<vector<char>> board;
        board.clear();
        board.resize(y, vector<char>(x));

        queue<pair<int, int>> fire_q;
        queue<pair<int, int>> people_q;
        bool is_find = false;
        for(int i=0; i<y; i++){
            for(int j=0; j<x; j++){
                cin >> board[i][j];
                if (board[i][j] =='*'){
                    fire_q.push({i, j});
                }
                if (board[i][j] == '@'){
                    if(i == 0 || i==y-1 || j==0 || j==x-1){
                        is_find = true;
                        n--;
                        cout<< "1" << "\n";
                    }
                    visited[i][j] =true;
                    people_q.push({i,j});
                }
            }
        }
        if(is_find) {
            continue;
        }
        int result = 0;
        bool found = false;
        while(!people_q.empty()){
            result++;
            int fire_size = fire_q.size();
            int people_size = people_q.size();

            while(fire_size != 0){
                int now_x = fire_q.front().second;
                int now_y = fire_q.front().first;
                fire_q.pop();
                for(int i=0; i<4; i++){
                    int nx = dx[i] + now_x;
                    int ny = dy[i] + now_y;

                    if(nx < 0 || ny < 0 || nx >= x || ny >= y || board[ny][nx] =='#' || board[ny][nx] =='*'){
                        continue;
                    }
                    board[ny][nx] = '*';
                    fire_q.push({ny,nx});
                }
                fire_size--;
            }

            while(people_size != 0){
                int now_x = people_q.front().second;
                int now_y = people_q.front().first;
                people_q.pop();
                for(int i=0; i<4; i++){
                    int nx = dx[i] + now_x;
                    int ny = dy[i] + now_y;

                    if(nx < 0 || ny < 0 || nx >= x || ny >= y || board[ny][nx] == '*' || board[ny][nx] == '#' || visited[ny][nx]){
                        continue;
                    }
                    if(nx == x-1 || ny == y-1 || nx==0 || ny==0){
                        found = true;
                        cout << result+1 << "\n";
                        break;
                    }
                    visited[ny][nx] = true;
                    people_q.push({ny,nx});
                }
                if (found){
                    break;
                }
                people_size--;
            }

            if(found){
                break;
            }
        }
        if(!found){
            cout << "IMPOSSIBLE"<< "\n";
        }
        n--;
    }
}