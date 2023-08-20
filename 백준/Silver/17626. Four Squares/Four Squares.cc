#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

bool check(int num, int k) {
    if (k==1) {
        for(int tmp: v){
            if (tmp == num) {
                return true;
            }
        }
        return false;
    }
    for (int tmp:v){
        if (tmp < num && check(num-tmp, k-1)){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    int count = 0;
    while(true){
        count += 1;
        int tmp = count* count;
        if (n >= tmp){
            v.push_back(tmp);
        }else{
            break;
        }
    }

    for(int i =1; i<=4; i++){
        if (check(n, i)){
            cout << i;
            return 0;
        }
    }
}