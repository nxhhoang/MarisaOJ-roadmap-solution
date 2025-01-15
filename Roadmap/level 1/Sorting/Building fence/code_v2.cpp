#include <bits/stdc++.h>
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
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<pair<int, int>> AB;
    multiset<int> B;

    FOR(i, 0, n) cin >> A[i];
    FOR(i, 0, n)
    {
        int k;
        cin >> k;
        AB.push_back(make_pair(A[i], k));
        B.insert(k);
    }
    sort(all(AB));

    cout << *B.rbegin() << " ";
    int maxV = INT_MIN;
    ll total = 0;

    for (int i = n - 1; i >= 1; i--)
    {
        total += AB[i].first;
        B.erase(B.find(AB[i].second));
        maxV = max(AB[i].second - AB[i].first, maxV);
        cout << max(total + *B.rbegin(), total + maxV + AB[i - 1].first) << " ";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
