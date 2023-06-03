#include <iostream>
#include <mutex>
#include <stdexcept>

class BufferIndexError : public std::out_of_range
{
private:
    int index;
public:
    BufferIndexError(int idx) : std::out_of_range(""), index(idx) {}
    int getIndex() const { return index; }
};

template <typename T, int N>
struct Buffer
{
    int size() const{
        return N;
    }
    bool empty() const{
        return (N == 0);
    }
    const T& operator[](int i) const{
        if (i >= 0 && i < N)
            return elems[i];
        throw BufferIndexError(i);
    }
    const T& front() const{
        return elems[0];
    }
    const T& back() const{
        return elems[N-1];
    }
    T elems[N];
};

template <typename T, int N> std::ostream& operator<<(std::ostream &out, const Buffer<T, N> &buf)
{
    for (int i = 0; i < N; ++i)
        out << buf[i];
    return out;
}

int main()
{
    Buffer<int, 4> numbers = {1, 3, 1, 4};
    Buffer<int, 0> no_numbers;
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';

    Buffer<char, 16> letters = {'D','o',' ','n','o','t',' ','a','n','s','w','e','r','!','!','!'};
    if (!letters.empty())
    {
        std::cout << "The first character is: " << letters.front() << '\n';
        std::cout << "The last character is: " << letters.back() << '\n';
    }
    std::cout << letters << '\n';

    try
    {
        int k = 0;
        while (true)
            std::cout << letters[k++];
    } catch (BufferIndexError &ex) {
        std::cout << "\nBuffer index is out of range: " << ex.getIndex() << std::endl;
    }
}