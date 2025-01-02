#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using ll = long long;
using namespace std;

const int N = 20;

void solve()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    FOR(i, 0, n) cin >> A[i];
    ll current_sum = A[0];
    ll exact_sum = A[0];
    for (int i = 1; i < n; i++) {
        current_sum += A[i];
        if (current_sum < A[i]) current_sum = A[i];
        exact_sum = max(exact_sum, current_sum);
    }
    cout << exact_sum << endl;
    return;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
