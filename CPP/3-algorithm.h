
#pragma once   // 宏的define
namespace algorithm{    // 放进自己的命名空间

template<typename T, typename Compare>
int min_ele(T a[], int i, int n, Compare comp)      // 现在只能处理数组
{
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (comp(a[j], a[min_idx]))
                min_idx = j;
        }
        return min_idx;
}

// C++ 特有写法 reference
template<typename T>
void swap(T &a, T &b)
{
        T t = a;
        a = b;
        b = t;
}

template<typename T, typename Compare>      // 做比较的函数
void selection_sort(T a[], int n, Compare comp)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min_idx = min_ele(a, i, n, comp);
        if (min_idx != i)
        {
            swap(a[min_idx], a[i]);
        }
    }
}


// 模板
template<typename T>
void print_array(T* a[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << *a[i] << " ";
    std::cout << "\n";
}
// C++ 支持同名函数
}