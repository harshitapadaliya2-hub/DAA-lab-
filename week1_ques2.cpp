#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int key;
        cin >> key;

        int low = 0, high = n - 1;
        int comparisons = 0;
        bool found = false;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            comparisons++;

            if (arr[mid] == key) {
                found = true;
                break;
            }
            else if (key < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if (found)
            cout << "Present " << comparisons << endl;
        else
            cout << "Not Present " << comparisons << endl;
    }

    return 0;
}
