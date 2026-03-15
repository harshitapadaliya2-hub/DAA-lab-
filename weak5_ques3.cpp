#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;

    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int i = 0, j = 0;
    bool found = false;

    while (i < m && j < n) {
        if (a[i] == b[j]) {
            cout << a[i] << " ";
            found = true;
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    if (!found)
        cout << "No Common Elements";

    return 0;
}
