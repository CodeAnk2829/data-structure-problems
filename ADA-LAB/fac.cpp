#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countAnagrams(string text, string word)
{
	int n = text.size(), m = word.size();
	unordered_map<char, int> freqWord, freqText;
	int count = 0;

	// Create frequency map of characters in the word
	for (char c : word)
		freqWord[c]++;

    for(auto &t : freqWord) {
        cout << t.first << " " << t.second << endl;
    }
	// Sliding window approach
	for (int i = 0; i < n; i++) {
		// Add character to frequency map
		freqText[i]++;

		// Remove character that went out of window
		if (i >= m) {
			if (freqText[text[i - m]] == 1)
				freqText.erase(text[i - m]);
			else
				freqText[text[i - m]]--;
		}

		// Compare frequency maps
		if (i >= m - 1 && freqText == freqWord)
			count++;
	}

	return count;
}

int main()
{
	string text = "forxxorfxdofr";
	string word = "for";
	cout << countAnagrams(text, word) << endl;

	return 0;
}
// This code is contributed by rudra1807raj
