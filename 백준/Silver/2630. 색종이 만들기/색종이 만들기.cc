#include <iostream>
#include <vector>
using namespace std;

int white=0;
int blue=0;
vector<vector<int>> vec;

void recursion(int x, int y, int num) {
    int now_color = vec[x][y];
    bool same = true;

    for(int i=x; i<x+num && same; i++){
        for(int j=y; j<y+num; j++){
            if (vec[i][j] != now_color){
                same = false;
                break;
            }
        }
    }
    if (same){
        if (now_color == 0){
            white += 1;
        }else{
            blue += 1;
        }
    }else{
        int half = num / 2;
        recursion(x, y, half);
        recursion(x+half, y, half);
        recursion(x,y+half, half);
        recursion(x+half, y+half, half);
    }
}

int main(){
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        vector<int> row;
        for (int j=0; j<n; j++){
            int input_num;
            cin >> input_num;
            row.push_back(input_num);
        }
        vec.push_back(row);
    }

    recursion(0,0,n);

    cout << white << "\n";
    cout << blue;
}