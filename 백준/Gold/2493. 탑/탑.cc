#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> tower(N);
    for(int i = 0; i < N; i++) {
        cin >> tower[i];
    }

    stack<pair<int, int>> st; 
    vector<int> result;

    for(int i = 0; i < N; i++) {
        while(!st.empty() && st.top().first <= tower[i]) {
            st.pop();
        }
        if(st.empty()) {
            result.push_back(0);
        } else {
            result.push_back(st.top().second + 1);
        }
        st.push({tower[i], i});
    }

    for(int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
