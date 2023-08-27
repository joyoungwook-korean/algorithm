#include <iostream>
#include <vector>
using namespace std;

int main(){
    string input_string;
    cin >> input_string;

    vector<int> v(26, 0);

    for(char& i: input_string){
        int tmp = i;
        v[tmp-97] += 1;
    }

    for(int& i: v){
        cout << i << " ";
    }
}