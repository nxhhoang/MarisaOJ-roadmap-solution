// nxhhoang - the dreamer
// g++ -std=c++11 -Wall -Wextra -O2 B.cpp -o B.exe

// __builtin_popcount(x); - count bit 1
// __builtin_parity(x); nums of 1 (even or odd)
// __builtin_ctz(x); count trailing zeros
// __builtin_clz(x); count leading zeros

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; i++)
#define endl '\n'
#define debug(x) cout << #x << " = " << x << '\n'
#define ub upper_bound // find target < min(value)
#define lb lower_bound // find target <= min(value)
#define fi first
#define se second
#define SIZE(x) (int)(x).size()
#define MASK(x, i) (((x) >> (i)) & 1)

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MSIZE = 2e5 + 5;
const int MAXN = 1e3 + 5;
const ll MOD = 1e9 + 7;
const int N = 2005;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

vector<pii> tele[N];
int val[N];
int mat[N][N];
int dp[N][N];

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            tele[mat[i][j]].push_back({i, j});
            val[mat[i][j]] = MOD;
            dp[i][j] = MOD;
        }
    }

    // priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    queue<pair<ll, pii>> pq;
    pq.push({0, {1, 1}});

    while (SIZE(pq)) {
        auto [vl, xy] = pq.front();
        auto [x, y] = xy;
        pq.pop();

        if (vl > dp[x][y]) continue;
        dp[x][y] = vl;

        for (int i = 0; i < 4; i++) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (a < 1 || b < 1 || a > n || b > n) continue;

            if (dp[a][b] > vl + 1) {
                dp[a][b] = vl + 1;
                pq.push({dp[a][b], {a, b}});
            }
        }

        if (val[mat[x][y]] > vl + 1) {
            val[mat[x][y]] = vl + 1;
            for (auto [a, b] : tele[mat[x][y]]) {
                if (a == x && b == y) continue;
                if (dp[a][b] <= vl + 1) continue;
                dp[a][b] = vl + 1;
                pq.push({dp[a][b], {a, b}});
            }
        }
    }

    cout << dp[n][n] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout);
    int t = 1;
    // cin >> t; /// DLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL

    while (t--)
    {
        solve();
    }

    return 0;
}

// accumulate -> sum of array
// max_element -> max of array
// min_element -> min of array
// minmax_element -> pair<min, max>
// all_of -> check condition for all eles
// any_of -> check condition for some eles
// none_of -> no element satisfies
// count -> count(a.begin(), a.end(), 5) -> ele == 5 counts
// count_if
// find -> find(a.begin(), a.end(), 8);
// find_if
// transform -> map in python
//// transform(a.begin(), a.end(), b.begin(), [](int x){ return x * 2; });


// Pre-submit:
// Write a few simple test cases if sample is not enough.
// Are time limits close? If so, generate max cases.
// Is the memory usage fine?
// Could anything overflow?
// Make sure to submit the right file.


// Wrong answer:
// Print your solution! Print debug output, as well.
// Are you clearing all data structures between test cases?
// Can your algorithm handle the whole range of input?
// Read the full problem statement again.
// Do you handle all corner cases correctly?
// Have you understood the problem correctly?
// Any uninitialized variables?
// Any overflows?
// Confusing N and M, i and j, etc.?
// Are you sure your algorithm works?
// What special cases have you not thought of?
// Are you sure the STL functions you use work as you think?
// Add some assertions, maybe resubmit.
// Create some testcases to run your algorithm on.
// Go through the algorithm for a simple case.
// Go through this list again.
// Explain your algorithm to a teammate.
// Ask the teammate to look at your code.
// Go for a small walk, e.g. to the toilet.
// Is your output format correct? (including whitespace)
// Rewrite your solution from the start or let a teammate do it.
// SORTING can lose the initial position of elements

// If the output includes (Your answer will be considered correct if its absolute or relative error does not exceed) 
// => use fixed and setprecision


// Runtime error:
// Have you tested all corner cases locally?
// Any uninitialized variables?
// Are you reading or writing outside the range of any vector?
// Any assertions that might fail?
// Any possible division by 0? (mod 0 for example)
// Any possible infinite recursion?
// Invalidated pointers or iterators?
// Are you using too much memory?
// Debug with resubmits (e.g. remapped signals, see Various).


// Time limit exceeded:
// Do you have any possible infinite loops?
// What is the complexity of your algorithm?
// Use the wrong variable (n -> q or q -> n)
// Are you copying a lot of unnecessary data? (References)
// How big is the input and output? (consider scanf)
// Avoid vector, map. (use arrays/unordered_map)
// What do your teammates think about your algorithm?


// Memory limit exceeded:
// What is the max amount of memory your algorithm should need?
// Are you clearing all data structures between test cases?

// Use case tree to consider all cases easier
// Use case tree to consider all cases easier
// Use case tree to consider all cases easier
// Use case tree to consider all cases easier
// Use case tree to consider all cases easier
