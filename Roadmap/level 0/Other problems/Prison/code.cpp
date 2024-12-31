#include <stdio.h>
#include <math.h>
using ll = long long;

int namnhuan(ll y) {
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return 1;
    else return 0;
}
int ngaythang(ll n, ll m) {
    int leap = namnhuan(m);
    if (leap == -1 || n < 1 || n>12) return -1;
    else {
        switch (n) {
        case 1:case 3:case 5:case 7:case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        default: if (leap == 1) return 29;
            else return 28;
        }
    }
}
int kngaytieptheo(ll d, ll m, ll y, ll k) {
    for (int i = 1; i <= k; i++) {
        int ngaytrongthang = ngaythang(m, y);
        if (ngaytrongthang == -1 || d<1 || d>ngaytrongthang) return -1;
        else {
            if (d < ngaytrongthang)d++;
            else if (m < 12) {
                d = 1; m++;
            }
            else {
                d = m = 1; y++;
            }
        }
    }
    printf("%lld %lld %lld\n", d, m, y);
    return 1;
}
int main() {
    ll a, b, c, k;
    scanf("%lld", &a);
    scanf("%lld", &k);
    scanf("%lld", &b);
    scanf("%lld", &c);
    ll count = 0;
    if (a > ngaythang(b, c)) {
        k = k + a - ngaythang(b, c);
        a = ngaythang(b, c);
    }
    count = floor(k / 146097);
    k = k % 146097;
    c = c + count * 400;
    kngaytieptheo(a, b, c, k);
}
