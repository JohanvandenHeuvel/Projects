#include "../../std_lib_facilities.h"

int main()
{
	string disliked_1 = "Broccoli";
	string disliked_2 = "Tank";
	string disliked_3 = "Auto";

	vector<string> words;

	for (string input; cin >> input;)
		words.push_back(input);
	cout << "Number of words: " << words.size() << '\n';

	sort(words);

	for (int i = 0; i < words.size(); i++)
	{
		if (words[i] == disliked_1 || words[i] == disliked_2 || words[i] == disliked_3)
		{
			cout << "You dislike the word '" << words[i] << "'\n";
		}
	}

	keep_window_open();
	return 0;
}