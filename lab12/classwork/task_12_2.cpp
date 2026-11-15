#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0)
        return 0;

    unsigned long long* a = new unsigned long long[n];
    unsigned long long sum = 0;

    for (int i = 0; i < n; i++) {
        a[i] = 0;

        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;

            if (c < '0' || c > '9') {
                delete[] a;
                return 0;
            }

            a[i] = a[i] * 10 + (c - '0');
        }

        sum += a[i];
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << endl;

    cout << "Sum = " << sum << endl;

    delete[] a;

    return 0;
}