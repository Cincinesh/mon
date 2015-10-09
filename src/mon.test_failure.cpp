//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/mon/issues

#include <mon/test_failure.hpp>

#include <string>

using namespace std;

namespace mon
{
    test_failure::test_failure(const string& file, int line, const string& text)
    :
        file_(file), line_(line), text_(text)
    {
    }

    string test_failure::file() const
    {
        return file_;
    }

    int test_failure::line() const noexcept
    {
        return line_;
    }

    string test_failure::text() const
    {
        return text_;
    }
}
