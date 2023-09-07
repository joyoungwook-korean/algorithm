#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int dx[6] = {0, 0, 0, 0, 1, -1};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {1, -1, 0, 0, 0, 0};
    int is_full = 1;
    vector<vector<vector<int>>> box(z, vector<vector<int>>(y, vector<int>(x)));
    queue<pair<int, pair<int, int>>> q;

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    q.push({i, {j, k}});
                }
                else if (box[i][j][k] == 0)
                {
                    is_full = 0;
                }
            }
        }
    }

    if (is_full == 1)
    {
        cout << 0;
        return 0;
    }
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second.first;
        int cz = q.front().second.second;
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nz = cz + dz[i];

            if (nx >= 0 && nx < z && ny >= 0 && ny < y && nz >= 0 && nz < x && box[nx][ny][nz] == 0)
            {
                box[nx][ny][nz] = box[cx][cy][cz] + 1;
                q.push({nx, {ny, nz}});
            }
        }
    }

    int result = -1;
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                if (box[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                result = max(result, box[i][j][k]);
            }
        }
    }
    cout << result - 1;
}