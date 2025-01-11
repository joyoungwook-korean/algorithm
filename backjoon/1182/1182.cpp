#include <iostream>
using namespace std;

int n, s;
int arr[20];
int result = 0;

void func(int sum, int now, int cnt){ 
    if(now == n){
        if(sum == s && cnt > 0){ 
            result++;
        }
        return;
    }

    func(sum + arr[now], now+1, cnt+1);  
    func(sum, now+1, cnt);           
}

int main(){
    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    func(0, 0, 0);
    cout << result;
    return 0;
}