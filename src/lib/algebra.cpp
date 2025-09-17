#include "algebra.h"
#include "logger.h"

Algebra::Algebra(const INoise *noise) { noise_ = noise; }

void Algebra::setLogger(ILogger *logger) { logger_ = logger; }

float Algebra::squareTwo(float x) const { return x * x; }

float Algebra::squareTwoNoise(float x) const
{
    if (!noise_)
        throw std::runtime_error("No noise object found!");

    return squareTwo(x) + noise_->addNoise();
}

float Algebra::longOperation(float x) const
{
    bool has_logger = logger_ ? true : false;

    if (has_logger)
        logger_->info("Long operationg starting...");

    float res = squareTwo(x);

    if (has_logger)
        logger_->info("Long operation over...");

    return res;
}