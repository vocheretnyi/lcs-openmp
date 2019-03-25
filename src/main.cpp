#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <omp.h>

#include "timer.h"
#include "Solver.h"

using namespace std;

const int N = 3e4;

int main(int argc, char* argv[]) {

    srand(time(NULL));
    cout.precision(6);
    omp_set_dynamic(false);
    omp_set_num_threads(4);

    string s1, s2;
    s1.reserve(N);
    s2.reserve(N);

    for (int i = 0; i < N; ++i) {
        char ch;
        ch = static_cast<char>(rand() % 26) + 'a';
        s1.push_back(ch);
        ch = static_cast<char>(rand() % 26) + 'a';
        s2.push_back(ch);
    }

    LCSSolver solver;
    int a, b, c, d;
   // if (argc > 1)
    {
       // if (strcmp(argv[1], "sequential") == 0)
         //else if (strcmp(argv[1], "par")  == 0)
        {
//            LOG_DURATION("seq");
//            b = solver.Solve(N, s1, s2);
        }
        {
            LOG_DURATION("seq less memory");
            d = solver.SolveLessMemory(N, s1, s2);
        }
        {
//            LOG_DURATION("parallel")
//            a = solver.SolveParallel(N, s1, s2);
        }
        {
            LOG_DURATION("parallel less memory");
            c = solver.SolveParallelLessMemory(N, s1, s2);
        }

    }
    cout << a << endl << b << endl << c << endl << d << endl;
    return 0;
}