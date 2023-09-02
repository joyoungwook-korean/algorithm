#include <iostream>
#include <deque>
using namespace std;
deque<int> deq;

int main(){
    int n, count; 
    cin >> n >> count;

    for(int i=0; i<n; i++){
        deq.push_back(i+1);
    }

    int result = 0;
    for(int i=0; i<count; i++){
        int num;
        cin >> num;
        int index = 0;
        for (int i = 0; i < deq.size(); i++) {
            if (deq[i] == num) {
                index = i;
                break;
            }
        }

        int left = index;
        int right = deq.size() - index - 1;
        if (left <= right) {
            while (deq.front() != num) {
                int front = deq.front();
                deq.pop_front();
                deq.push_back(front);
                result++;
            }
        } else {
            while (deq.front() != num) {
                int back = deq.back();
                deq.pop_back();
                deq.push_front(back);
                result++;
            }
        }
        deq.pop_front();
    }
    cout << result;
}