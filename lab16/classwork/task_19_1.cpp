#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Number of customers N=";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "Invalid N" << endl;
        return 1;
    }

    queue<double> service;
    for (int i = 1; i <= n; ++i) {
        double t;
        cout << "t" << i << "=";
        cin >> t;
        if (!cin || t < 0) {
            cerr << "Service time must be non-negative" << endl;
            return 1;
        }
        service.push(t);
    }

    vector<double> stay;
    double finish = 0.0;
    double minService = service.front();
    int minService_i = 1;
    int i = 0;

    while (!service.empty()) {
        double t = service.front();
        service.pop();
        double arrival = static_cast<double>(i);
        double start = (finish > arrival) ? finish : arrival;
        finish = start + t;
        stay.push_back(finish - arrival);
        if (t < minService) {
            minService = t;
            minService_i = i + 1;
        }
        ++i;
    }

    int maxStay_i = 0;
    for (int k = 0; k < n; ++k) {
        cout << "c" << k + 1 << "=" << stay[k] << endl;
        if (stay[k] > stay[maxStay_i]) {
            maxStay_i = k;
        }
    }

    cout << "Shortest service time is for customer #" << minService_i << " (" << minService << " min)" << endl;
    cout << "Longest time in queue is for customer #" << maxStay_i + 1 << " (" << stay[maxStay_i] << " min)" << endl;

    return 0;
}
