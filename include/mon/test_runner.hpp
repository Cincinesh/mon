//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/mon/issues

#pragma once

namespace mon {

class test_case;

namespace test_runner
{
  void add(const test_case* tcase);

  int run_all() noexcept;
}

}
