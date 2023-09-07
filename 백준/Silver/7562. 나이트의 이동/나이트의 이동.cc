#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int l, pair<int, int> start, pair<int, int> end)
{
    vector<vector<bool>> visited(l, vector<bool>(l, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (x == end.first && y == end.second)
        {
            return dist;
        }

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < l && ny < l && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({{nx, ny}, dist + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int l;
        cin >> l;

        pair<int, int> start, end;
        cin >> start.first >> start.second;
        cin >> end.first >> end.second;

        cout << bfs(l, start, end) << '\n';
    }
    return 0;
}
