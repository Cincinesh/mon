//                Copyright Jo Bates 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
//
//     Please report any bugs, typos, or suggestions to
//         https://github.com/Cincinesh/mon/issues

#include <mon/test_runner.hpp>

#include <cstdlib>
#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <mon/test_case.hpp>
#include <mon/test_failure.hpp>

using namespace std;

namespace {
using namespace mon;

map<string, vector<const test_case*>>& test_case_map_() {
  static map<string, vector<const test_case*>> value;
  return value;
}

}

namespace mon {

void test_runner::add(const test_case* tcase) {
  const auto emplace_result = test_case_map_().emplace(
      piecewise_construct,
      forward_as_tuple(tcase->file()),
      forward_as_tuple());
  auto& tcases = emplace_result.first->second;
  tcases.push_back(tcase);
}

int test_runner::run_all() noexcept {
#ifdef _MSC_VER
  const auto preline = "(";
  const auto postline = "): error: ";
#else
  const auto preline = ":";
  const auto postline = ": error: ";
#endif

  int status = EXIT_SUCCESS;

  for (const auto& entry : test_case_map_()) {
    const auto& file = entry.first;
    const auto& tcases = entry.second;

    cout << "Running test cases in " << file << endl;
    for (const auto& tcase : tcases) {
      cout << "  " << tcase->name() << "..." << endl;
      cout.flush();

      bool success = false;
      try {
        tcase->run();
        success = true;
      } catch (const test_failure& f) {
        cerr << f.file() << preline << f.line() << postline
             << f.text() << endl;
      } catch (const exception& e) {
        cerr << tcase->file() << preline << tcase->line() << postline
             << tcase->name() << " threw an exception: "
             << e.what() << endl;
      } catch (...) {
        cerr << tcase->file() << preline << tcase->line() << postline
             << tcase->name() << " threw a non-standard exception" << endl;
      }

      if (success) {
        cout << "  SUCCESS" << endl;
      } else {
        cout << "  FAILURE" << endl;
        status = EXIT_FAILURE;
      }
    }
  }

  return status;
}

}
