#include <string>
#include <omp.h>

#include "timer.hpp"
#include "solver.hpp"
#include "test_runner.hpp"

using namespace std;

void SimpleTestSeq() {
    LCSSolver solver;
    ASSERT_EQUAL(solver.SolveLessMemory(1, "a", "b"), 0);
    ASSERT_EQUAL(solver.SolveLessMemory(3, "acb", "abc"), 2);
    ASSERT_EQUAL(solver.SolveLessMemory(4, "acbe", "acbe"), 4);
    ASSERT_EQUAL(solver.SolveLessMemory(5, "abcba", "cabab"), 3);
}

void SimpleTestParallel() {
    LCSSolver solver;
    ASSERT_EQUAL(solver.SolveParallelLessMemory(1, "a", "b"), 0);
    ASSERT_EQUAL(solver.SolveParallelLessMemory(3, "acb", "abc"), 2);
    ASSERT_EQUAL(solver.SolveParallelLessMemory(4, "acbe", "acbe"), 4);
    ASSERT_EQUAL(solver.SolveParallelLessMemory(5, "abcba", "cabab"), 3);
}

void LargeTest() {
    srand(time(NULL));
    const int N = 3e4;
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
    int res1, res2;
    {
        LOG_DURATION("parallel");
        res2 = solver.SolveParallelLessMemory(N, s1, s2);
    }
    {
        LOG_DURATION("sequential");
        res1 = solver.SolveLessMemory(N, s1, s2);
    }

    ASSERT_EQUAL(res1, res2);
}

void Testing() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTestSeq);
    RUN_TEST(tr, SimpleTestParallel);
    RUN_TEST(tr, LargeTest);
}

int main(int argc, char* argv[]) {

    omp_set_dynamic(false);
    omp_set_num_threads(8);

    Testing();

    return 0;
}