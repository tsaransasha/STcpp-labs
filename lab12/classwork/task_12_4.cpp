
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    if (n <= 0)
        return 0;

    int* m = new int[n];
    double* x = new double[n];

    for (int i = 0; i < n; i++)
        cin >> m[i];

    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        delete[] m;
        delete[] x;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (!(fin >> x[i])) {
            cout << "Incorrect input file" << endl;
            delete[] m;
            delete[] x;
            return 0;
        }
    }

    string extra;
    if (fin >> extra) {
        cout << "Incorrect input file" << endl;
        delete[] m;
        delete[] x;
        return 0;
    }

    fin.close();

    for (int i = 0; i < n; i++) {
        if (x[i] == 0 && m[i] < 0) {
            cout << "Cannot calculate 0 to negative power" << endl;
            delete[] m;
            delete[] x;
            return 0;
        }
    }

    ofstream fout("output.txt");

    if (!fout) {
        cout << "Cannot create output.txt" << endl;
        delete[] m;
        delete[] x;
        return 0;
    }

    for (int i = 0; i < n; i++)
        fout << pow(x[i], m[i]) << endl;

    fout.close();

    delete[] m;
    delete[] x;

    return 0;
}