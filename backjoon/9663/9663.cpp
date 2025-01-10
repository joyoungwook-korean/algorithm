#include <iostream>
using namespace std;

int n;
int result = 0;
bool isused_col[15];
bool isused_dig[30];
bool isused_dig2[30];


void func(int cur){
    if (cur == n ){
        result++;
        return;
    }
    
    for (int i=0; i<n; i++){
        if(!isused_col[i] && !isused_dig[cur+i] && !isused_dig2[cur-i+n] ){
            isused_col[i] = 1;
            isused_dig[cur+i] = 1;
            isused_dig2[cur-i+n]= 1;
            func(cur +1);
            isused_col[i] = 0;
            isused_dig[cur+i] = 0;
            isused_dig2[cur-i+n]= 0;
        }
    }
}

int main(){

    cin >> n;
    func(0);

    cout << result;

    return 0;
    
}