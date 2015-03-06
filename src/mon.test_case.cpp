//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mon/test_case.hpp>
#include <string>
#include <mon/test_failure.hpp>
#include <mon/test_runner.hpp>

using namespace std;

namespace mon {

test_case::test_case(
    const string& file,
    int line,
    const string& name,
    function_ptr_t function_ptr,
    bool should_add_to_test_runner)
  : file_(file),
    line_(line),
    name_(name),
    function_ptr_(function_ptr) {
  if (should_add_to_test_runner) {
    test_runner::add(this);
  }
}

string test_case::file() const {
  return file_;
}

int test_case::line() const noexcept {
  return line_;
}

string test_case::name() const {
  return name_;
}

test_case::function_ptr_t test_case::function_ptr() const noexcept {
  return function_ptr_;
}

void test_case::run() const {
  function_ptr_();
}

void test_case::fail(
    const string& file,
    int line,
    const string& text) {
  throw test_failure(file, line, text);
}

}
