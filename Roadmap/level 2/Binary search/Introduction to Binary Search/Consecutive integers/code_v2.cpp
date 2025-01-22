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
    vector<int> vec(n);
    int j = 1;
    FOR (i, 0, n) cin >> vec[i];
    sort(all(vec));
    FOR (i, 1, n) if (vec[i - 1] != vec[i]) vec[j++] = vec[i];
    int minAns = 1;
    int k = 0, i = 0;
    while(i < j) {
        while (k < i && vec[i] - vec[k] > n - 1) k++;
        minAns = max(minAns, i - k + 1);
        i++;
    }  
    cout << n - minAns << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
