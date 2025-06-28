
#include <iostream>
#include <deque>
using namespace std;
deque<int> v;

int main(){
    int n, m;
    cin >> n >> m;
    char ch;
    while (cin >> ch)
    {
        int num = static_cast<int>(ch);
        if (v.empty()){
            v.push_front(num);
            continue;
        }
        if (num <v.front()){
            v.push_front(num);
            continue;
        }

        bool inserted = false;
        for (int i = 0; i < v.size(); i++) {
            if (num < v[i]) {
                v.insert(v.begin() + i, num);
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            v.push_back(num);
        }
    }

    cout << v[0];
}