#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v;
vector<int> arr;

void recursion(int k, int start){
    if(k==m){
        for(int i=0; i<m; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=start; i<n; i++){
        v.push_back(arr[i]);
        recursion(k+1, i);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    arr.resize(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    recursion(0,0);
}