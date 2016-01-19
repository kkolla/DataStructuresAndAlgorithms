#include "numberAndCharecters.h"

double squareroot(double input)
{
    if (input < 0 || input == 0 || input == 1)  return input;
    double low = 0, high = (input < 1) ? 1 : input;
    double precision = 0.001;
    while (abs(high - low) > precision) {
        double mid = (low + high)/2;
        double midsqr = mid * mid;
        if (abs(midsqr - input) < precision) return mid;
        if (midsqr > input) {
            high = mid;
        } else if (midsqr < input) {
            low = mid;
        }
    }
    return high;
}
