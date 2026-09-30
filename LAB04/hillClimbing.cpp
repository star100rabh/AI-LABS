#include <iostream>
using namespace std;

int f(int x) {
    return -x * x + 8 * x + 5;
}

int main() {
    int current = 0;

    while (true) {
        int left = current - 1;
        int right = current + 1;
        int best = current;

        if (f(left) > f(best))
            best = left;

        if (f(right) > f(best))
            best = right;

        if (best == current)
            break;

        current = best;
    }

    cout << "Best x = " << current << endl;
    cout << "Maximum value = " << f(current) << endl;

    return 0;
}