#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> v;

    for (int i=0; i < n; i++){
        vector<int> row(i+1);
        for (int j=0; j <=i; j++){
            cin >> row[j];
        }
        v.push_back(row);
    }

    vector<vector<int>> cloneVertor(v);
    for (int i=0; i<v.size()-1; i++){
        for(int j=0; j<v[i].size(); j++){
            int now = v[i][j];
            int tmp = now + cloneVertor[i+1][j];
            int tmp1 = now + cloneVertor[i+1][j+1];
             if (v[i+1][j] < tmp){
                v[i+1][j] = tmp;
            }
            if (v[i+1][j+1] < tmp1){
                 v[i+1][j+1] = tmp1;
             }
        }
    }
    int result = 0;
    for (const int& i: v[n-1]){
        if (i >= result){
            result = i;
        }
    }
    cout << result;
}
