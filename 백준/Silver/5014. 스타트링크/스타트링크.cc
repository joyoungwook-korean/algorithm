#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int max_stair, now, want, up, down;
    cin >> max_stair >> now >> want >> up >> down;
    vector<int> v;
    vector<bool> visited(max_stair + 1, false);
    queue<pair<int, int>> q;
    int up_down[2] = {up, down*-1};
    q.push({now,0});
    visited[now] = true;

    while(!q.empty()){
        int now_tmp = q.front().first;
        int now_dist = q.front().second;
        q.pop();

        if(now_tmp == want){
            cout << now_dist;
            return 0;
        }

        for(int i=0; i<2; i++){
            int nx = now_tmp + up_down[i];
            if(nx <1 || nx > max_stair || visited[nx]){
                continue;
            }
            q.push({nx, now_dist+1});
            visited[nx] = true;
        }
    }
    cout << "use the stairs";
}