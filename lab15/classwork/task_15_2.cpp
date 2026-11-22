#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point {
    double x;
    double y;
    static int count;

public:
    Point() : x(0), y(0) {
        count++;
    }

    Point(double x_, double y_) : x(x_), y(y_) {
        count++;
    }

    Point(const Point &p) : x(p.x), y(p.y) {
        count++;
    }

    ~Point() {
        count--;
    }

    Point &operator=(const Point &p) {
        if (this != &p) {
            x = p.x;
            y = p.y;
        }
        return *this;
    }

    static int counter() {
        return count;
    }

    double distance(const Point &p) const {
        return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
    }

    friend ostream &operator<<(ostream &os, const Point &p) {
        os << "(" << p.x << "; " << p.y << ")";
        return os;
    }

    friend istream &operator>>(istream &is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
};

int Point::count = 0;

double perimeter(const vector<Point> &v) {
    double p = 0;
    for (size_t i = 0; i < v.size(); i++) {
        p += v[i].distance(v[(i + 1) % v.size()]);
    }
    return p;
}

int main() {
    vector<Point> polygon;
    int answer;
    while (true) {
        cout << "Enter a vertex? (1 - yes, 0 - no): ";
        cin >> answer;
        if (!cin || answer == 0) {
            break;
        }
        if (answer != 1) {
            continue;
        }
        Point p;
        cout << "x y = ";
        cin >> p;
        if (!cin) {
            cerr << "Invalid input" << endl;
            return 1;
        }
        polygon.push_back(p);
    }
    cout << "Number of instances: " << Point::counter() << endl;
    if (polygon.size() < 3) {
        cout << "A polygon requires at least 3 vertices" << endl;
        return 0;
    }
    for (size_t i = 0; i < polygon.size(); i++) {
        cout << i + 1 << ": " << polygon[i] << endl;
    }
    cout << "Perimeter: " << perimeter(polygon) << endl;
    return 0;
}
