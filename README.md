The Monday C++ Unit Test Framework
==================================
The Monday C++ Unit Test Framework is a small and easy to use test framework.

Requirements
------------
Monday requires Visual Studio 2015 or a fully C++11 compliant compiler such as
GCC 4.8.1 or Clang 3.1.

Usage
-----
To make a test suite using Monday, simply make sure the `include` directory in
the root of this project is on your include path and all the `.cpp` files under
the `src` directory are compiled and linked into your executable binary. For GCC
and Clang, you might have to provide the compiler option `-std=c++11` or higher
as well if you aren't already.

With the Monday code hooked in to your test suite, the only thing left to do is
write test files like this:

~~~{.cpp}
#include <mylib/foo.hpp>
#include <mon/test_case.hpp>

using namespace mylib;

// Create an unnamed namespace. This isn't strictly required but avoids test
// name collisions with tests from other files.
namespace
{
    TEST_CASE(bar)
    {
        foo myfoo;
        test_assert(myfoo.bar() == 123);
    }
    
    TEST_CASE(baz)
    {
        foo myfoo;
        try
        {
            myfoo.baz();
            test_fail("myfoo.baz() didn't throw an exception as expected.");
        }
        catch (...)
        {
            return;
        }
    }
}
~~~

That's it! Just make sure to include `<mon/test_case.hpp>` and write
`TEST_CASE()`'s. The `main()` function provided by `src/main.cpp` will
automatically run any `TEST_CASE()` compiled and linked in the same executable.

Monday will treat any exception thrown by a `TEST_CASE()` as a test failure.
Additionally, you can use the macros `test_assert()` and `test_fail()` as shown
above to specify other failure conditions.

The error output format is meant to match that of your C++ compiler, so if you
configure your IDE to run your test suite as a post-link step, it should be able
to highlight test failures in your code as if they were compiler errors.

See [Tuesday](https://github.com/Cincinesh/tue) for an example of a project that
uses Monday.

License
-------
Copyright Jo Bates 2015.

Distributed under the Boost Software License, Version 1.0.

See accompanying file [LICENSE_1_0.txt](LICENSE_1_0.txt) or copy at
http://www.boost.org/LICENSE_1_0.txt.

Bug Reporting
-------------
Please report any bugs, typos, or suggestions to
https://github.com/Cincinesh/mon/issues.
