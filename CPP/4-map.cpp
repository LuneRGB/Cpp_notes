#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string, int> price;
    price["apple"] = 3;
    price["orange"] = 5;
    price["banana"] = 1;
    // 如果输入不在价目表里的事情

    for (const auto &pair : price)
    {
        cout << "{" << pair.first << "," << pair.second << "}" ; 
    }
    cout << endl;
    
    string item;
    int total = 0;
    while (cin >> item)     // 结束输入ctrl + d
    {
        if (price.contains(item))   // 这个需要换到c++20. 如果没有20，可以用.count
            total += price[item];   // silent insertion: 如果item不在容器里，会建立item键值对，没有给的参数用默认构造函数
        else
            cout << item << "is not in the fruit list" << endl;
    } 

    // 会出现不在价目表里的东西
    for (const auto &pair : price)
    {
        cout << "{" << pair.first << "," << pair.second << "}" ; 
    }
    cout << endl;
    
    cout << total << endl;
    return 0;
}