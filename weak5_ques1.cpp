#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        vector<int> count(26, 0);
        // Counting occurrences
        for (char c : arr) {
            count[c - 'a']++;
        }
        int maxFreq = 0;
        char maxChar = '\0';
        // Find max occurrence
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxFreq) {
                maxFreq = count[i];
                maxChar = 'a' + i;
            }
        }
        if (maxFreq <= 1) {
            cout << "No Duplicates Present" << endl;
        } else {
            cout << maxChar << "-" << maxFreq << endl;
        }
    }

    return 0;
}
