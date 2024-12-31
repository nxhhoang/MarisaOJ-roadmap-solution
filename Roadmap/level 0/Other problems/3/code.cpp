#include <iostream>
using namespace std;

long long dem(long long arr[], int n) {
    long long sum = 0;
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        switch (arr[i] % 3) {
            case 1:
                sum += y;
                x++;
                break;
            case 2:
                sum += x;
                y++;
                break;
            default:
                sum += z;
                z++;
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    long long *arr = new long long[n]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << dem(arr, n);
    delete[] arr;
    return 0;
}
