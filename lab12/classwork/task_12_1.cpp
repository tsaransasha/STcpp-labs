#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x, y;
    cin >> x;
    cin >> y;

    double z = pow(x, y);

    cout << fixed << setprecision(6) << z << endl;
    cout << scientific << setprecision(6) << z << endl;

    return 0;
}