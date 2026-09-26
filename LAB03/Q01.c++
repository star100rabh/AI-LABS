// regression code 
#include <iostream>
using namespace std;
int main() {
    double x1[] = {1000, 1500, 2000, 2500};
    double x2[] = {2, 3, 4, 5};
    double y[]  = {200, 300, 400, 500};

    int n = 4;
    double w1 = 0, w2 = 0, b = 0;
    double lr = 0.000001;
    for (int epoch=0; epoch < 10000; epoch++) {
        double dw1 = 0, dw2 = 0, db = 0;

        for (int i = 0; i < n; i++) {
            double pred = w1 * x1[i] + w2 * x2[i] + b;
            double error = pred - y[i];

            dw1 += error * x1[i];
            dw2 += error * x2[i];
            db += error;
        }

        w1 -= lr * dw1 / n;
        w2 -= lr * dw2 / n;
        b  -= lr * db / n;
    }

    cout << "w1 = " << w1 << endl;
    cout << "w2 = " << w2 << endl;
    cout << "b  = " << b << endl;

    double size = 1800, bedrooms = 3;
    double price = w1 * size + w2 * bedrooms + b;

    cout << "Predicted Price = " << price << endl;

    
}