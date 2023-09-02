#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> v(20005, 0);
    int mx = v.size()/2 +1;
    int head = mx;
    int tail = mx;


    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        if (tmp == "push_back"){
            int pushInt;
            cin >> pushInt;
            v[tail] = pushInt;
            tail++;
        }else if(tmp =="push_front"){
            int pushInt;
            cin >> pushInt;
            head--;
            v[head] = pushInt;
        }else if(tmp == "pop_front"){
            if (tail -1 < head){
                cout << "-1" << "\n";
            }else{
                cout << v[head] << "\n";
                head++;
            }
        }else if(tmp == "pop_back"){
            if (tail -1 < head){
                cout << "-1" << "\n";
            }else{
                cout << v[tail-1] << "\n";
                tail--;
            }
        }else if(tmp == "size"){
            cout << ((tail) - head) << "\n";
        }else if(tmp == "empty"){
            if (tail -1 < head){
                cout << 1 <<"\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(tmp == "front"){
            if (tail -1 < head){
                cout << "-1" << "\n";
            }else{
                cout << v[head] << "\n";
            }
        }else{
             if (tail -1 < head){
                cout << "-1" << "\n";
            }else{
                cout << v[tail-1] << "\n";
            }
        }
    }
}