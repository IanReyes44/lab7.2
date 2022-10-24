// Jacob Rice
// CPSC 120-06
// 2022-10-19
// jrice909@csu.fullerton.edu
// @JChillin808
//
// Lab 07-02
// Partners: @IanReyes44
//
// This program plays blackjack
//

#include <iostream>
#include <string>
#include <vector>

bool IsAce(const std::string& card_name) {
  if (card_name == "A") {
    return true;
  }
  return false;
}

bool IsFaceCard(const std::string& card_name) {
  if (card_name == "K") {
    return true;
  } else if (card_name == "Q") {
    return true;
  } else if (card_name == "J") {
    return true;
  }
  return false;
}

bool IsNumberCard(const std::string& card_name) {
  if (card_name == "2" || card_name == "3" || card_name == "4" ||
      card_name == "5" || card_name == "6" || card_name == "7" ||
      card_name == "8" || card_name == "9" || card_name == "10") {
    return true;
  }
  return false;
}

bool IsCardName(const std::string& str) {
  if (IsAce(str) || IsFaceCard(str) || IsNumberCard(str)) {
    return true;
  }
  return false;
}

bool AllArgumentsValid(const std::vector<std::string>& arguments) {
  bool first = true;
  for (const std::string& c : arguments) {
    if (first) {
      first = false;
    } else if (IsCardName(c) == false) {
      return false;
    }
  }
  return true;
}

int CardPoints(const std::string& card_name) {
  int face_card{10};
  int ace{1};
  if (IsFaceCard(card_name)) {
    return face_card;
  }
  if (IsAce(card_name)) {
    return ace;
  }
  if (IsNumberCard(card_name)) {
    return std::stoi(card_name);
  }
  return 0;
}

bool HandContainsAce(const std::vector<std::string>& arguments) {
  bool first = true;
  for (const std::string& c : arguments) {
    if (first) {
      first = false;
    } else if (IsAce(c)) {
      return true;
    }
  }
  return false;
}

bool IsBust(int score) {
  if (score > 21) {
    return true;
  }
  return false;
}

int HandScore(const std::vector<std::string>& arguments) {
  int score{0};
  bool first = true;
  for (const std::string& c : arguments) {
    if (first) {
      first = false;
    } else {
      score += CardPoints(c);
    }
  }
  if (HandContainsAce(arguments) && (!IsBust(score + 10))) {
    score += 10;
  }
  return score;
}

void PrintScore(int score) {
  if (IsBust(score) == false) {
    std::cout << "Score is " << score << "\n";
  }
  if (IsBust(score) == true) {
    std::cout << "Score is " << score << ", BUST\n";
  }
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (AllArgumentsValid(arguments) == true) {
    PrintScore(HandScore(arguments));
    return 0;
  }
  std::cout << "error: invalid card\n";
  return 1;
}