#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const int N = 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> preSum(n + 1, 0);
    FOR(i, 0, n) {
        cin >> arr[i];
        preSum.at(i + 1) = preSum[i] + arr[i]; 
    } 
    int maxSum = abs(preSum[n] - preSum[0] * 2);
    FOR(i, 0, n){
        maxSum = max(maxSum, abs(preSum[n] - preSum[i] * 2));
    }
    cout << maxSum <<endl;
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
