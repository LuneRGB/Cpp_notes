#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>

using namespace std;

int main(){

    const int Size = 5;
    int arr[Size] {5, 4, 3, 2, 1};
    list<int> l(arr, arr+Size);     // arr's address
    set<int> s(arr, arr+Size);
    vector<int> v(arr, arr+Size);

    auto ita = find(arr, arr+Size, 3);          // 迭代器是前闭后开的
    cout << *ita << endl;                       // 原生数组的迭代器是指针
    auto itl = find(l.begin(), l.end(), 3);     // return a iter between arr and arr+Size
    // ++itl;
    // itl += 2;     // 链表上没有实现+=操作，因为效率不好
    cout << *itl << endl;
    auto its = find(s.begin(), s.end(), 3);
    its ++;     // set底层是一个平衡二叉树，是红黑树实现的，是二叉搜索树，按中序遍历去访问元素会得到从小到大排列的顺序，所以会得到4
    cout << *its << endl;
    auto itv = find(v.begin(), v.end(), 3);
    itv += 2;
    cout << *itv << endl;

}
