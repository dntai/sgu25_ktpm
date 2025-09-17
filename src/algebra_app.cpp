#include <iostream>
#include "lib/algebra.h"

int main() {
    Algebra alg;
    auto sqr = alg.squareTwo(5);

    std::cout << "Result: " << sqr << std::endl;
    return 0;
}