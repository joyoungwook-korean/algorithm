#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> arr;
vector<bool> visited;

void recursion(int k){
    if (k == m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for(int i=0; i<arr.size(); i++){
        if(!visited[i] && (prev == -1 || prev != arr[i])){
            visited[i] = true;
            v.push_back(arr[i]);
            recursion(k+1);
            v.pop_back();
            visited[i] = false;
            prev = arr[i];
        }
    }
}

int main(){
    cin >> n >> m;
    arr.resize(n);
    visited.resize(n, false);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    recursion(0);
}
