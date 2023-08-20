#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<long long> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    v.push_back(9);

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        long long result = 0;
        if (tmp < 11) {
            result = v[tmp-1];
        }else{
            vector<long long> cloneV(v);
            for(int j=10; j<tmp; j++){
                cloneV.push_back(cloneV[j-1] + cloneV[j-5]);
            }
            result = cloneV[tmp-1];
        }
        cout << result << endl;
    }
}