#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++){
        if (!isused[i]){
            isused[i] = 1;
            arr[k] = num[i];
            func(k + 1);
            isused[i] = 0;
        }
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    sort(num, num+n);

    func(0);

    return 0;
}