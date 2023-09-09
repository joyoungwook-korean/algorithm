#include <iostream>
#include <vector>
#include <string>
using namespace std;

int result = 0;

int recursion(const string& s, int start, int end){
    result++;
    if (s[start] != s[end]) return 0;
    if (start >= end) return 1;
    return recursion(s, start+1, end-1);
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    for (int i=0; i<n; i++){
        result = 0;
        string tmp;
        getline(cin, tmp);
        cout << recursion(tmp,0,tmp.size()-1) << " " << result << "\n";
    }
}