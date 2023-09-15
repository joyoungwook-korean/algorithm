#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> arr;

void recursion(int k, int start){
    if(k == m){
        for(int i=0; i<m; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev =-1;
    for(int i=start; i<arr.size(); i++){
        if (prev != arr[i]){
            v.push_back(arr[i]);
            prev = arr[i];
            recursion(k+1, i+1);
            v.pop_back();
        }
        
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