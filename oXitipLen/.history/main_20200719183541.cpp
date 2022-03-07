// This is the main C++ program file of the ITIP CLI frontend.

#include <iostream>     // cin/cerr etc ...
#include <string>       // getline
#include <vector>       // vector
#include <iterator>     // back_inserter

#include "citip.hpp"
#include "common.hpp"

using util::quoted;
using util::line_iterator;


int main (int argc, char *argv[])
try
{
    using namespace std;

    vector<string> expr;

    bool use_stdin = argc == 1;

    if (string(argv[argc-1]) == "-") {
        --argc;
        use_stdin = true;
    }

    copy(argv+1, argv+argc, back_inserter(expr));

    if (use_stdin) {
        copy(line_iterator(cin), line_iterator(), back_inserter(expr));
    }
//printf("main:expr.size()=%d\n",(int) expr.size());
    //bool success = check(parse(expr));
    int success = parse(expr).var_names.size();

    if (success) {
        cerr << success << endl;
        return success;
    } else {
        cerr << "0" << endl;
        return 1;
    }


 //   cerr << "The information theoretic expression is either:\n"
  //      << "    1. FALSE, or\n"
   //     << "    2. A non-Shannon type expression/inequality" << endl;
//    return 1;
}
catch (std::exception& e)
{
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 2;
}
// force stack unwinding
catch (...)
{
    std::cerr << "UNKNOWN ERROR - aborting." << std::endl;
    return 3;
}
