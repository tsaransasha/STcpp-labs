#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0)
        return 0;

    for (int i = 0; i < 8 * n + 1; i++)
        cout << "+";
    cout << endl;

    for (int i = 1; i <= n; i++)
        cout << setw(8) << i;
    cout << endl;

    for (int i = 0; i < 8 * n + 1; i++)
        cout << "+";
    cout << endl;

    for (int i = 1; i <= n; i++) {
        double x = sqrt(i);

        if ((int)x * (int)x == i)
            cout << setw(8) << (int)x;
        else
            cout << fixed << setprecision(2) << setw(8) << x;
    }

    cout << endl;

    for (int i = 0; i < 8 * n + 1; i++)
        cout << "+";
    cout << endl;

    return 0;
}