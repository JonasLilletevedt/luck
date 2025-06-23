#include "commands.hpp"

#include <complex>
#include <iostream>
#include <filesystem>
#include <system_error>
#include <string_view>

commandMap initNewCommandMap() {
  commandMap commandMap;

  commandMap["echo"] = cmdEcho;
  commandMap["exit"] = cmdExit;
  commandMap["mkdir"] = cmdMkdir;
  commandMap["ls"] = cmdLs;

  return commandMap;
}

void dispatchCommand(std::tuple<std::string, std::vector<std::string>> cmdArgsTuple, const commandMap& cmdMap){
  auto [command, args] = cmdArgsTuple;
  if (command.empty() || !cmdMap.contains(command)) {
    cmdNoCommandFound(command);
    return;
  }
  cmdMap.at(command)(args);
}


void cmdNoCommandFound(std::string command) {
  std::cout << command << ": command not found" << std::endl;
}

void cmdExit(const std::vector<std::string>& arguments) {
  exit(0);
}

void cmdEcho(const std::vector<std::string>& arguments) {
  for (const auto& arg : arguments) {
    std::cout << arg << ' ';
  }
  std::cout << std::endl; 
}

void cmdMkdir(const std::vector<std::string> &arguments) {
  for (const auto& arg : arguments) {
    std::error_code ec{};
    bool sucess = std::filesystem::create_directories(arg, ec);

    if (sucess) return;

    std::cerr << "mkdir: Error creating directory: ";

    if(ec) {
      std::cerr << ec.message() << '.';
    }
    else {
      std::cerr << "file already exists.";
    }

    std::cout << std::endl;
  }
}

void cmdLs(const std::vector<std::string> &arguments) {
  std::error_code ec{};
  
  std::vector<std::string> pathsToList{"."};

  if (!arguments.empty()) {
    pathsToList.assign(arguments.begin(), arguments.end());
  }

  for (const auto& path : pathsToList) {
    if (pathsToList.size() > 1) {
      std::cout << path << ": ";
    }

    for (const auto& dirEntry : std::filesystem::directory_iterator(path, ec)) {
      std::cout << dirEntry << ' ';
    }

    if (ec) {
      std::cerr << "ls: cannot acess '" << path << "' :"
        << ec.message();
    }
    std::cerr << std::endl;
  }
}
