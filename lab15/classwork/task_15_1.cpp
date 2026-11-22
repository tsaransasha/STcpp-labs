#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

class Rational {
private:
    int nominator;
    unsigned int denominator;

    static unsigned long long gcd(unsigned long long a, unsigned long long b) {
        while (b != 0) {
            unsigned long long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    void reduce() {
        if (nominator == 0) {
            denominator = 1;
            return;
        }
        unsigned long long absN = nominator < 0 ? static_cast<unsigned long long>(-static_cast<long long>(nominator)) : static_cast<unsigned long long>(nominator);
        unsigned long long g = gcd(absN, denominator);
        if (g > 1) {
            nominator = static_cast<int>(nominator / static_cast<long long>(g));
            denominator = static_cast<unsigned int>(denominator / g);
        }
    }

    static Rational make(long long n, unsigned long long d) {
        if (d == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        unsigned long long absN = n < 0 ? static_cast<unsigned long long>(-n) : static_cast<unsigned long long>(n);
        unsigned long long g = gcd(absN, d);
        Rational r;
        r.nominator = static_cast<int>(n / static_cast<long long>(g));
        r.denominator = static_cast<unsigned int>(d / g);
        return r;
    }

public:
    Rational() : nominator(1), denominator(1) {}

    Rational(int n, unsigned int d) : nominator(n), denominator(d) {
        if (denominator == 0) {
            cerr << "Warning: Denominator cannot be zero. Defaulting denominator to 1." << endl;
            denominator = 1;
        }
        reduce();
    }

    int getNominator() const {
        return nominator;
    }

    unsigned int getDenominator() const {
        return denominator;
    }

    void setNominator(int n) {
        nominator = n;
        reduce();
    }

    bool setDenominator(unsigned int d) {
        if (d == 0) {
            return false;
        }
        denominator = d;
        reduce();
        return true;
    }

    double toDouble() const {
        return static_cast<double>(nominator) / denominator;
    }

    void input() {
        int n;
        long long d;
        cout << "Numerator: ";
        cin >> n;
        do {
            cout << "Denominator (positive integer): ";
            cin >> d;
            if (!cin) return;
        } while (d <= 0 || d > 4294967295LL);

        nominator = n;
        denominator = static_cast<unsigned int>(d);
        reduce();
    }

    void print() const {
        if (denominator == 1) {
            cout << nominator;
        } else {
            cout << nominator << "/" << denominator;
        }
    }

    Rational add(const Rational &b) const {
        return make(static_cast<long long>(nominator) * b.denominator + static_cast<long long>(b.nominator) * denominator,
                    static_cast<unsigned long long>(denominator) * b.denominator);
    }

    Rational multiply(const Rational &b) const {
        return make(static_cast<long long>(nominator) * b.nominator,
                    static_cast<unsigned long long>(denominator) * b.denominator);
    }

    Rational operator+(const Rational &b) const { return add(b); }
    Rational operator-(const Rational &b) const {
        return make(static_cast<long long>(nominator) * b.denominator - static_cast<long long>(b.nominator) * denominator,
                    static_cast<unsigned long long>(denominator) * b.denominator);
    }
    Rational operator*(const Rational &b) const { return multiply(b); }

    Rational operator/(const Rational &b) const {
        if (b.nominator == 0) {
            throw invalid_argument("Division by zero.");
        }
        long long n = static_cast<long long>(nominator) * b.denominator;
        unsigned long long d = static_cast<unsigned long long>(denominator) * (b.nominator < 0 ? -static_cast<long long>(b.nominator) : b.nominator);
        if (b.nominator < 0) {
            n = -n;
        }
        return make(n, d);
    }

    Rational operator-() const {
        return make(-static_cast<long long>(nominator), denominator);
    }

    Rational &operator+=(const Rational &b) {
        *this = *this + b;
        return *this;
    }

    Rational &operator*=(const Rational &b) {
        *this = *this * b;
        return *this;
    }

    bool operator==(const Rational &b) const {
        return nominator == b.nominator && denominator == b.denominator;
    }

    bool operator!=(const Rational &b) const {
        return !(*this == b);
    }

    bool operator<(const Rational &b) const {
        return static_cast<long long>(nominator) * b.denominator < static_cast<long long>(b.nominator) * denominator;
    }

    bool operator>(const Rational &b) const {
        return b < *this;
    }

    bool operator<=(const Rational &b) const {
        return !(b < *this);
    }

    bool operator>=(const Rational &b) const {
        return !(*this < b);
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        if (r.denominator == 1) {
            os << r.nominator;
        } else {
            os << r.nominator << "/" << r.denominator;
        }
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        int n;
        long long d;
        is >> n >> d;
        if (is && (d <= 0 || d > 4294967295LL)) {
            is.setstate(ios::failbit);
        }
        if (is) {
            r.nominator = n;
            r.denominator = static_cast<unsigned int>(d);
            r.reduce();
        }
        return is;
    }
};

int main() {
    cout << "=== Class Demo ===" << endl;
    Rational a, b;
    cout << "First rational number:" << endl;
    a.input();
    cout << "Second rational number:" << endl;
    b.input();

    if (!cin) {
        cerr << "Invalid input data." << endl;
        return 1;
    }

    cout << "\nResults:" << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;

    if (b != Rational(0, 1)) {
        cout << a << " / " << b << " = " << a / b << endl;
    } else {
        cout << "Cannot divide by zero." << endl;
    }

    cout << a << (a < b ? " < " : (a > b ? " > " : " == ")) << b << endl;

    cout << "\n=== Independent Task 1: Find Minimum in Array ===" << endl;
    int n;
    cout << "Enter array size N: ";
    cin >> n;

    if (!cin || n <= 0) {
        cerr << "Invalid size N." << endl;
        return 1;
    }

    vector<Rational> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]:" << endl;
        arr[i].input();
        if (!cin) {
            cerr << "Invalid input data." << endl;
            return 1;
        }
    }

    Rational minimum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }
    cout << "Minimum rational number: " << minimum << endl;

    cout << "\n=== Independent Task 2: Series Sum Approximation ===" << endl;
    double sum = 1.0;
    long long k = 2;

    while (true) {
        double term = 1.0 / (k * k);
        if (term < 0.01) {
            break;
        }
        if (k % 2 == 0) {
            sum -= term;
        } else {
            sum += term;
        }
        k++;
    }

    double target = (acos(-1.0) * acos(-1.0)) / 12.0;
    cout << "Calculated series sum: " << sum << endl;
    cout << "Target (pi^2 / 12):   " << target << endl;
    cout << "Difference:           " << fabs(sum - target) << endl;

    if (fabs(sum - target) < 0.01) {
        cout << "The series converges to pi^2 / 12 with precision 0.01." << endl;
    } else {
        cout << "The series does not reach target within precision 0.01 at this step threshold." << endl;
    }

    return 0;
}