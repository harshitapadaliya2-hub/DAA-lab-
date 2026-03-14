#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
long long comparisons = 0, swaps = 0;
int partition(vector<int> &a, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);
    swaps++;
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
            swaps++;
        }
    }

    swap(a[i + 1], a[high]);
    swaps++;
    return i + 1;
}
void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}
int main() {
    srand(time(0));
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        comparisons = 0;
        swaps = 0;
        quickSort(a, 0, n - 1);
        for (int x : a)
            cout << x << " ";
        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }
}
