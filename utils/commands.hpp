#pragma once

#include <functional>
#include <map>
#include <string>
#include <tuple>
#include <vector>

using cmdFun = std::function<void(const std::vector<std::string>&)>;
using commandMap = std::map<std::string, cmdFun>;


commandMap initNewCommandMap();
void dispatchCommand(std::tuple<std::string, std::vector<std::string>> cmdArgsTuple, const commandMap& cmdMap);
void cmdNoCommandFound(std::string command);
void cmdExit(const std::vector<std::string>& arguments);
void cmdEcho(const std::vector<std::string>& arguments);
void cmdMkdir(const std::vector<std::string>& arguments);
void cmdLs(const std::vector<std::string>& arguments);
