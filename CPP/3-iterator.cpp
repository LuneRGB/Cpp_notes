#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
using namespace std;
int globalx = 1;
int main()
{
    vector<int> v = {1,2,3,5};
    vector<int> u(10, 8);
    reverse(v.begin(), v.end());
    copy(v.begin(), v.end(), back_inserter(u));  // 如果能copy过去，u.begin() 里面必须已经有4个元素以保证有4个空间
    copy(u.begin(), u.end(), ostream_iterator<int>(cout, ", "));  // copy 到输出流的迭代器
    cout << endl;


    list<int> l;
    // copy(v.begin(), v.end(), back_inserter(l));
    copy(v.begin(), v.end(), front_inserter(l));
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));  // copy 到输出流的迭代器
    // iterator 可以自己去写，去掉行尾的，
    cout << endl;

    return 0;
}