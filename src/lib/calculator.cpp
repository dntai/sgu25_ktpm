#include "calculator.h"

int Calculator::Add(int a, int b) const noexcept {
    return a + b;
}

int Calculator::Sub(int a, int b) const noexcept {
    return a - b;
}

int Calculator::Mul(int a, int b) const noexcept {
    return a * b;
}

int Calculator::Div(int a, int b) const {
    if (b == 0) {
        throw std::runtime_error("Divide by zero");
    }
    return a / b;
}