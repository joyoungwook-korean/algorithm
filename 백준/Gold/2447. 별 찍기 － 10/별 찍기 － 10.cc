#include <iostream>
#include <vector>
using namespace std;

void recusion(int n, int start_y, int start_x, vector<vector<char>> &result)
{
    if (n == 1)
        return;
    int size = n / 3;

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            result[start_y + y + size][start_x + x + size] = ' ';
        }
    }

    if (size == 1)
    {
        return;
    }

    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            if (y == 1 && x == 1)
                continue;

            recusion(size, start_y + y * size, start_x + x * size, result);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> result(n, vector<char>(n, '*'));
    cin.ignore();

    recusion(n, 0, 0, result);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cout << result[y][x];
        }
        cout << "\n";
    }

    return 0;
}