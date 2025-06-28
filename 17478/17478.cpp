/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17478                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: siosio0915 <boj.kr/u/siosio0915>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17478                          #+#        #+#      #+#    */
/*   Solved: 2025/06/20 18:44:24 by siosio0915    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;

int n;

void func_back(string s,int now, int end) {
    if (now == -1)
        return;

    if (end == now)
    {
        cout << s << "\"재귀함수가 뭔가요?\"" << "\n";
        cout << s << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << "\n";
    }
    cout << s << "라고 답변하였지." << "\n";
    func_back(s.substr(0, (now-1) * 4), now - 1, end);
    return;
}

void func_front(string s, int now, int end) {
    if (now == end) {
        func_back(s, now, end);
        return;
    }


    cout << s << "\"재귀함수가 뭔가요?\"" << "\n";
    cout << s << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << "\n";
    cout << s << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << "\n";
    cout << s << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << "\n";

    if (now == 0) {
        func_front("____", now + 1, end);
    }else {
        s = s.append("____");
        func_front(s, now + 1, end);
    }
    return;
}

int main() {

    cin >> n;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<< "\n";

    func_front("", 0, n);

    return 0;
}