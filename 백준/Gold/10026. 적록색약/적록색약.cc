#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int y;
    cin >> y;
    vector<vector<char>> board(y, vector<char>(y));
    vector<vector<bool>> visited1(y, vector<bool>(y, false));
    vector<vector<bool>> visited2(y, vector<bool>(y, false));
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            cin >> board[i][j];
        }
    }

    int q1_result = 0;
    int q2_result = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (!visited1[i][j])
            {
                q1.push({i, j});
                visited1[i][j] = true;
                q1_result++;
                while (!q1.empty())
                {
                    pair<int, int> cur1 = q1.front();
                    q1.pop();
                    int x1 = cur1.second;
                    int y1 = cur1.first;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x1 + dx[k];
                        int ny = y1 + dy[k];
                        if (nx < 0 || ny < 0 || nx >= y || ny >= y)
                        {
                            continue;
                        }
                        if (visited1[ny][nx])
                        {
                            continue;
                        }
                        if (board[y1][x1] == board[ny][nx])
                        {
                            visited1[ny][nx] = true;
                            q1.push({ny, nx});
                        }
                    }
                }
            }

            if (!visited2[i][j])
            {
                q2.push({i, j});
                visited2[i][j] = true;
                q2_result++;
                while (!q2.empty())
                {
                    pair<int, int> cur2 = q2.front();
                    q2.pop();
                    int x2 = cur2.second;
                    int y2 = cur2.first;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x2 + dx[k];
                        int ny = y2 + dy[k];
                        if (nx < 0 || ny < 0 || nx >= y || ny >= y)
                        {
                            continue;
                        }
                        if (visited2[ny][nx])
                        {
                            continue;
                        }
                        char now = board[y2][x2];
                        if (now == 'B' && now == board[ny][nx])
                        {
                            visited2[ny][nx] = true;
                            q2.push({ny, nx});
                        }
                        if ((now == 'G' || now == 'R') && (board[ny][nx] == 'G' || board[ny][nx] == 'R'))
                        {
                            visited2[ny][nx] = true;
                            q2.push({ny, nx});
                        }
                    }
                }
            }
        }
    }
    cout << q1_result << " " << q2_result;
}
