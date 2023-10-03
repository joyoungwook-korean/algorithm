#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> visited;
vector<int> arr;
int n, m;


void recursion(int k, int start){
    if (k == 6){
        for(int i=0; i<k; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i=start; i<arr.size(); i++){
        if (!visited[i]){
            visited[i] = true;
            v.push_back(arr[i]);
            recursion(k+1, i);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    while(true){
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        visited.resize(n, false);
        for (int i=0; i<n; i++){
            int a;
            cin >> a;
            arr.push_back(a);
        }

        sort(arr.begin(), arr.end());
        recursion(0, 0);
        visited.clear();
        arr.clear();
        cout << "\n";
    }
}