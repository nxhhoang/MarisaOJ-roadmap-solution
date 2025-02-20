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
const int N = 10;
const int MAXSIZE = 1e5 + 1;
const int MAXN = 1e6 + 1;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> prime(MAXSIZE, 0);

    for (int i = 2; i * i <= MAXSIZE; i++){
        if (prime[i] != -1) for (ll j = 1ll * i * i; j <= MAXSIZE; j += i) prime[j] = -1;
    }

    ll sum = 1;

    while(n--){
        int A;
        cin >> A;
        for (int i = 2; i * i <= A; i++){
            if (prime[i] == -1) continue;
            int cnt = 0;
            while (A % i == 0) {
                A /= i;
                cnt++;
                if (prime[i] < cnt) sum = sum * i % MOD;
            }
            prime[i] = max(prime[i], cnt);
        }

        if (A > 1 && prime[A] < 1) {
            sum = (sum * A) % MOD;
            prime[A] = 1;
        }
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
