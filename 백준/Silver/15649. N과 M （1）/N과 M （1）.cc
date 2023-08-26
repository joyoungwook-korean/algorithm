#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;
bool visited[9]; 

void dfs(int cnt) {
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            arr.push_back(i);
            dfs(cnt + 1);
            visited[i] = false;
            arr.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
    return 0;
}
