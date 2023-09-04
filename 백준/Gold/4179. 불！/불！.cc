#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int x, y;
    cin >> y >> x;
    vector<vector<bool>> visited(y, vector<bool>(x, false));
    vector<vector<char>> board;
    queue<pair<int, int>> jQ, fQ;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < y; i++)
    {
        vector<char> row;
        for (int j = 0; j < x; j++)
        {
            char tmp;
            cin >> tmp;
            row.push_back(tmp);
            if (tmp == 'J')
            {
                jQ.push({i, j});
                visited[i][j] = true;
            }
            if (tmp == 'F')
            {
                fQ.push({i, j});
            }
        }
        board.push_back(row);
    }

    int result = 0;
    while (!jQ.empty())
    {
        int jq_size = jQ.size();
        int fq_size = fQ.size();
        for (int i = 0; i < fq_size; i++)
        {
            int cur_x = fQ.front().second;
            int cur_y = fQ.front().first;
            fQ.pop();

            for (int j = 0; j < 4; j++)
            {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (nx < 0 || ny < 0 || nx >= x || ny >= y)
                    continue;
                if (board[ny][nx] == '#' || board[ny][nx] == 'F')
                    continue;

                board[ny][nx] = 'F';
                fQ.push({ny, nx});
            }
        }
        for (int i = 0; i < jq_size; i++)
        {
            int cur_x = jQ.front().second;
            int cur_y = jQ.front().first;
            jQ.pop();

            if (cur_x == 0 || cur_y == 0 || cur_x == x - 1 || cur_y == y - 1)
            {
                cout << result + 1;
                return 0;
            }

            for (int j = 0; j < 4; j++)
            {
                int nx = cur_x + dx[j];
                int ny = cur_y + dy[j];

                if (nx < 0 || ny < 0 || nx >= x || ny >= y)
                    continue;
                if (visited[ny][nx] || board[ny][nx] != '.')
                    continue;

                visited[ny][nx] = true;
                jQ.push({ny, nx});
            }
        }
        result++;
    }

    cout << "IMPOSSIBLE";
}