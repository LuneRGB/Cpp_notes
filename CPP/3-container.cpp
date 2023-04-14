#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> evens {2, 4, 6, 8};
    evens.push_back(20);            // 当空间不够时会自动开辟新的空间，将原来的元素复制过去，均摊复杂度等于数组
    evens.insert(evens.begin() + 4, 5, 10);  // 在给定位置的前面插入5 个 10
    for (int i = 0; i < evens.size(); i++)
    {
        cout << evens[i] << ' ';
    }
    cout << endl;
    // 传入算法api的都是迭代器类型，不是vector list等形式，所以可以统一使用
    for (vector<int>::iterator it = evens.begin(); it < evens.end(); ++it)      // vector的迭代器可以小于也可以不等号，list不可以
    {
        cout << *it << ' ';
    }
    // auto, 底层是迭代器，数组也可以用
    for (int e : evens)
    {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}