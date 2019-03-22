#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <omp.h>

#include "timer.h"

using namespace std;

const int N = 3e4;

void calcLCS(const string& s1, const string& s2, vector<vector<int>>& dp) {
    dp[0][0] = s1[0] == s2[0];
    for (int i = 1; i < N; ++i) {
        dp[i][0] = s1[i] == s2[0] ? 1 : dp[i - 1][0];
    }
    for (int j = 1; j < N; ++j) {
        dp[0][j] = s1[0] == s2[j] ? 1 : dp[0][j - 1];
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < N; ++j) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

void calcLCS_Parallel(const string& s1, const string& s2, vector<vector<int>>& dp) {

    dp[0][0] = s1[0] == s2[0];
    for (int i = 1; i < N; ++i) {
        dp[i][i] = s1[i] == s2[0] ? 1 : dp[i - 1][i - 1];
    }
    for (int j = 1; j < N; ++j) {
        dp[j][0] = s1[0] == s2[j] ? 1 : dp[j - 1][0];
    }

    for (int sum = 2; sum <= N - 1; ++sum) {
#pragma omp parallel for simd safelen(1) schedule(static)
//#pragma omp parallel for schedule(static)
        for (int i = 1; i <= sum - 1; ++i) {
            int j = sum - i;
            if (s1[i] == s2[j]) {
                dp[sum][i] = dp[sum - 2][i - 1] + 1;
            } else {
                dp[sum][i] = max(dp[sum - 1][i - 1], dp[sum - 1][i]);
            }
        }
    }

    for (int k = N - 1; k >= 1; --k) {
        int sum = N - 1 + N - k;
#pragma omp parallel for simd safelen(1) schedule(static)
//#pragma omp parallel for schedule(static)
        for (int i = N - k; i < N; ++i) {
            int j = sum - i;
            if (s1[i] == s2[j]) {
                dp[sum][i] = dp[sum - 2][i - 1] + 1;
            } else {
                dp[sum][i] = max(dp[sum - 1][i - 1], dp[sum - 1][i]);
            }
        }
    }
}

void calcLCS_Parallel_Memory(const string& s1, const string& s2, vector<vector<int>>& dp) {

    dp[0][0] = s1[0] == s2[0];
    for (int i = 1; i < N; ++i) {
        dp[i][i] = s1[i] == s2[0] ? 1 : dp[i - 1][i - 1];
    }
    for (int j = 1; j < N; ++j) {
        dp[j][0] = s1[0] == s2[j] ? 1 : dp[j - 1][0];
    }

    for (int sum = 2; sum <= N - 1; ++sum) {
#pragma omp parallel for simd safelen(1) schedule(static)
//#pragma omp parallel for schedule(static)
        for (int i = 1; i <= sum - 1; ++i) {
            int j = sum - i;
            if (s1[i] == s2[j]) {
                dp[sum][i] = dp[sum - 2][i - 1] + 1;
            } else {
                dp[sum][i] = max(dp[sum - 1][i - 1], dp[sum - 1][i]);
            }
        }
    }

    for (int k = N - 1; k >= 1; --k) {
        int sum = N - 1 + N - k;
#pragma omp parallel for simd safelen(1) schedule(static)
//#pragma omp parallel for schedule(static)
        for (int i = N - k; i < N; ++i) {
            int j = sum - i;
            if (s1[i] == s2[j]) {
                dp[sum][i] = dp[sum - 2][i - 1] + 1;
            } else {
                dp[sum][i] = max(dp[sum - 1][i - 1], dp[sum - 1][i]);
            }
        }
    }
}

void check(vector<vector<int>>& dp1, vector<vector<int>>& dp2) {
    bool isCorrect = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (dp1[i][j] != dp2[i + j][i]) {
                isCorrect = false;
                break;
            }
        }
    }
    if (isCorrect) {
        cout << "OK";
    } else {
        cout << "WRONG";
    }
}

int main(int argc, char* argv[]) {

//    vector<vector<int>> dp1(N, vector<int>(N, 0));
    vector<vector<int>> dp2(N + N);
//    vector<vector<int>> dp2(N + N, vector<int>(N, 0));
    for (int i = 0; i < N + N; ++i) {
        dp2[i].resize(min(i + 1, N));
//        dp2[i].resize(N);
    }
    string s1, s2;

    srand(time(NULL));
    s1.reserve(N);
    s2.reserve(N);
    omp_set_dynamic(false);
    omp_set_num_threads(16);

    for (int i = 0; i < N; ++i) {
        char ch;
        ch = static_cast<char>(rand() % 26) + 'a';
        s1.push_back(ch);
        ch = static_cast<char>(rand() % 26) + 'a';
        s2.push_back(ch);
    }

    cout.precision(6);
   // if (argc > 1)
    {
       // if (strcmp(argv[1], "sequential") == 0)
        {
//            LOG_DURATION("seq");
//            calcLCS(s1, s2, dp1);
        } //else if (strcmp(argv[1], "par")  == 0)
        {
            LOG_DURATION("parallel")
            calcLCS_Parallel(s1, s2, dp2);
        }
    }

//    check(dp1, dp2);

    return 0;
}