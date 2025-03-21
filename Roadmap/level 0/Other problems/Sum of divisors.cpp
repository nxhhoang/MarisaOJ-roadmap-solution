// Link: https://marisaoj.com/problem/17

// Calculate the sum of positive divisors of given integer $n$.

#include <iostream>
#include <cmath>
using namespace std;

long long summ(long long n) {
	if (n == 1) return 1;
	long long sum = 0;
	for (long long i = 1; i * i <= n; i++) {
		if (n % i == 0) { 
			if (i == n / i) sum += i;
			else sum += i + n / i; 
		}
	}
	return sum;
}

int main() {
	long long n;
	cin >> n;
	cout << summ(n);
}
