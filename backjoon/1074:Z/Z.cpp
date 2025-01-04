/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1074                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1074                           #+#        #+#      #+#    */
/*   Solved: 2025/01/05 01:16:11 by siosio0915    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int recursion (int n, int row, int col){
    if (n==0){
        return 0;
    }

    int half = 1;
    for (int i = 0; i < n - 1; i++)
    {
        half *= 2;
    }

    if (row < half && col < half)
        return recursion(n - 1, row, col);
    if (row <half && col >=half)
        return half * half + recursion(n - 1, row, col - half);
    if (row >= half && col < half)
        return 2 * half * half + recursion(n - 1, row - half, col);
    return 3 * half * half + recursion(n-1, row-half, col-half);
}

int main(){
    int n, row, col;
    cin >> n >> row >> col;

    cout << recursion(n, row, col);

    return 0;
}