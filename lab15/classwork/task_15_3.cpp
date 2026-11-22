#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

class Polynomial {
    int n;
    double *coef;

public:
    Polynomial(int size) : n(size), coef(nullptr) {
        if (size <= 0) {
            throw invalid_argument("Size must be positive.");
        }
        coef = new double[n];
        for (int i = 0; i < n; i++) {
            coef[i] = 0;
        }
    }

    Polynomial(int size, const double *values) : n(size), coef(nullptr) {
        if (size <= 0) {
            throw invalid_argument("Size must be positive.");
        }
        coef = new double[n];
        fill(values);
    }

    Polynomial(const Polynomial &p) : n(p.n), coef(new double[p.n]) {
        for (int i = 0; i < n; i++) {
            coef[i] = p.coef[i];
        }
    }

    ~Polynomial() {
        delete[] coef;
    }

    Polynomial &operator=(const Polynomial &p) {
        if (this != &p) {
            double *tmp = new double[p.n];
            for (int i = 0; i < p.n; i++) {
                tmp[i] = p.coef[i];
            }
            delete[] coef;
            coef = tmp;
            n = p.n;
        }
        return *this;
    }

    int size() const {
        return n;
    }

    void fill(const double *values) {
        for (int i = 0; i < n; i++) {
            coef[i] = values[i];
        }
    }

    bool setCoef(int i, double value) {
        if (i < 0 || i >= n) {
            return false;
        }
        coef[i] = value;
        return true;
    }

    void print(ostream &os = cout) const {
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                os << " + ";
            }
            os << coef[i] << "*x^" << i;
        }
    }

    friend ostream &operator<<(ostream &os, const Polynomial &p) {
        p.print(os);
        return os;
    }

    friend istream &operator>>(istream &is, Polynomial &p) {
        for (int i = 0; i < p.n; i++) {
            cout << "Coefficient for x^" << i << ": ";
            is >> p.coef[i];
        }
        return is;
    }

    friend bool saveBinary(const Polynomial &p, const char *fileName) {
        ofstream out(fileName, ios::binary);
        if (!out) {
            return false;
        }
        out.write(reinterpret_cast<const char *>(&p.n), sizeof(int));
        out.write(reinterpret_cast<const char *>(p.coef), p.n * sizeof(double));
        return static_cast<bool>(out);
    }

    friend bool loadBinary(Polynomial &p, const char *fileName) {
        ifstream in(fileName, ios::binary);
        if (!in) {
            return false;
        }
        int size;
        in.read(reinterpret_cast<char *>(&size), sizeof(int));
        if (!in || size <= 0) {
            return false;
        }
        double *tmp = new double[size];
        in.read(reinterpret_cast<char *>(tmp), size * sizeof(double));
        if (!in) {
            delete[] tmp;
            return false;
        }
        delete[] p.coef;
        p.coef = tmp;
        p.n = size;
        return true;
    }
};

int main() {
    int size;
    cout << "Number of coefficients N = ";
    cin >> size;
    if (!cin || size <= 0) {
        cerr << "Invalid N" << endl;
        return 1;
    }

    Polynomial p(size);
    cin >> p;
    if (!cin) {
        cerr << "Invalid input" << endl;
        return 1;
    }
    cout << "P(x) = " << p << endl;

    double v[3] = {1, 2, 3};
    Polynomial q(3, v);
    q.setCoef(1, 5);
    cout << "Q(x) = " << q << endl;

    Polynomial c(p);
    cout << "Copy of P: " << c << endl;
    c = q;
    cout << "After assignment: " << c << endl;

    if (!saveBinary(p, "poly.bin")) {
        cerr << "Error writing to file" << endl;
        return 1;
    }

    Polynomial r(1);
    if (!loadBinary(r, "poly.bin")) {
        cerr << "Error reading from file" << endl;
        return 1;
    }
    cout << "Loaded from file: " << r << endl;

    return 0;
}