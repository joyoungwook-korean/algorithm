#include <iostream>
#include <vector>
using namespace std;

void recusion(vector<vector<int>> &table, int now_cut, int start_y, int start_x, vector<int> &result)
{
    int now = table[start_y][start_x];
    if (now_cut == 1)
    {
        result[now] += 1;
        return;
    }

    int half = now_cut / 2;

    for (int y = start_y; y < start_y + now_cut; y++)
    {
        for (int x = start_x; x < start_x + now_cut; x++)
        {
            if (table[y][x] != now)
            {
                for (int cut_y = start_y; cut_y < start_y + now_cut; cut_y += half)
                {
                    for (int cut_x = start_x; cut_x < start_x + now_cut; cut_x += half)
                    {
                        recusion(table, half, cut_y, cut_x, result);
                    }
                }
                return;
            }
        }
    }
    result[now] += 1;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> table(n, vector<int>(n, 0));
    vector<int> result(2, 0);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cin >> table[y][x];
        }
    }

    recusion(table, n, 0, 0, result);

    cout << result[0] << "\n";
    cout << result[1] << "\n";

    return 0;
}