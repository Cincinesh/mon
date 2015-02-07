//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <map>
#include <string>
#include <vector>

// The Monday C++ unit test framework.
namespace mon
{
  // A single test case.
  class test_case
  {
    friend class test_runner;

  public:
    // A test_case function pointer.
    using function_ptr_t = void(*)();

  private:
    static std::map<std::string, std::vector<const test_case*>>&
    global_collection_();

    std::string file_;

    int line_;

    std::string name_;

    function_ptr_t function_ptr_;

  public:
    // Constructs a new test_case with the given properties.
    test_case(
        const std::string& file,
        int line,
        const std::string& name,
        function_ptr_t function_ptr,
        bool should_add_to_global_collection = false);

    // Returns the name of the file this test_case was defined in.
    std::string file() const;

    // Returns the line number this test_case starts on.
    int line() const;

    // Returns the name of this test_case.
    std::string name() const;

    // Returns a pointer to this test_case's function.
    function_ptr_t function_ptr() const;

    // Runs this test_case.
    void run() const;

    // Throws a test_failure from within a test_case.
    static void throw_test_failure(
        const std::string& file,
        int line,
        const std::string& text);
  };
}

// Evaluate to constexpr when the compiler fully support C++11 constexpr, and
// imply const otherwise.
// TODO: Remove this once Visual Studio 2015 fully supports C++11 constexpr.
#ifdef _MSC_VER
#define CONST_OR_CONSTEXPR const
#else
#define CONST_OR_CONSTEXPR constexpr
#endif

// Defines a new TEST_CASE.
#define TEST_CASE(name) \
namespace TEST_CASE_##name \
{ \
  void function_(); \
  ::mon::test_case TEST_CASE_##name( \
      __FILE__, __LINE__, "TEST_CASE("#name")", &function_, true); \
} \
void TEST_CASE_##name::function_()

// Checks the given condition and throws a test_failure if the condition isn't
// true.
#define test_assert(condition) static_cast<void>( \
  static_cast<bool>(condition) \
  || (::mon::test_case::throw_test_failure( \
      __FILE__, __LINE__, "test_assert("#condition") failed"), 0))

// Throws a test_failure with the given info.
#define test_fail(info) \
  ::mon::test_case::throw_test_failure( \
      __FILE__, __LINE__, "test_fail("#info")")
