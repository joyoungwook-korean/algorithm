#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(11, 0);

    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for(int i =4; i<11; i++){
        v[i] = v[i-1] + v[i-2] + v[i-3];
    }

    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        cout << v[m] << endl;
    }
}