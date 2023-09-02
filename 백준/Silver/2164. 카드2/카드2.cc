#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    queue<int> queue;

    for (int i = 0; i < n; i++)
    {
        queue.push(i + 1);
    }

    while (queue.size() != 1)
    {
        queue.pop();
        int tmp = queue.front();
        queue.pop();
        queue.push(tmp);
    }

    cout << queue.front();
}
