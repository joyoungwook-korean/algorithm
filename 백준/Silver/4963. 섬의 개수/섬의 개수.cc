#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector<int> result;
    while (true)
    {
        int x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            break;
        }
        vector<vector<bool>> visited;
        vector<vector<int>> board;
        visited.clear();
        board.clear();
        visited.assign(y, vector<bool>(x, false));
        int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
        int dy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

        for (int i = 0; i < y; i++)
        {
            vector<int> row;
            for (int j = 0; j < x; j++)
            {
                int tmp;
                cin >> tmp;
                row.push_back(tmp);
            }
            board.push_back(row);
        }

        queue<pair<int, int>> q;
        int result_tmp = 0;
        for (int i = 0; i < y; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (!visited[i][j] && board[i][j] == 1)
                {
                    result_tmp += 1;
                    q.push({i, j});
                }
                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = cur.second + dx[k];
                        int ny = cur.first + dy[k];
                        if (nx < 0 || ny < 0 || nx >= x || ny >= y)
                        {
                            continue;
                        }
                        if (visited[ny][nx] || board[ny][nx] != 1)
                        {
                            continue;
                        }
                        visited[ny][nx] = true;
                        q.push({ny, nx});
                    }
                }
            }
        }
        result.push_back(result_tmp);
    }
    for (auto &a : result)
    {
        cout << a << "\n";
    }
}