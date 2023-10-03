#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<int> arr;
int n, m;

void recursion(int k, int start){
    if (k == m) {
        for (int i=0; i<m; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=start; i<arr.size(); i++){
        if (!v.empty()){
            if(v.back() > arr[i]){
                continue;
            }
        }
        v.push_back(arr[i]);
        recursion(k+1, i);
        v.pop_back();    
    }
}

int main(){
    cin >> n >> m;
 
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(),arr.end()), arr.end());

    recursion(0,0);
}