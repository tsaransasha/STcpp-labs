#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <stdexcept>

using namespace std;

class QuadraticEquation {
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a_ = 1.0, double b_ = 0.0, double c_ = 0.0) : a(a_), b(b_), c(c_) {
        if (fabs(a) < 1e-12) {
            throw invalid_argument("Coefficient a must not be zero.");
        }
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    double evaluate(double x) const {
        return a * x * x + b * x + c;
    }

    double discriminant() const {
        return b * b - 4.0 * a * c;
    }

    vector<double> findRoots() const {
        vector<double> roots;
        double d = discriminant();
        if (d > 1e-12) {
            double sqrtD = sqrt(d);
            double x1 = (-b - sqrtD) / (2.0 * a);
            double x2 = (-b + sqrtD) / (2.0 * a);
            if (x1 > x2) {
                swap(x1, x2);
            }
            roots.push_back(x1);
            roots.push_back(x2);
        } else if (fabs(d) <= 1e-12) {
            double x = -b / (2.0 * a);
            roots.push_back(x);
        }
        return roots;
    }

    void printRoots() const {
        vector<double> roots = findRoots();
        if (roots.empty()) {
            cout << "No real roots (D < 0)." << endl;
        } else if (roots.size() == 1) {
            cout << "One real root: x = " << roots[0] << endl;
        } else {
            cout << "Two real roots: x1 = " << roots[0] << ", x2 = " << roots[1] << endl;
        }
    }

    void printExtremum() const {
        double x0 = -b / (2.0 * a);
        double y0 = evaluate(x0);
        if (a > 0) {
            cout << "Minimum at (" << x0 << "; " << y0 << ")" << endl;
        } else {
            cout << "Maximum at (" << x0 << "; " << y0 << ")" << endl;
        }
    }

    void printMonotonicity() const {
        double x0 = -b / (2.0 * a);
        if (a > 0) {
            cout << "Decreasing on (-inf; " << x0 << "], increasing on [" << x0 << "; +inf)" << endl;
        } else {
            cout << "Increasing on (-inf; " << x0 << "], decreasing on [" << x0 << "; +inf)" << endl;
        }
    }

    void printEquation() const {
        cout << a << "*x^2";
        if (b >= 0) {
            cout << " + " << b << "*x";
        } else {
            cout << " - " << fabs(b) << "*x";
        }
        if (c >= 0) {
            cout << " + " << c;
        } else {
            cout << " - " << fabs(c);
        }
        cout << " = 0";
    }
};

int main() {
    int count;
    cout << "Enter number of quadratic equations: ";
    cin >> count;
    if (!cin || count <= 0) {
        cerr << "Invalid count." << endl;
        return 1;
    }

    vector<QuadraticEquation> equations;
    equations.reserve(count);

    for (int i = 0; i < count; i++) {
        double a, b, c;
        cout << "Equation [" << i << "] (a b c): ";
        cin >> a >> b >> c;
        if (!cin) {
            cerr << "Invalid input." << endl;
            return 1;
        }
        if (fabs(a) < 1e-12) {
            cerr << "Coefficient a cannot be zero. Skipping or re-enter." << endl;
            return 1;
        }
        equations.emplace_back(a, b, c);
    }

    bool hasAnyRoot = false;
    double minRoot = numeric_limits<double>::infinity();
    double maxRoot = -numeric_limits<double>::infinity();

    for (size_t i = 0; i < equations.size(); i++) {
        cout << "\n--- Equation " << i + 1 << ": ";
        equations[i].printEquation();
        cout << " ---" << endl;
        equations[i].printRoots();
        equations[i].printExtremum();
        equations[i].printMonotonicity();

        vector<double> roots = equations[i].findRoots();
        for (double r : roots) {
            if (!hasAnyRoot || r < minRoot) {
                minRoot = r;
            }
            if (!hasAnyRoot || r > maxRoot) {
                maxRoot = r;
            }
            hasAnyRoot = true;
        }
    }

    cout << "\n=== Overall Roots Summary ===" << endl;
    if (hasAnyRoot) {
        cout << "Smallest root across all equations: " << minRoot << endl;
        cout << "Largest root across all equations:  " << maxRoot << endl;
    } else {
        cout << "No real roots found in any equation." << endl;
    }

    return 0;
}