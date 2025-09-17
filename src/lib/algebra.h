#pragma once
#include "logger.h"
#include "noise.h"

class Algebra
{
public:
    Algebra() = default;
    Algebra(const INoise *noise);
    void setLogger(ILogger *logger);
    float squareTwo(float x) const;
    float squareTwoNoise(float x) const;
    float longOperation(float x) const;
private:
    // Dependencies
    const INoise *noise_ = nullptr;
    const ILogger *logger_ = nullptr;
};