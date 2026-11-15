
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        return 0;
    }

    const int MAX = 128 * 1024;
    unsigned long long* a = new unsigned long long[MAX];

    int n = 0;
    unsigned long long x;

    while (fin >> x) {
        if (x > 1000000000000000000ULL || n == MAX) {
            cout << "Incorrect input file" << endl;
            delete[] a;
            return 0;
        }

        a[n] = x;
        n++;
    }

    if (!fin.eof()) {
        cout << "Incorrect input file" << endl;
        delete[] a;
        return 0;
    }

    fin.close();

    cout << fixed << setprecision(3);

    for (int i = n - 1; i >= 0; i--)
        cout << sqrt((long double)a[i]) << endl;

    delete[] a;

    return 0;
}