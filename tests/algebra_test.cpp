#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "algebra.h"

// Mock class cho Logger
class MockLogger : public ILogger
{
public:
    MOCK_METHOD(void, info, (const std::string &), (const, override));
    MOCK_METHOD(void, error, (const std::string &), (const, override));
    MOCK_METHOD(void, debug, (const std::string &), (const, override));

    // virtual void info(const std::string &content) const = 0;
    // virtual void error(const std::string &content) const = 0;
    // virtual void debug(const std::string &content) const = 0;
};

// Mock class cho INoise
class MockNoise : public INoise {
    public:
    MockNoise() : INoise(0.0) {}
    MOCK_METHOD(float, addNoise, (), (const,override));
};

TEST(Algebra, SquareTwo) {
    Algebra alg;

    auto expect = alg.squareTwo(5);
    EXPECT_NEAR(expect, 25.0, 1e-7);
    EXPECT_NEAR(alg.squareTwo(25), 625.0, 1e-7);
}

TEST(Algebra, SquareTwoNoiseThrow) {
    Algebra alg;
    
    EXPECT_THROW(alg.squareTwoNoise(1.0), std::exception);
}

TEST(Algebra, SquareTwoNoise) {
    MockNoise mock_noise;
    Algebra alg(&mock_noise);

    EXPECT_CALL(mock_noise, addNoise).WillOnce(testing::Return(1.0));

    auto res = alg.squareTwoNoise(5);

    EXPECT_NEAR(res, 26.0, 1e-7);
}

TEST(Algebra, testLongOpLogging)
{
    MockLogger mock_logger;

    Algebra obj;

    obj.setLogger(&mock_logger);

    EXPECT_CALL(mock_logger, info(testing::StrEq("Long operationg starting...")));
    EXPECT_CALL(mock_logger, info(testing::StrEq("Long operation over...")));

    auto ret = obj.longOperation(10.0);

    EXPECT_NEAR(ret, 100.0, 1e-8);
}