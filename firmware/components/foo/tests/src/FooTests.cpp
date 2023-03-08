#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <foo/hello.hpp>

TEST(FooTest, RequireReturnZero)
{
    const auto result = foo::sayHello();

    EXPECT_EQ(0, result);
}
