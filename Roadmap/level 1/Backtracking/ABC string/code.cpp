#include<iostream>
using namespace std;

void AB(string s, int i){
	if(i == s.size()) {
		cout << s << endl;
		return;
	}
	for (int j = 0; j < 3; j++){
		s[i] = j + 'A';
		if (i!=0) {
			if (s[i] == s[i - 1]) continue;
		}
		AB(s, i + 1);
	}
}

int main(){
	int n;
	cin >> n;
	string m(n, '1');
	AB(m, 0);
	return 0;
}
