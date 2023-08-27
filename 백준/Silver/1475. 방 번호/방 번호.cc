#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string n;
    cin >> n;
    vector<int> v(10, 0);

    int result = 0;
    for(char& i: n){
        int tmp = i - '0';
        v[tmp] += 1;
    }

    int total69 = v[6] + v[9];
    int required69 = total69 / 2 + (total69 % 2); 
    v[6] = required69;
    v[9] = 0;

    for(int i=0; i<9; i++){
        if (result < v[i]){
            result = v[i];
        }
    }

    cout << result;
}