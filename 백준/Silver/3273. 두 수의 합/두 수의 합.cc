#include <iostream>
#include <vector>
using namespace std;

int main(){
    int count;
    vector<int> v;
    vector<int> visited(1000001,0);
    cin >> count;
    int result = 0;
    for(int i=0; i<count; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        visited[tmp] = 1;
    }

    int check_num;
    cin >> check_num;

    for(int& i:v){
        int check = check_num -i;
        if (check > 0 &&  check < 1000001 &&visited[check] == 1){
            result += 1;
        }
    }
    cout << result/2;
}