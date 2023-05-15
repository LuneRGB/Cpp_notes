#include <iostream>
using namespace std;

/* 相当于在调用端帮忙添加参数 */
void foo(int i, int j = 2){
    cout << i << " " << j << endl;
}



int main(){


    foo(2);


}