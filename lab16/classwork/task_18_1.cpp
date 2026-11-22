#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace MyLib {

    class Rational {
        long long nominator;
        long long denominator;

        static long long gcd(long long a, long long b) {
            if (a < 0) {
                a = -a;
            }
            while (b != 0) {
                long long t = a % b;
                a = b;
                b = t;
            }
            return a;
        }

        void reduce() {
            long long g = gcd(nominator, denominator);
            if (g > 1) {
                nominator /= g;
                denominator /= g;
            }
        }

    public:
        Rational(long long n = 0, long long d = 1) : nominator(n), denominator(d) {
            if (denominator == 0) {
                cerr << "Denominator cannot be zero, set to 1" << endl;
                denominator = 1;
            }
            if (denominator < 0) {
                nominator = -nominator;
                denominator = -denominator;
            }
            reduce();
        }

        bool operator<(const Rational &b) const {
            return nominator * b.denominator < b.nominator * denominator;
        }

        bool operator>(const Rational &b) const {
            return b < *this;
        }

        bool operator==(const Rational &b) const {
            return nominator == b.nominator && denominator == b.denominator;
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
            long long n, d;
            is >> n >> d;
            if (is && d == 0) {
                is.setstate(ios::failbit);
            }
            if (is) {
                r = Rational(n, d);
            }
            return is;
        }
    };

    template <class T> const T &maximum(const T &a, const T &b) {
        return (a < b) ? b : a;
    }

    const char *maximum(const char *a, const char *b) {
        return (strcmp(a, b) < 0) ? b : a;
    }

}

int main() {
    int i1, i2;
    cout << "Two integers: ";
    cin >> i1 >> i2;

    double d1, d2;
    cout << "Two floating-point numbers: ";
    cin >> d1 >> d2;

    char c1, c2;
    cout << "Two characters: ";
    cin >> c1 >> c2;

    string s1, s2;
    cout << "Two strings: ";
    cin >> s1 >> s2;

    MyLib::Rational r1, r2;
    cout << "First rational (numerator denominator): ";
    cin >> r1;
    cout << "Second rational (numerator denominator): ";
    cin >> r2;

    if (!cin) {
        cerr << "Invalid input" << endl;
        return 1;
    }

    cout << "int: " << MyLib::maximum(i1, i2) << endl;
    cout << "double: " << MyLib::maximum(d1, d2) << endl;
    cout << "char: " << MyLib::maximum(c1, c2) << endl;
    cout << "string: " << MyLib::maximum(s1, s2) << endl;
    cout << "Rational: " << MyLib::maximum(r1, r2) << endl;
    cout << "const char*: " << MyLib::maximum("apple", "pear") << endl;
    cout << "long: " << MyLib::maximum(100000L, 99999L) << endl;
    cout << "float: " << MyLib::maximum(1.5f, 2.5f) << endl;

    return 0;
}