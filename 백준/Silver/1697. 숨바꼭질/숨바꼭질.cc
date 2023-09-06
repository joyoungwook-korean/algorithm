#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, finish;
    cin >> n >> finish;
    vector<bool> visited(100001, false);
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == finish)
        {
            cout << cur.second;
            break;
        }
        if (visited[cur.first] || cur.first < 0 || cur.first > 100000)
        {
            continue;
        }
        visited[cur.first] = true;
        int nowPlus = cur.first + 1;
        int nowMinus = cur.first - 1;
        int nowDouble = cur.first * 2;
        q.push({nowPlus, cur.second + 1});
        q.push({nowMinus, cur.second + 1});
        q.push({nowDouble, cur.second + 1});
    }
}