#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int next : v[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main(){
    int n,m;
    cin >> n;
    cin >> m;

    v.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i=0; i < m; i++){
         int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a); 
    }

    dfs(1);

    int result = 0;
    for (const bool& n: visited){
        if (n){
            result +=1;
        }
    }

    cout << result-1;
}