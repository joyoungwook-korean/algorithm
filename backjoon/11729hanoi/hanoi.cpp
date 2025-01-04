/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11729                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11729                          #+#        #+#      #+#    */
/*   Solved: 2025/01/05 00:01:21 by siosio0915    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

void POW(int start, int end, int count){
    if (count == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    POW(start, 6 - start - end, count - 1);
    cout << start << " " << end << "\n";
    POW(6 - start - end, end, count - 1);
}

int main(){
    int n;
    cin >> n;

    cout << (1 << n) - 1 << "\n";
    POW(1, 3, n);
}