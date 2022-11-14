#include <iostream>
using namespace std;


int main() {
    double n;
    scanf("%lf", &n);
    double l = -100.0, r= 100.0;
    while(r-l>1e-8) {
        double mid = (l+r)/2;
        if(mid*mid*mid < n) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    printf("%.6lf", l);
}