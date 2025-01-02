#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define umap unordered_map
#define uset unordered_set

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
    vector<pair<int, int>> nguyen_mau(n);

    FOR(i, 0, n)
        cin >> nguyen_mau[i].first >> nguyen_mau[i].second;
    sort(all(nguyen_mau));

    ll ans = LLONG_MAX;
    do
    {
        vector<pair<int, int>> ab = nguyen_mau;

        int i = 0;
        int j = 0;
        ll sum = 0;
        queue<int> labeled;

        while (i < n && j < n)
        {
            if (labeled.empty())
            {
                if (i <= j) sum += ab[i++].first;
                else labeled.push(j++);
            }
            else
            {
                if (ab[i].first == ab[labeled.front()].second)
                {
                    labeled.push(j++);
                    labeled.pop();
                    sum += ab[i++].first;
                }
                else if (ab[i].first > ab[labeled.front()].second)
                {
                    ab[i].first -= ab[labeled.front()].second;
                    sum += ab[labeled.front()].second;
                    labeled.pop();
                }
                else
                {
                    ab[labeled.front()].second -= ab[i].first;
                    sum += ab[i++].first;
                }
            }
        }
        while (j < n) labeled.push(j++);
        while(!labeled.empty()){
            sum += ab[labeled.front()].second;
            labeled.pop();
        }

        ans = min(ans, sum);

    } while (next_permutation(nguyen_mau.begin(), nguyen_mau.end()));
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
