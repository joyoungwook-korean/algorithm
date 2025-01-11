#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int num[10];
int arr[10];

void func(int start, int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int prev = 0;  
    for (int i = start; i < n; i++){
        if (i > start && prev == num[i]){
            continue;
        }
        arr[k] = num[i];
        prev = num[i];
        func(i + 1, k + 1);
    }
}

int main(){

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num + n);

    func(0, 0);

    return 0;
}