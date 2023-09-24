#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
int n, m;

void recursion(int k){
    if (k == m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for(int i=0; i<n; i++){
        if (prev == arr[i]) continue;
        prev = arr[i];
        v.push_back(arr[i]);
        recursion(k+1);
        v.pop_back();
    }
}

int main(){
    cin >> n >> m;
    arr.resize(n, 0);

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    recursion(0);
}
