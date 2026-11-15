#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    long long x, y, z;
};

long double dist2(Point a, Point b) {
    long double dx = (long double)a.x - b.x;
    long double dy = (long double)a.y - b.y;
    long double dz = (long double)a.z - b.z;
    return dx * dx + dy * dy + dz * dz;
}

int main() {
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open input.txt" << endl;
        return 0;
    }

    int cap = 16;
    Point* p = new Point[cap];

    int n = 0;
    long long x1, x2, x3;
    char c;


    while (fin >> x1) {
        if (!(fin >> c) || c != ',' ||
            !(fin >> x2) ||
            !(fin >> c) || c != ',' ||
            !(fin >> x3)) {
            cout << "Incorrect input file" << endl;
            delete[] p;
            return 0;
        }

        if (n == cap) {
            cap *= 2;
            Point* tmp = new Point[cap];
            for (int i = 0; i < n; i++)
                tmp[i] = p[i];
            delete[] p;
            p = tmp;
        }

        p[n].x = x1;
        p[n].y = x2;
        p[n].z = x3;
        n++;

        if (fin >> c) {
            if (c != ';') {
                cout << "Incorrect input file" << endl;
                delete[] p;
                return 0;
            }
        }
        else
            break;
    }

    if (!fin.eof()) {
        cout << "Incorrect input file" << endl;
        delete[] p;
        return 0;
    }

    fin.close();

    if (n < 2) {
        cout << "Not enough points (need at least 2)" << endl;
        delete[] p;
        return 0;
    }

    int bestI = 0, bestJ = 1;
    long double best = dist2(p[0], p[1]);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            long double d = dist2(p[i], p[j]);
            if (d > best) {
                best = d;
                bestI = i;
                bestJ = j;
            }
        }

    cout << "Longest segment:" << endl;
    cout << "(" << p[bestI].x << ", " << p[bestI].y << ", " << p[bestI].z << ") - ";
    cout << "(" << p[bestJ].x << ", " << p[bestJ].y << ", " << p[bestJ].z << ")" << endl;

    cout << fixed << setprecision(3);
    cout << "Length: " << sqrt(best) << endl;

    delete[] p;

    return 0;
}