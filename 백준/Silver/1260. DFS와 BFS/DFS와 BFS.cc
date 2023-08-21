#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<bool> isChecked;

void dfs(int num, vector<bool> &cloneChecked)
{
    if (cloneChecked[num])
        return;

    cloneChecked[num] = true;
    cout << num;
    sort(v[num].begin(), v[num].end());

    for (int i = 0; i < v[num].size(); i++)
    {
        int nextValue = v[num][i];
        if (!cloneChecked[nextValue])
        {
            cout << " ";
            dfs(nextValue, cloneChecked);
        }
    }
}

void bfs(int num, vector<bool> &cloneChecked)
{
    queue<int> q;
    q.push(num);
    cloneChecked[num] = true;

    cout << num;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        sort(v[current].begin(), v[current].end());

        for (int i = 0; i < v[current].size(); i++)
        {
            int nextValue = v[current][i];
            if (!cloneChecked[nextValue])
            {
                cout << " " << nextValue;
                q.push(nextValue);
                cloneChecked[nextValue] = true;
            }
        }
    }
}

int main()
{
    int m, count, start;
    cin >> m >> count >> start;

    vector<int> v1;
    v.resize(m + 1, v1);
    isChecked.resize(m + 1, false);

    for (int i = 0; i < count; i++)
    {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
        v[tmp1].push_back(tmp);
    }

    for (int i = 1; i <= m; i++)
    {
        sort(v[i].begin(), v[i].end());
    }

    dfs(start, isChecked);
    cout << "\n";

    fill(isChecked.begin(), isChecked.end(), false);

    bfs(start, isChecked);
}
