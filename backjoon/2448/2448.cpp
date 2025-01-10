#include <iostream>
#include <vector>
using namespace std;

void recusion(vector<vector<char>> &table, int now_num, int start_y, int start_x, int target_num){
    if (now_num == 3) {
        table[start_y][start_x] = '*';
        table[start_y + 1][start_x - 1] = '*';
        table[start_y + 1][start_x + 1] = '*';
        for (int i = start_x - 2; i <= start_x + 2; i++) {
            table[start_y + 2][i] = '*';
        }
        return;
    }

    int next_height = now_num / 2;
    
    recusion(table, next_height, start_y, start_x, target_num);
    recusion(table, next_height, start_y + next_height, start_x - next_height, target_num);
    recusion(table, next_height, start_y + next_height, start_x + next_height, target_num);
}

int main(){
    int n;
    cin >> n;
    int width = 2 * n - 1;
    vector<vector<char>> table(n, vector<char>(width, ' '));

    recusion(table, n, 0, n-1, n);

    for (int y = 0; y < n; y++){
        for (int x = 0; x < width; x++) {
            cout << table[y][x];
        }
        cout << "\n";
    }
    return 0;
}