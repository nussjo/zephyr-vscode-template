#include <gtest/gtest.h>
#include <cmdline.h>
#include <posix_board_if.h>
#include <span>

int main()
{
    // Arguments are passed like this
    // zephyr.elf <path> [<zephyr_arg1> <zephyr_arg2>] [-testargs] [<gtest_arg1> <gtest_arg2>]
    //
    // InitGoogleTest should be called with
    // <path> [<gtest_arg1> <gtest_arg2>]
    //
    int argcAll = 0;
    char **argvAll = nullptr;
    native_get_cmd_line_args(&argcAll, &argvAll);
    if (argcAll > 0 && argvAll)
    {
        int argcTest = 0;
        char **argvTest = nullptr;
        native_get_test_cmd_line_args(&argcTest, &argvTest);
        ++argcTest;
        if (argcTest == 1)
        {
            ::testing::InitGoogleTest(&argcTest, argvAll);
        }
        else
        {
            auto args = std::span(argvAll, argcAll);
            const auto startIndexForGTest = argcAll - argcTest;
            args[startIndexForGTest] = args.front();
            ::testing::InitGoogleTest(&argcTest, &args[startIndexForGTest]);
        }
    }
    else
    {
        ::testing::InitGoogleTest();
    }
    const int exitCode = RUN_ALL_TESTS();
    posix_exit(exitCode);
    return 0;
}
