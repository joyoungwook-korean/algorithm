#include <iostream>
using namespace std;

int n, m;
int arr[10];

void func(int start,  int k){
    if (k == m) {
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++){
        arr[k] = i;
        func(i, k + 1);
    }
}

int main(){

    cin >> n >> m;

    func(1, 0);

    return 0;
}