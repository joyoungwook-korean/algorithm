#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    vector<int> preTotal(n+1, 0);

    for(int i=1; i<=n; i++){
       preTotal[i] = preTotal[i-1] + v[i-1];
    }

    for(int i=0; i<m; i++){
        int start, end;
        scanf("%d %d", &start, &end);
        int result;
        if (end == start) {
            result = v[end-1];
        }else{
            result = preTotal[end] - preTotal[start-1];
        }
        printf("%d\n", result);
    }

}
