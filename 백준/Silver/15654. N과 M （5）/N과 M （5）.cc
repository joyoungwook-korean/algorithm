#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> tmp;
vector<bool> visited;
void recursion(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=0; i<tmp.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(tmp[i]);
            recursion(k+1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> m;

    tmp.resize(n);
    visited.resize(n, false);

    for(int i =0; i< n; i++){
        cin >> tmp[i];
    }

    sort(tmp.begin(), tmp.end());
    recursion(0);
}