// Custom -- Includes
#include "utils/commands.hpp"
#include "utils/parser.hpp"

// STD -- includes
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using cmdFun = std::function<void(const std::vector<std::string>&)>;
using commandMap = std::map<std::string, cmdFun>;

void repl();
std::tuple<std::string, std::vector<std::string>> getCmdAndArgsTuple(std::string inputLine);


int main() { 
  repl();
  return 0;
}


void repl() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::cout << "$ ";

  std::string inputLine;
  std::getline(std::cin, inputLine);

  auto cmdAndArgsTuple = getCmdAndArgsTuple(inputLine);

  commandMap commandMap = initNewCommandMap();

  dispatchCommand(cmdAndArgsTuple, commandMap);

  repl();
}


