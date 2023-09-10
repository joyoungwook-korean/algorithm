#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> visited;
vector<int> v;

void recursion(int k,int start){
    if (k==m){
        for (int i=0; i<m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<=n; i++){
        v.push_back(i);
        recursion(k+1, i);
        v.pop_back();
    }

}

int main(){
    cin >> n >> m;
    recursion(0,1);
}