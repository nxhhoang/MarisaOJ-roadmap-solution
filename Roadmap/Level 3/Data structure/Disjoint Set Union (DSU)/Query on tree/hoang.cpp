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

const int MSIZE = 1e5 + 5;
const int MAXN = 4e8 + 5;
const ll MOD = 1e9 + 7;
const int N = 40000;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

struct DSU {
    vector<ll> vec, st;
    
    DSU (int n) {
        vec.resize(n + 1, 0);
        st.resize(n + 1, 0);

        for (int i = 0; i <= n; i++) vec[i] = i, st[i] = 1;
    }

    void make_set(int u) {
        vec[u] = u;
        st[u] = 1;
    }
    
    int find_set(int u) {
        return (vec[u] == u) ? u : (vec[u] = find_set(vec[u]));
    }
    
    void union_set(int u, int v) {
        int a = find_set(u);
        int b = find_set(v);
        if (a != b) {
            if (st[a] > st[b]) swap(a, b);
            vec[a] = b;
            st[b] += st[a];
        }
    }
    
    bool check(int u, int v) {
        return find_set(u) == find_set(v);
    }

    ll cc(int u) {
        return st[find_set(u)];
    }
};

ll val[MSIZE];
vector<vector<pii>> tmp(MSIZE);
vector<int> pa(MSIZE, 0);
multiset<pii> st;
vector<vector<pii>> query(MSIZE);
vector<ll> ans(MSIZE);

void dfs(int u, int p) {
    for (auto [ve, w] : tmp[u]) {
        if (ve == p && u != 1) {
            st.insert({w, u});
            pa[u] = p;
            continue;
        }
        dfs(ve, u);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        tmp[u].push_back({v, w});
        tmp[v].push_back({u, w});
    }
    
    dfs(1, 0);
    
    DSU minV(n + 1), hay(n + 1);

    for (int i = 1; i <= q; i++) {
        int u, k;
        cin >> u >> k;

        query[k].push_back({u, i});
    }
    
    st.insert({MOD, 0});
    for (auto it = next(st.rbegin()), git = st.rbegin(); it != st.rend(); it++) {
        int ve = it->second;
        auto mit = it;
        mit++;
        minV.union_set(ve, pa[ve]);
        
        if (mit == st.rend() || mit->first != it->first) {
            // cout << it->first << " " << minV.cc(ve) << "  " << hay.cc(ve) << endl;
            for (auto [u, pos] : query[it->first]) 
                ans[pos] += minV.cc(u) - hay.cc(u), cout ;

            while (git != mit) hay.union_set(git->second, pa[git->second]), git++; 
        }
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("K-query.inp", "r", stdin);
    // freopen("K-query.ans", "w", stdout)
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
