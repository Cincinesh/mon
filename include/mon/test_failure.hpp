//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <string>

// The Monday C++ unit test framework.
namespace mon
{
  // A test failure. They're meant to be thrown from within test_case's like
  // exceptions.
  class test_failure
  {
  private:
    std::string file_;

    int line_;

    std::string text_;

  public:
    // Constructs a new test_failure with the given properties.
    test_failure(const std::string& file, int line, const std::string& text);

    // Returns the name of the file this test_failure was thrown from.
    std::string file() const;

    // Returns the line number this test_failure was thrown from.
    int line() const;

    // Returns the text associated with this test_failure.
    std::string text() const;
  };
}
