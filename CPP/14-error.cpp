#include <iostream>
using namespace std;
class MathErr{
private:
    int data;
public:
    virtual void diagnostic(){}
};
class OverflowErr: public MathErr{

};
class UnderflowErr: public MathErr{

};
class ZerodivideErr: public MathErr{

};

int main(){

try{
    throw UnderflowErr();      // 抛出来的时候是哪个能接到它
} catch (ZerodivideErr &e){
    // 
} catch (UnderflowErr &e) {     //会被基类先接到，派生类接不到。派生类放在上面

} catch (MathErr &e) {

} catch(...) { // catch all handler must be at last
    
}
    return 0;
}