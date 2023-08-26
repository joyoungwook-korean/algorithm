#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
     ios_base::sync_with_stdio(false); 

    int e, s, m;
    cin >> e >> s >> m;

    int E = 1, S = 1, M = 1;
    int result = 1;

    while (E != e || S != s || M != m) {
        E++; S++; M++;
        if (E > 15) E = 1;
        if (S > 28) S = 1;
        if (M > 19) M = 1;
        result++;
    }

    cout << result;
    return 0;
}