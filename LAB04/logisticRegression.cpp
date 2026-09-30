#include <iostream>
#include <cmath>
using namespace std;

double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

int main() {
    double X[] = {1, 2, 3, 4, 5, 6};
    int Y[] = {0, 0, 0, 1, 1, 1};
    int n = 6;

    double w = 0, b = 0;
    double lr = 0.1;
    int epochs = 1000;

    // Gradient Descent
    for (int e = 0; e < epochs; e++) {
        double dw = 0, db = 0;

        for (int i = 0; i < n; i++) {
            double z = w * X[i] + b;
            double y_pred = sigmoid(z);

            double error = y_pred - Y[i];

            dw += error * X[i];
            db += error;
        }

        dw /= n;
        db /= n;

        w = w - lr * dw;
        b = b - lr * db;
    }

    cout << "Trained Weight: " << w << endl;
    cout << "Trained Bias: " << b << endl;
    double x;
    cout << "Enter new input: ";
    cin >> x;

    double probability = sigmoid(w * x + b);

    cout << "Probability: " << probability << endl;

    if (probability >= 0.5)
        cout << "Class 1";
    else
        cout << "Class 0";

    return 0;
}