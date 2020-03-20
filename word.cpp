#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argv, char **argc) {
  map<string, int> words;
  ifstream fin(argc[1]);
  string nextword;

/*<<<<<<< HEAD
  while (fin >> nextword) {
    bool found = false;
    for (auto &[word, occurrence] : words) {
      if (word == nextword) {
        ++occurrence;
        found = true;
        break;
      }
    }
    if (!found)
      words.emplace_back(nextword, 1);
  }

  if (words.empty()) {
    cout << "Input is empty" << endl;
    return 0;
  }

  string word_with_max_occur = words[0].first;
  int max_occur = words[0].second;
  for (auto &[word, occur] : words)
    if (occur > max_occur) {
      word_with_max_occur = word;
      max_occur = occur;
=======*/
  while (!fin.eof()) {
    fin >> nextword;
    words[nextword]++;
  }

  auto answer = max_element(words.begin(), words.end(),
    // Define a comparator
    [](auto &elem1, auto &elem2) {
      // Compare the occurrence first.
      return tie(elem1.second, elem1.first) < tie(elem2.second, elem2.first);
//>>>>>>> usemap
    }
  );

  if(answer->first == ""){
  	cout << "Input is empty" << endl;
	return 0;
  }

  cout << "Word '" << answer->first << "' appeared " << answer->second
       << " times." << endl;
  return 0;
}
