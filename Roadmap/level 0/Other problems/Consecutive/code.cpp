#include<iostream>
#include<cmath>
using namespace std;

int ketqua(long long n){
	int k=sqrt(2*n);
	int dem=0;
    double t=0;
    for (int i=2; i<=k; i++){
        t=(double)(((double)n*2/i) - (i-1))/2;
		if (t-floor(t)<=0.0000001) dem++;
    }
	return dem;
}

int main(){ 
    long long n;
	cin >> n;
	cout <<ketqua(n);
}
