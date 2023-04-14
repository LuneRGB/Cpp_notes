#include <iostream>
#include <map>
using namespace std;
int main()
{
    map <string, int> word_map;
    for (const auto& w : {"we", "are", "not", "humans", "we", "are", "robots"})
        ++word_map[w];      //  创建键值对和++合为一
    for (const auto& [word, count] : word_map)
        std::cout << count << " occurrence(s) of " << word << endl;      
    return 0;
}