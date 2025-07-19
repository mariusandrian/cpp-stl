#include <initializer_list>
#include <iostream>
#include <vector>
#include <stdexcept>

// static int x = 5;
// int& foo() { return x; }
// int* foo() { return &x; }
// ---> equivalent to: return &x; but dereferenced
// int bar() { return x; }
// ---> equivalent to: int temp = x; return temp;

// quite important.
// const T - not useful.
// T
// T&
// const T&
// T*
// const T*

class IntVector
{
private:
    int m_capacity;
    int m_length;
    int *m_data;

    static constexpr int INIT_SIZE = 2;

public:
    // todo:  vector( const vector& other );
    // RULE OF zero three five
    // make assignment and move constructor
    // MyString& operator=(const MyString& other)

    // ALWAYS init data in list initializer. Then do other stuff in the body.
    // Cause in body it might die and the object might be invalid.
    IntVector()
        : m_data{nullptr}, m_length{0}, m_capacity{INIT_SIZE}
    {
    }

        IntVector(std::initializer_list<int> il)
    {
        for (auto it = il.begin(); it != il.end(); ++it)
        {
            std::cout << *it << '\n';
        }
    }

    // TODO: private function that takes in int capacity and expands it to that cap.
    // use for copy constructor

    // Check STL for exact return type. Was under impression from other language that it
    // only peeks the value.
    int &back()
    {
        if (m_length == 0)
            throw std::out_of_range("empty duh");
        return m_data[m_length - 1];
    }

    int &front()
    {
        if (m_length == 0)
            throw std::out_of_range("empty duh");
        return m_data[0];
    }

    int &at(int index) const
    {
        if (index < 0 || index > m_length)
        {
            throw std::out_of_range("invalid index");
        }
        else
        {
            return m_data[index];
        }
    }

    // always use const T& for push back.
    void push_back(const int &num)
    {
        if (m_length == m_capacity)
        {
            // Expand.
            // copy over data from the current arr to the new one.
            m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;

            int *temp = new int[m_capacity]{};
            for (int i = 0; i < m_length; ++i)
            {
                temp[i] = m_data[i];
            }
            delete[] m_data;
            m_data = temp;
        }
        m_data[m_length] = num;
        ++m_length;
    }

    // c in cbegin means const
    const int *cbegin() const
    {
        return m_data;
    }

    const int *cend() const
    {
        return m_data + m_length;
    }

    void pop_back()
    {
        if (m_length == 0)
            throw std::out_of_range("nothing to pop");
        --m_length;
    }

    int size() const
    {
        return m_length;
    }

    void print() const
    {
        std::cout << "capacity is " << m_capacity << std::endl;
        std::cout << "length is " << m_length << std::endl;
        std::cout << "data is" << std::endl;
        for (int i = 0; i < m_length; ++i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Returning a reference allows you to change the value of the element in the array.
    int &operator[](int i)
    {
        return m_data[i];
    }

    ~IntVector()
    {
        if (m_data == nullptr)
            return;
        delete[] m_data;
        std::cout << "completed destruction" << std::endl;
    }
};

int main()
{

    // IntVector iv{1, 2, 3, 4};

    IntVector iv{};
    // iv[0] = 1; // how to return lvalue here? int&?
    // std::cout << &(iv[0]) << '\n';
    // std::cout << &(iv[1]) << '\n';
    // std::cout << &iv[1] << '\n';

    // std::vector<int> v(1.212312);
    // std::cout << v.size() << std::endl;

    // std::vector<int> v1();
    // std::cout << v1.size();
    iv.print();
    iv.push_back(99);
    iv.print();
    iv.push_back(93);
    iv.print();
    iv.push_back(102);
    iv.print();

    std::cout << "at front is " << iv.front() << std::endl;
    std::cout << "at index 1 is " << iv.at(1) << std::endl;
    std::cout << "at back is " << iv.back() << std::endl;

    iv.pop_back();
    std::cout << "at back is " << iv.back() << std::endl;

    std::cout << "front iter is " << iv.cbegin() << std::endl;
    std::cout << "end iter is " << iv.cend() << std::endl;

    std::cout << "Navigating iterators" << std::endl
              << std::endl;
    for (auto it = iv.cbegin(); it != iv.cend(); ++it)
    {
        std::cout << "now at " << *it << std::endl;
    }

    IntVector a = IntVector{}; // calls copy constructor / ctor
    a = IntVector{};           // calls operator=
}