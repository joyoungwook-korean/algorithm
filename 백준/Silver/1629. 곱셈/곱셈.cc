#include <iostream>
using namespace std;

long long recursion(long long a, long long b, long long m) {
    if (b == 0) return 1;
    
    long long half = recursion(a, b / 2, m);
    
    if (b % 2 == 0) {
        return (half * half) % m;
    } else {
        return ((half * half) % m * a) % m;
    }
}

int main() {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << recursion(a, b, m);
    return 0;
}
