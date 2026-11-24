#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Number {
public:
    virtual ~Number() {}
    virtual void print() const = 0;
};

class Real : public Number {
private:
    double value;

public:
    Real(double v = 0) {
        value = v;
    }

    double getValue() const {
        return value;
    }

    void setValue(double v) {
        value = v;
    }

    Real operator+(const Real& other) const {
        return Real(value + other.value);
    }

    void print() const override {
        cout << value;
    }
};

class Complex : public Number {
private:
    double re;
    double im;

public:
    Complex(double r = 0, double i = 0) {
        re = r;
        im = i;
    }

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    void print() const override {
        if (im >= 0) {
            cout << re << " + " << im << "i";
        } else {
            cout << re << " - " << -im << "i";
        }
    }
};

Real sumReal(const vector<Real>& v) {
    Real sum;
    for (const Real& x : v) {
        sum = sum + x;
    }
    return sum;
}

Complex sumComplex(const vector<Complex>& v) {
    Complex sum;
    for (const Complex& x : v) {
        sum = sum + x;
    }
    return sum;
}

Complex sumMixed(const vector<Number*>& v) {
    Complex sum;
    for (Number* n : v) {
        Real* r = dynamic_cast<Real*>(n);
        if (r != nullptr) {
            sum = sum + Complex(r->getValue(), 0);
        }

        Complex* c = dynamic_cast<Complex*>(n);
        if (c != nullptr) {
            sum = sum + *c;
        }
    }
    return sum;
}

void printBytes(const unsigned char* bytes, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << hex << setw(2) << setfill('0') << static_cast<int>(bytes[i]) << " ";
    }
    cout << dec << setfill(' ') << endl;
}

int main() {
    cout << "--- static_cast ---" << endl;
    int total = 26;
    int count = 6;
    cout << "Without cast: " << total / count << endl;
    double average = static_cast<double>(total) / count;
    cout << "With static_cast: " << average << endl;

    cout << endl << "--- dynamic_cast ---" << endl;
    Number* num = new Real(3.14);

    Real* r = dynamic_cast<Real*>(num);
    if (r != nullptr) {
        cout << "It is Real, value = " << r->getValue() << endl;
    }

    Complex* c = dynamic_cast<Complex*>(num);
    if (c == nullptr) {
        cout << "It is not Complex, dynamic_cast returned nullptr" << endl;
    }
    delete num;

    cout << endl << "--- const_cast ---" << endl;
    Real a(1.5);
    const Real& ref = a;
    Real& changeable = const_cast<Real&>(ref);
    changeable.setValue(2.5);
    cout << "a after change = " << a.getValue() << endl;

    cout << endl << "--- reinterpret_cast ---" << endl;
    int x = 255;
    double d = static_cast<double>(x);

    cout << "Bytes of int 255: ";
    printBytes(reinterpret_cast<const unsigned char*>(&x), sizeof(x));

    cout << "Bytes of double 255.0: ";
    printBytes(reinterpret_cast<const unsigned char*>(&d), sizeof(d));

    cout << "Decimal again: " << x << endl;

    cout << endl << "--- Vector sums ---" << endl;
    vector<Real> reals = {1.5, 2.25, -0.75, 4.0};
    vector<Complex> complexes = {Complex(1, 2), Complex(3, -1), Complex(-0.5, 0.5)};

    cout << "Sum of Real: ";
    sumReal(reals).print();
    cout << endl;

    cout << "Sum of Complex: ";
    sumComplex(complexes).print();
    cout << endl;

    vector<Number*> mixed;
    mixed.push_back(new Real(10));
    mixed.push_back(new Complex(1, -3));
    mixed.push_back(new Real(-2.5));
    mixed.push_back(new Complex(0.5, 1));

    cout << "Sum of mixed vector: ";
    sumMixed(mixed).print();
    cout << endl;

    for (Number* n : mixed) {
        delete n;
    }

    return 0;
}