#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <type_traits>

using namespace std;

template <class T1, class T2>
struct Pair {
    T1 first;
    T2 second;

    Pair() : first(), second() {}
    Pair(const T1 &a, const T2 &b) : first(a), second(b) {}
};

template <class Num = long long, class Den = long long>
class Rational {
    Pair<Num, Den> p;

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

    void normalize() {
        if constexpr (is_integral_v<Num> && is_integral_v<Den>) {
            if (p.second == 0) {
                throw invalid_argument("Denominator cannot be zero");
            }
            if (p.second < 0) {
                p.first = -p.first;
                p.second = -p.second;
            }
            long long g = gcd(static_cast<long long>(p.first), static_cast<long long>(p.second));
            if (g > 1) {
                p.first = static_cast<Num>(static_cast<long long>(p.first) / g);
                p.second = static_cast<Den>(static_cast<long long>(p.second) / g);
            }
        } else {
            if (p.second == Den(0)) {
                throw invalid_argument("Denominator cannot be zero");
            }
        }
    }

public:
    Rational() : p(Num(0), Den(1)) {}
    Rational(const Num &n, const Den &d) : p(n, d) {
        normalize();
    }

    const Num &numerator() const {
        return p.first;
    }

    const Den &denominator() const {
        return p.second;
    }

    double toDouble() const {
        return static_cast<double>(p.first) / static_cast<double>(p.second);
    }

    Rational operator+(const Rational &rhs) const {
        auto n = p.first * rhs.p.second + rhs.p.first * p.second;
        auto d = p.second * rhs.p.second;
        return Rational<decltype(n), decltype(d)>(n, d);
    }

    Rational operator-(const Rational &rhs) const {
        auto n = p.first * rhs.p.second - rhs.p.first * p.second;
        auto d = p.second * rhs.p.second;
        return Rational<decltype(n), decltype(d)>(n, d);
    }

    Rational operator*(const Rational &rhs) const {
        auto n = p.first * rhs.p.first;
        auto d = p.second * rhs.p.second;
        return Rational<decltype(n), decltype(d)>(n, d);
    }

    Rational operator/(const Rational &rhs) const {
        if (rhs.p.first == Num(0)) {
            throw domain_error("Division by zero rational");
        }
        auto n = p.first * rhs.p.second;
        auto d = p.second * rhs.p.first;
        return Rational<decltype(n), decltype(d)>(n, d);
    }

    Rational operator%(const Rational &rhs) const {
        if (rhs.p.first == Num(0)) {
            throw domain_error("Division by zero rational");
        }
        long long intPart = static_cast<long long>(trunc(toDouble() / rhs.toDouble()));
        Rational<long long, long long> q(intPart, 1);
        auto n = p.first * rhs.p.second - q.numerator() * rhs.p.first * p.second;
        auto d = p.second * rhs.p.second;
        return Rational<decltype(n), decltype(d)>(n, d);
    }

    bool operator==(const Rational &rhs) const {
        return p.first * rhs.p.second == rhs.p.first * p.second;
    }

    bool operator!=(const Rational &rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Rational &rhs) const {
        return p.first * rhs.p.second < rhs.p.first * p.second;
    }

    bool operator<=(const Rational &rhs) const {
        return *this < rhs || *this == rhs;
    }

    bool operator>(const Rational &rhs) const {
        return rhs < *this;
    }

    bool operator>=(const Rational &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        os << r.p.first << "/" << r.p.second;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        Num n;
        Den d;
        if (is >> n >> d) {
            r = Rational(n, d);
        }
        return is;
    }
};

template <class Den>
class Rational<string, Den> {
    Pair<string, Den> p;
    string repr;

    void buildRepr() {
        repr = p.first + "/" + to_string(p.second);
    }

public:
    Rational() : p("", Den(1)) {
        buildRepr();
    }

    Rational(const string &n, const Den &d) : p(n, d) {
        buildRepr();
    }

    const string &numerator() const {
        return p.first;
    }

    const Den &denominator() const {
        return p.second;
    }

    const string &value() const {
        return repr;
    }

    Rational operator+(const Rational &rhs) const {
        return Rational(repr + rhs.repr, p.second);
    }

    Rational operator-(const Rational &) const {
        throw logic_error("Subtraction is not supported for string rational");
    }

    Rational operator*(const Rational &) const {
        throw logic_error("Multiplication is not supported for string rational");
    }

    Rational operator/(const Rational &) const {
        throw logic_error("Division is not supported for string rational");
    }

    Rational operator%(const Rational &) const {
        throw logic_error("Remainder is not supported for string rational");
    }

    bool operator==(const Rational &rhs) const {
        return repr == rhs.repr;
    }

    bool operator!=(const Rational &rhs) const {
        return repr != rhs.repr;
    }

    bool operator<(const Rational &rhs) const {
        return repr < rhs.repr;
    }

    bool operator<=(const Rational &rhs) const {
        return repr <= rhs.repr;
    }

    bool operator>(const Rational &rhs) const {
        return repr > rhs.repr;
    }

    bool operator>=(const Rational &rhs) const {
        return repr >= rhs.repr;
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        os << r.repr;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        string n;
        Den d;
        if (is >> n >> d) {
            r = Rational(n, d);
        }
        return is;
    }
};

template <class Num>
class Rational<Num, string> {
    Pair<Num, string> p;
    string repr;

    void buildRepr() {
        repr = to_string(p.first) + "/" + p.second;
    }

public:
    Rational() : p(Num(0), "") {
        buildRepr();
    }

    Rational(const Num &n, const string &d) : p(n, d) {
        buildRepr();
    }

    const Num &numerator() const {
        return p.first;
    }

    const string &denominator() const {
        return p.second;
    }

    const string &value() const {
        return repr;
    }

    Rational operator+(const Rational &rhs) const {
        return Rational(p.first, repr + rhs.repr);
    }

    Rational operator-(const Rational &) const {
        throw logic_error("Subtraction is not supported for string rational");
    }

    Rational operator*(const Rational &) const {
        throw logic_error("Multiplication is not supported for string rational");
    }

    Rational operator/(const Rational &) const {
        throw logic_error("Division is not supported for string rational");
    }

    Rational operator%(const Rational &) const {
        throw logic_error("Remainder is not supported for string rational");
    }

    bool operator==(const Rational &rhs) const {
        return repr == rhs.repr;
    }

    bool operator!=(const Rational &rhs) const {
        return repr != rhs.repr;
    }

    bool operator<(const Rational &rhs) const {
        return repr < rhs.repr;
    }

    bool operator<=(const Rational &rhs) const {
        return repr <= rhs.repr;
    }

    bool operator>(const Rational &rhs) const {
        return repr > rhs.repr;
    }

    bool operator>=(const Rational &rhs) const {
        return repr >= rhs.repr;
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        os << r.repr;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        Num n;
        string d;
        if (is >> n >> d) {
            r = Rational(n, d);
        }
        return is;
    }
};

template <>
class Rational<string, string> {
    Pair<string, string> p;
    string repr;

    void buildRepr() {
        repr = p.first + "/" + p.second;
    }

public:
    Rational() : p("", "") {
        buildRepr();
    }

    Rational(const string &n, const string &d) : p(n, d) {
        buildRepr();
    }

    const string &numerator() const {
        return p.first;
    }

    const string &denominator() const {
        return p.second;
    }

    const string &value() const {
        return repr;
    }

    Rational operator+(const Rational &rhs) const {
        return Rational(repr + rhs.repr, "");
    }

    Rational operator-(const Rational &) const {
        throw logic_error("Subtraction is not supported for string rational");
    }

    Rational operator*(const Rational &) const {
        throw logic_error("Multiplication is not supported for string rational");
    }

    Rational operator/(const Rational &) const {
        throw logic_error("Division is not supported for string rational");
    }

    Rational operator%(const Rational &) const {
        throw logic_error("Remainder is not supported for string rational");
    }

    bool operator==(const Rational &rhs) const {
        return repr == rhs.repr;
    }

    bool operator!=(const Rational &rhs) const {
        return repr != rhs.repr;
    }

    bool operator<(const Rational &rhs) const {
        return repr < rhs.repr;
    }

    bool operator<=(const Rational &rhs) const {
        return repr <= rhs.repr;
    }

    bool operator>(const Rational &rhs) const {
        return repr > rhs.repr;
    }

    bool operator>=(const Rational &rhs) const {
        return repr >= rhs.repr;
    }

    friend ostream &operator<<(ostream &os, const Rational &r) {
        os << r.repr;
        return os;
    }

    friend istream &operator>>(istream &is, Rational &r) {
        string n, d;
        if (is >> n >> d) {
            r = Rational(n, d);
        }
        return is;
    }
};

int main() {
    Rational<int, int> a(7, 4);
    Rational<int, int> b(1, 2);

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    cout << (a > b) << " " << (a == b) << endl;

    Rational<string, int> s1("a", 2);
    Rational<string, int> s2("b", 3);
    cout << s1.value() << " | " << s1.numerator() << " | " << s1.denominator() << endl;
    cout << (s1 + s2) << endl;
    cout << (s1 < s2) << endl;

    try {
        auto res = s1 - s2;
        cout << res << endl;
    } catch (const logic_error &e) {
        cout << e.what() << endl;
    }

    return 0;
}
