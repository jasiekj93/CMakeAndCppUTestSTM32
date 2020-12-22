#include <CppUTest/TestHarness.h>

#include <libFoo/Application/Application.hpp>

TEST_GROUP(ApplicationTest)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

TEST(ApplicationTest, OneArgument)
{
    const char *arguments[] = {"Foo", "2"};

    auto result = Foo::Application::Run(1, arguments);

    CHECK_EQUAL(1, result);
}

TEST(ApplicationTest, TwoArguments)
{
    const char *arguments[] = {"Foo", "2"};

    auto result = Foo::Application::Run(2, arguments);

    CHECK_EQUAL(0, result);
}

TEST(ApplicationTest, TwoArguments_NotANumber)
{
    const char *arguments[] = {"Foo", "text"};

    auto result = Foo::Application::Run(2, arguments);

    CHECK_EQUAL(1, result);
}