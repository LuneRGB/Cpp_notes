#include <iostream>
using namespace std;
class TEST{
    int num;
public:
    TEST(int num=0);
    void increment();
    ~TEST();
};
TEST::TEST(int num) : num(num){
    cout << num << endl;
}
void TEST::increment(){
    num++;
}
TEST::~TEST(){
    cout << num << endl;
}
int main(){

    TEST array[1];
    array[0].increment();
    array[1].increment();
    return 0;
}