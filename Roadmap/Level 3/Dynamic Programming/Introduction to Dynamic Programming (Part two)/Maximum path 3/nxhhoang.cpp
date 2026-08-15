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
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
const int N = 2005;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int dxx[] = {0, 1};
const int dyy[] = {1, 0};

const int NN = 55;
int mat[NN][NN];
int dp[NN][NN][NN][NN];

struct Node {
    ll val;
    int x, y, z, t;

    bool operator<(const Node A) const {
        return A.val > val;
    } 
};

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
        }
    }    

    priority_queue<Node> pq;
    pq.push({mat[1][1], 1, 1, 1, 1});

    auto check = [&](int x, int y, int z, int t, ll value) -> void {
        if (!(1 <= x && x <= n && 1 <= y && y <= n && 1 <= z && z <= n && 1 <= t && t <= n)) return;
        if (dp[x][y][z][t] < value) {
            dp[x][y][z][t] = dp[z][t][x][y] = value;
            pq.push(Node{value, x, y, z, t});
        }
    };

    while (SIZE(pq)) {
        auto [val, x, y, z, t] = pq.top();
        pq.pop();

        if (val < dp[x][y][z][t]) continue;
        dp[x][y][z][t] = val;

        if (x == z && y == t) {
            check(x + 1, y, x, y + 1, val + mat[x + 1][y] + mat[x][y + 1]);
            check(x, y + 1, x, y + 1, val + mat[x][y + 1]);
            check(x + 1, y, x + 1, y, val + mat[x + 1][y]);
        } else {
            check(x + 1, y, z + 1, t, val + mat[x + 1][y] + mat[z + 1][t]);
            check(x, y + 1, z, t + 1, val + mat[x][y + 1] + mat[z][t + 1]);
            check(x, y + 1, z + 1, t, val + mat[x][y + 1] + mat[z + 1][t] * (!(x == z + 1 && y + 1 == t)));
            check(x + 1, y, z, t + 1, val + mat[x + 1][y] + mat[z][t + 1]);
        }
    }

    cout << dp[n][n][n][n] << endl;
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
// Check Custom comparable function of max heap or min heap (< <=> >) 

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
