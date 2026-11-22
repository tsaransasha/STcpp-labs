#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

using namespace std;

int rowMax(const list<int> &row) {
    if (row.empty()) {
        throw invalid_argument("Row cannot be empty");
    }
    list<int>::const_iterator it = row.begin();
    int m = *it;
    for (; it != row.end(); ++it) {
        if (*it > m) {
            m = *it;
        }
    }
    return m;
}

void printMatrix(const vector<list<int> > &a) {
    for (size_t i = 0; i < a.size(); ++i) {
        for (list<int>::const_iterator it = a[i].begin(); it != a[i].end(); ++it) {
            cout << *it << "\t";
        }
        cout << "  [max = " << rowMax(a[i]) << "]" << endl;
    }
}

int main() {
    int n, m;
    cout << "n=";
    cin >> n;
    cout << "m=";
    cin >> m;
    if (!cin || n <= 0 || m <= 0 || n >= 100 || m >= 100) {
        cerr << "n and m must be positive integers less than 100" << endl;
        return 1;
    }

    vector<list<int> > a(n);
    for (int i = 0; i < n; ++i) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (!cin) {
                cerr << "Invalid input" << endl;
                return 1;
            }
            a[i].push_back(x);
        }
    }

    cout << "Initial matrix:" << endl;
    printMatrix(a);

    vector<int> maxVals(n);
    for (int i = 0; i < n; ++i) {
        maxVals[i] = rowMax(a[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (maxVals[j] < maxVals[j + 1]) {
                a[j].swap(a[j + 1]);
                int tmp = maxVals[j];
                maxVals[j] = maxVals[j + 1];
                maxVals[j + 1] = tmp;
            }
        }
    }

    cout << "Matrix after sorting rows:" << endl;
    printMatrix(a);

    return 0;
}