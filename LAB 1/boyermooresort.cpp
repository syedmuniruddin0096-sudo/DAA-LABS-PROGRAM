#include <iostream>
#include <string>
using namespace std;

#define NO_OF_CHARS 256

// Build bad character table
void badCharHeuristic(string pat, int size, int badchar[]) {
    for (int i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (int i = 0; i < size; i++)
        badchar[(int)pat[i]] = i;
}

// Boyer Moore search function
void search(string txt, string pat) {
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);

    int shift = 0;

    while (shift <= (n - m)) {
        int j = m - 1;

        // Compare from right to left
        while (j >= 0 && pat[j] == txt[shift + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << shift << endl;
            shift += (shift + m < n) ? m - badchar[txt[shift + m]] : 1;
        } else {
            shift += max(1, j - badchar[txt[shift + j]]);
        }
    }
}

int main() {
    string text = "ABAAABCD";
    string pattern = "ABC";

    search(text, pattern);

    return 0;
}
