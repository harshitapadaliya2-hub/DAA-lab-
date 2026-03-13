#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int K;
        cin >> K;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(arr[i] - arr[j]) == K)
                    count++;
            }
        }

        cout << count << endl;
    }
    return 0;
}
