#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void printList(const list<int> &lst) {
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    size_t n1, n2;
    cout << "Enter size of L1: ";
    cin >> n1;
    if (!cin) {
        cerr << "Invalid input" << endl;
        return 1;
    }

    list<int> l1;
    cout << "Enter elements of L1:" << endl;
    for (size_t i = 0; i < n1; ++i) {
        int x;
        cin >> x;
        if (!cin) {
            cerr << "Invalid input" << endl;
            return 1;
        }
        l1.push_back(x);
    }

    cout << "Enter size of L2: ";
    cin >> n2;
    if (!cin) {
        cerr << "Invalid input" << endl;
        return 1;
    }

    list<int> l2;
    cout << "Enter elements of L2:" << endl;
    for (size_t i = 0; i < n2; ++i) {
        int x;
        cin >> x;
        if (!cin) {
            cerr << "Invalid input" << endl;
            return 1;
        }
        l2.push_back(x);
    }

    while (l1.size() > l2.size()) {
        l1.pop_back();
    }
    while (l2.size() > l1.size()) {
        l2.pop_back();
    }

    size_t n = l2.size();
    list<int>::iterator pos = l2.begin();
    for (size_t i = 0; i < n; ++i) {
        ++pos;
        list<int>::iterator first = l1.begin();
        list<int>::iterator last = first;
        ++last;
        l2.splice(pos, l1, first, last);
    }

    cout << "Resulting L2:" << endl;
    printList(l2);

    return 0;
}