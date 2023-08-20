#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> isChecked;

void dfs(int width, int height) {
    if (width < 0 || width >= v.size() || height < 0 || height >= v[0].size() || isChecked[width][height] == 1 || v[width][height] == 0) {
        return;
    }

    isChecked[width][height] = 1;

    dfs(width+1, height);
    dfs(width-1, height);
    dfs(width, height+1);
    dfs(width, height-1);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;

        v.assign(m, vector<int>(n, 0));
        isChecked.assign(m, vector<int>(n, 0));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            v[x][y] = 1;
        }

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isChecked[i][j] == 0 && v[i][j] == 1) {
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}
