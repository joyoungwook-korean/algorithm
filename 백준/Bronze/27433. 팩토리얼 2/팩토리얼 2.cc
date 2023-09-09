#include <iostream>
using namespace std;


long long recursion(int i){
    if (i ==0) return 1;
    return i * recursion(i-1);
}

int main(){
    int n;
    cin >> n;
    if (n == 0){
        cout << 1;
        return 0;
    }
    
    cout << recursion(n);
}