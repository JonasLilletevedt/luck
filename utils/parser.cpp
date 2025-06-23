#include "parser.hpp"

std::tuple<std::string, std::vector<std::string>> getCmdAndArgsTuple(std::string inputLine) {
  std::string command;
  std::vector<std::string> args;
  std::string curr;
  for (auto ch : inputLine) {
    if (ch != ' ') {
      curr.push_back(ch);
      continue;
    }

    if (curr.empty()) continue;

    if (command.empty()) command = std::move(curr);
    else args.push_back(std::move(curr));

    curr.clear();
  }

  if (!curr.empty()) {
    if (command.empty()) command = std::move(curr);
    else args.push_back(std::move(curr));
  }

  return std::tuple(command, args);
}


