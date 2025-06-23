# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.12)

# Define the project name and language
project(LuckProject CXX)

# Tell CMake to generate compile_commands.json for your editor's LSP/IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- THIS IS THE MOST IMPORTANT LINE ---
add_executable(luck main.cpp utils/commands.cpp utils/parser.cpp)

target_compile_features(luck PRIVATE cxx_std_20)
