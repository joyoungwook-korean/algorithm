#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    v[0] = 1;
    if (n > 1) {
        v[1] = 3;
    }

    for(int i=2; i<n; i++){
        v[i] = ((v[i-2]*2) + v[i-1]) % 10007;
    }    

    cout << v[n-1] % 10007;
}