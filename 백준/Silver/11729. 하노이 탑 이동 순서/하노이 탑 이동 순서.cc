#include <iostream>
#include <queue>
using namespace std;

void recursion(int start, int end, int n){
    if(n == 1){
        cout << start << " " << end << "\n";
        return ;
    }
    recursion(start, 6-start-end,n-1);
    cout << start << " " << end << "\n";
    recursion(6-start-end, end, n-1);
}

int main(){
    int n;
    cin >>n;
    cout << (1 << n) -1 <<"\n";
    recursion(1, 3, n);
}