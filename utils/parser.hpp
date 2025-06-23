#pragma once

#include <string>
#include <tuple>
#include <vector>

std::tuple<std::string, std::vector<std::string>> getCmdAndArgsTuple(
    std::string inputLine
    );
