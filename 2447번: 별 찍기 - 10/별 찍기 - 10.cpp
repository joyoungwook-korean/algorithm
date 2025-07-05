/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2447                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2447                           #+#        #+#      #+#    */
/*   Solved: 2025/06/29 01:11:06 by siosio0915    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */


#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<char>> v;

void star(int x, int y, int size) {
    if (size == 1) {
        v[x][y] = '*';
        return;
    }

    int newSize = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                for (int a = 0; a < newSize; a++) {
                    for (int b = 0; b < newSize; b++) {
                        v[x + i * newSize + a][y + j * newSize + b] = ' ';
                    }
                }
            } else {
                star(x + i * newSize, y + j * newSize, newSize);
            }
        }
    }
}


int main(){

    cin >> n;
    v.resize(n, vector<char>(n, '*')); 

    star(0, 0, n);

    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << v[x][y];
        }
        cout << "\n";
    }

    return 0;
}