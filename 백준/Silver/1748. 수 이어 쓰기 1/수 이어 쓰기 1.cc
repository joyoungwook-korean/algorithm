#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long result = 0;
    for (long long i = 1, len = 1; i <= n; i *= 10, len++) {
        long long end = i * 10 - 1;
        if (end > n) {
            end = n;
        }
        result += (end - i + 1) * len;
    }

    cout << result;
    return 0;
}
