//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

// The Monday C++ unit test framework.
namespace mon
{
  // Utility class for running test_case's.
  class test_runner
  {
    test_runner() = delete;
    test_runner(const test_runner&) = delete;
    ~test_runner() = delete;
    test_runner& operator=(const test_runner&) = delete;

  public:
    // Runs all test_case's that were constructed with
    // should_add_to_global_collection. Returns EXIT_SUCCESS on success and
    // EXIT_FAILURE otherwise.
    static int run_all();
  };
}
