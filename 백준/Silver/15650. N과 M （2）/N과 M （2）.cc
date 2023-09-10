#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> arr;
int visited[9];

void recursion(int k,int start){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i =start; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            arr.push_back(i);
            recursion(k+1, i);
            visited[i] = false;
            arr.pop_back();
        }
    }
}

int main(){
    cin >> n >> m;
    recursion(0, 1);
}