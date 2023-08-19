#include <iostream>
using namespace std;


int main(){
    int x, y, z;
    while (true){
        cin >> x >> y >> z;
        if (x == 0 && y ==0 && z==0){
            break;
        }

        x = x*x;
        y = y*y;
        z = z*z;

        if (((x+y) == z) || ((x+z) == y) || ((y+z) == x)) {
            cout << "right\n";
        }else{
            cout << "wrong\n";
        }
    }
}
