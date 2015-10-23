//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/mon/issues

#pragma once

#include <string>

namespace mon
{
    class test_case
    {
    public:
        using function_ptr_t = void(*)();

    private:
        std::string file_;

        int line_;

        std::string name_;

        function_ptr_t function_ptr_;

    public:
        test_case(
            const std::string& file,
            int line,
            const std::string& name,
            function_ptr_t function_ptr,
            bool should_add_to_test_runner = false);

        std::string file() const;

        int line() const noexcept;

        std::string name() const;

        function_ptr_t function_ptr() const noexcept;

        void run() const;

        static void fail(
            const std::string& file,
            int line,
            const std::string& text);
    };
}

#define TEST_CASE(name) \
namespace TEST_CASE_##name \
{ \
    void function_(); \
    mon::test_case TEST_CASE_##name( \
        __FILE__, __LINE__, "TEST_CASE("#name")", &function_, true); \
} \
void TEST_CASE_##name::function_()

#define test_assert(condition) static_cast<void>( \
    static_cast<bool>(condition) \
    || (mon::test_case::fail( \
        __FILE__, __LINE__, "test_assert("#condition") failed"), 0))

#define test_fail(info) \
    mon::test_case::fail( \
        __FILE__, __LINE__, "test_fail("#info")")
