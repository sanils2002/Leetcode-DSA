class Solution {
private:
    std::vector<std::string> split(std::string str) {
  std::vector<std::string> words;
  std::string word = "";
  for (char c : str) {
    if (c == ' ') {
      words.push_back(word);
      word = "";
    } else {
      word += c;
    }
  }
  words.push_back(word);
  return words;
}

std::string join(std::vector<std::string> words) {
  std::string str = "";
  for (int i = 0; i < words.size(); i++) {
    str += words[i];
    if (i < words.size() - 1) {
      str += " ";
    }
  }
  return str;
}

public:
    string capitalizeTitle(string title) {
        // If the string is empty, return an empty string
  if (title.empty()) {
    return "";
  }

  // Split the string into words
  std::vector<std::string> words = split(title);

  // Capitalize each word
  for (int i = 0; i < words.size(); i++) {
    std::string word = words[i];

    if (word.length() <= 2) {
      // Change all letters to lowercase
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    } else {
      // Change first letter to uppercase and remaining letters to lowercase
      word[0] = toupper(word[0]);
      std::transform(word.begin() + 1, word.end(), word.begin() + 1, ::tolower);
    }

    words[i] = word;
  }

  // Join the words back into a single string
  std::string capitalizedTitle = join(words);
  return capitalizedTitle;
    }
};