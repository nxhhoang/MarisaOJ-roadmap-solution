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
    vector<int> Asau(n, 1);
    vector<int> eras(MAXN, 1);
    map<int, int> mp;

    FOR(i, 0, n) cin >> A[i];
    int ptr = 0;
    for (int i = 2; i < MAXN; i++) {
        if (eras[i]) {
            eras[ptr++] = i;
            for (ll j = 1ll * i * i; j < MAXN; j += i) eras[j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; 1ll * eras[j] * eras[j] <= A[i]; j++) {
            int prime = eras[j];
            int cnt = 0;
            while(A[i] % prime == 0) {
                A[i] /= prime;
                cnt++;
            }
            if (cnt % 2) Asau[i] *= prime;
        }
        if (A[i] > 1) Asau[i] *= A[i];
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += mp[Asau[i]];
        mp[Asau[i]]++;
    }

    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
