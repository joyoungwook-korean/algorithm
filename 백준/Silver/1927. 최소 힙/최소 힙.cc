#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        if (x == 0){
            if(min_heap.empty()){
                cout << 0 << "\n";
            } else{
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }else{
            min_heap.push(x);
        }

    }
}