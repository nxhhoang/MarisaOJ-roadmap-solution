// nxxhoang - the dreamer
#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set
#define ub upper_bound
#define lb lower_bound

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll inf = 2e18;
const int NN = 10;
const int MAXSIZE = 1e5 + 5;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;
const int dx[] = {1, -1, 0, 0}; 
const int dy[] = {0, 0, 1, -1};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> gcdB(n);
    vector<int> gcdS(n);

    FOR(i, 0, n) {
        cin >> A[i];
        if (i != 0) {
            gcdB[i] = gcd(gcdB[i - 1], A[i - 1]);
        } else gcdB[0] = A[0];
    }
    int maxV = 1;

    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1) {
            gcdS[i] = gcd(gcdS[i + 1], A[i + 1]);
        } else gcdS[n - 1] = A[n - 1];
    }

    for (int i = 1; i < n - 1; i++) {
        maxV = max(maxV, gcd(gcdB[i], gcdS[i]));
    }
    maxV = max(maxV, max(gcdB[n - 1], gcdS[0]));

    cout << maxV << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
