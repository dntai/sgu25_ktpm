#include <iostream>
#include "lib/math_lib.h"
using namespace std;

int main() {
    int a, b, c, vmax;
    cin >> a >> b >> c;
    vmax = findMax(a, b, c);
    cout << "Max value is: " << vmax << endl;
    return 0;
}