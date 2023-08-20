#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> v;

    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        for (int j=0; j<tmp; j++){
            string a,b;
            cin >> a >> b;
            if (v.count(b)) {
                v[b] += 1;
            }else{
                v[b] = 1;
            }
        }
        int result = 1;
            for (auto& r: v){
               result *= r.second+1;
            }

        cout << result-1 << endl;
        v = {};
    }

}