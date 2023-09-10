#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;


void recursion(int k){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=n; i++){
        v.push_back(i);
        recursion(k+1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    recursion(0);
}