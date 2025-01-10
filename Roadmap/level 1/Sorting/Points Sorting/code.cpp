#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define pb push_back
#define fi first
#define se second
#define endl '\n'

#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
using namespace std;
using ll = long long;

const ll inf = 2e18;
const int N = 10;
const int MAXSIZE = 1e5;

void mergeSort(vector<vector<int>>& vec, int l, int mid, int r){
    int i = l;
    int j = mid + 1;
    vector<vector<int>> vl;

    while(i <= mid && j <= r){
        if (vec[i][0] > vec[j][0]) vl.push_back(vec[j++]);
        else if (vec[i][0] == vec[j][0]) {
            if (vec[i][1] > vec[j][1]) vl.push_back(vec[j++]);
            else if (vec[i][1] == vec[j][1]) {
                if (vec[i][2] > vec[j][2]) vl.push_back(vec[j++]);
                else vl.push_back(vec[i++]);
            }
            else vl.push_back(vec[i++]);
        } else vl.push_back(vec[i++]);
    }

    while(i <= mid){
        vl.push_back(vec[i++]);
    }

    while(j <= r){
        vl.push_back(vec[j++]);
    }

    for(int k = l; k <= r; k++) vec[k] = vl[k - l];
}

void merge(vector<vector<int>>& vec, int l, int r){
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge(vec, l, mid);
        merge(vec, mid + 1, r);
        mergeSort(vec, l, mid, r);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(3));
    FOR(i, 0, n) FOR(j, 0, 3) cin >> vec[i][j];
    merge(vec, 0, n - 1);
    FOR(i, 0, n){
        FOR(j, 0, 3) cout << vec[i][j] << " ";
        cout << endl;
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
