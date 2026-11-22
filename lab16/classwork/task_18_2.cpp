#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

namespace MyLib {

    template <class T> class Stack {
        T *data;
        size_t count;
        size_t capacity;

        void grow() {
            size_t newCapacity = capacity * 2;
            T *tmp = new T[newCapacity];
            for (size_t i = 0; i < count; ++i) {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
            capacity = newCapacity;
        }

    public:
        Stack() : data(new T[4]), count(0), capacity(4) {}

        Stack(const Stack &s) : data(new T[s.capacity]), count(s.count), capacity(s.capacity) {
            for (size_t i = 0; i < count; ++i) {
                data[i] = s.data[i];
            }
        }

        ~Stack() {
            delete[] data;
        }

        Stack &operator=(const Stack &s) {
            if (this != &s) {
                T *tmp = new T[s.capacity];
                for (size_t i = 0; i < s.count; ++i) {
                    tmp[i] = s.data[i];
                }
                delete[] data;
                data = tmp;
                count = s.count;
                capacity = s.capacity;
            }
            return *this;
        }

        void push(const T &value) {
            if (count == capacity) {
                grow();
            }
            data[count++] = value;
        }

        T pop() {
            if (count == 0) {
                throw out_of_range("Stack is empty");
            }
            return data[--count];
        }

        const T &top() const {
            if (count == 0) {
                throw out_of_range("Stack is empty");
            }
            return data[count - 1];
        }

        bool empty() const {
            return count == 0;
        }

        size_t size() const {
            return count;
        }
    };

    template <class T> size_t readUntilZero(T *&result) {
        Stack<T> st;
        T x;
        while (cin >> x && x != T(0)) {
            st.push(x);
        }
        size_t n = st.size();
        result = (n > 0) ? new T[n] : nullptr;
        for (size_t i = n; i > 0; --i) {
            result[i - 1] = st.pop();
        }
        return n;
    }

    template <class T> bool sameAsStandard(const T *a, size_t n) {
        Stack<T> mine;
        stack<T> standard;
        for (size_t i = 0; i < n; ++i) {
            mine.push(a[i]);
            standard.push(a[i]);
        }
        if (mine.size() != standard.size()) {
            return false;
        }
        while (!standard.empty()) {
            if (mine.top() != standard.top()) {
                return false;
            }
            mine.pop();
            standard.pop();
        }
        return mine.empty();
    }

    template <class T> void printArray(const T *a, size_t n) {
        for (size_t i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

}

int main() {
    int *a = nullptr;
    cout << "Enter integers, 0 to stop:" << endl;
    size_t n = MyLib::readUntilZero(a);
    cout << "Element count: " << n << endl;
    MyLib::printArray(a, n);
    if (MyLib::sameAsStandard(a, n)) {
        cout << "Custom stack behaves the same as std::stack<int>" << endl;
    } else {
        cout << "Custom stack behaves differently from std::stack<int>" << endl;
    }
    delete[] a;

    cin.clear();
    double *b = nullptr;
    cout << "Enter floating-point numbers, 0 to stop:" << endl;
    size_t m = MyLib::readUntilZero(b);
    cout << "Element count: " << m << endl;
    MyLib::printArray(b, m);
    if (MyLib::sameAsStandard(b, m)) {
        cout << "Custom stack behaves the same as std::stack<double>" << endl;
    } else {
        cout << "Custom stack behaves differently from std::stack<double>" << endl;
    }
    delete[] b;

    try {
        MyLib::Stack<int> empty;
        empty.pop();
    } catch (const out_of_range &e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}