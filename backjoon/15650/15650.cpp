#include <iostream>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void func(int start, int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++){
        if (!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(i + 1, k + 1);
            isused[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    func(1, 0);
    return 0;
}