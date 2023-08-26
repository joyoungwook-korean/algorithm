#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> copy_tmp;
int n;

int check_width(int width){
    int result = 0;
    int tmp_max = 1;
    char first_char = copy_tmp[width][0];
    for(int i=1; i<n; i++){
        if (copy_tmp[width][i] != first_char){
            first_char = copy_tmp[width][i];
            result = max(result, tmp_max);
            tmp_max = 1;
        }else{
            tmp_max +=1;
            result = max(result, tmp_max);
        }
    }

    return result;
}

int check_height(int height){
    int result = 1;
    int tmp_max = 1;
    char first_char = copy_tmp[0][height];
    for(int i=1; i<n; i++){
        if (copy_tmp[i][height] != first_char){
            first_char = copy_tmp[i][height];
            result = max(result, tmp_max);
            tmp_max = 1;
        }else{
            tmp_max +=1;
            result = max(result, tmp_max);
        }
    }

    return result;
}

int main(){
    cin >> n;
    vector<vector<char>> tmp;

    for(int i=0; i<n; i++){
        vector<char> row;
        for(int j=0; j< n; j++){
            char input_char;
            cin >> input_char;
            row.push_back(input_char);
        }
        tmp.push_back(row);
    }

    int result = 0;
    copy_tmp = tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                swap(copy_tmp[i][j], copy_tmp[i][j + 1]);
                result = max(result, check_width(i));
                result = max(result, check_height(j));
                result = max(result, check_height(j + 1));
                copy_tmp = tmp;
            }
            if (i + 1 < n) {
                swap(copy_tmp[i][j], copy_tmp[i + 1][j]);
                result = max(result, check_width(i));
                result = max(result, check_width(i + 1));
                result = max(result, check_height(j));
                copy_tmp = tmp;
            }
           
        }
    }
    cout << result;
}