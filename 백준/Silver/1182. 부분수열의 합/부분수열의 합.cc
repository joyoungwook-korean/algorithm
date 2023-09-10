#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int result = 0;

void backTracking(int start, int end, int sum){
    if(sum == m && end >0){
        result++;
    }
    for(int i=start; i<n; i++){
        backTracking(i+1, end+1, sum+v[i]);
    }

}

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    backTracking(0,0,0);
    cout << result;
}