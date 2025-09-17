#pragma once

#include <stdexcept>

class Calculator {
public:
    int Add(int a, int b) const noexcept;
    int Sub(int a, int b) const noexcept;
    int Mul(int a, int b) const noexcept;
    int Div(int a, int b) const;
};