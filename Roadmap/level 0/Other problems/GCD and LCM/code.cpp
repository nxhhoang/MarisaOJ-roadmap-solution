#include <iostream>
#include <cmath>
using namespace std;

int GCD(long long a, long long b) {
	if (b % a == 0) return a;
	return GCD(b % a, a);
}

int main() {
	long long a,b;
	cin >> a>>b;
	int k = GCD(a, b);
	long long tich = (a/k) * b;
	cout << k<< " " << tich;
}
