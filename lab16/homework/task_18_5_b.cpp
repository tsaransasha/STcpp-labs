#include <iostream>
#include <string>
#include <utility>

using namespace std;

template <class T>
class Array {
    T *data;
    size_t length;

public:
    explicit Array(size_t n = 0) : data(n > 0 ? new T[n]() : nullptr), length(n) {}

    Array(initializer_list<T> init) : data(init.size() > 0 ? new T[init.size()] : nullptr), length(init.size()) {
        size_t i = 0;
        for (const auto &item : init) {
            data[i++] = item;
        }
    }

    Array(const Array &other) : data(other.length > 0 ? new T[other.length] : nullptr), length(other.length) {
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    ~Array() {
        delete[] data;
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            T *newData = other.length > 0 ? new T[other.length] : nullptr;
            for (size_t i = 0; i < other.length; ++i) {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            length = other.length;
        }
        return *this;
    }

    size_t size() const {
        return length;
    }

    T &operator[](size_t index) {
        return data[index];
    }

    const T &operator[](size_t index) const {
        return data[index];
    }

    static void sortCocktail(T *arr, size_t n) {
        if (arr == nullptr || n < 2) {
            return;
        }

        size_t left = 0;
        size_t right = n - 1;
        bool swapped = true;

        while (left < right && swapped) {
            swapped = false;

            for (size_t i = left; i < right; ++i) {
                if (arr[i + 1] < arr[i]) {
                    swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
            --right;

            if (!swapped) {
                break;
            }

            swapped = false;
            for (size_t i = right; i > left; --i) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
            ++left;
        }
    }

    static void sortCocktail(Array<T> &arr) {
        sortCocktail(arr.data, arr.length);
    }

    void sortCocktail() {
        sortCocktail(data, length);
    }

    void print() const {
        for (size_t i = 0; i < length; ++i) {
            cout << data[i] << (i + 1 < length ? " " : "");
        }
        cout << endl;
    }
};

int main() {
    Array<int> a = {64, 34, 25, 12, 22, 11, 90};
    a.sortCocktail();
    a.print();

    Array<double> b = {3.14, -1.5, 0.0, 2.71, -8.2};
    Array<double>::sortCocktail(b);
    b.print();

    int raw[] = {50, 10, 40, 20, 30};
    size_t n = sizeof(raw) / sizeof(raw[0]);
    Array<int>::sortCocktail(raw, n);
    for (size_t i = 0; i < n; ++i) {
        cout << raw[i] << (i + 1 < n ? " " : "");
    }
    cout << endl;

    Array<string> words = {"pear", "apple", "orange", "banana"};
    words.sortCocktail();
    words.print();

    return 0;
}
