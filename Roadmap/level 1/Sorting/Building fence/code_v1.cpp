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
    multiset<pair<int, int>> AB;
    multiset<pair<int, int>> BA;

    FOR(i, 0, n)
    cin >> A[i];
    FOR(i, 0, n)
    {
        int k;
        cin >> k;
        AB.insert(make_pair(A[i], k));
        BA.insert(make_pair(k, A[i]));
    }

    cout << BA.rbegin()->first << " ";
    priority_queue<int> maxHeap;
    ll total = 0;

    for (auto ind = AB.rbegin(); ind != AB.rend() && BA.size() > 1; ind++)
    {
        auto it = ind;
        total += ind->first;
        BA.erase(BA.find(make_pair(ind->second, ind->first)));
        maxHeap.push((ind->second - ind->first));
        cout << max(total + BA.rbegin()->first, total + maxHeap.top() + (++it)->first) << " ";
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
