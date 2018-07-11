/*
 * Compilation:
 * g++-8 -std=c++17 filesystem.cpp -o filesystem -lstdc++fs
 */
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    const fs::path pathToShow{ argc >= 2 ? argv[1] : fs::current_path() };
    std::cout << "exists() = " << fs::exists(pathToShow) << "\n"
              << "root_name() = " << pathToShow.root_name() << "\n"
              << "root_path() = " << pathToShow.root_path() << "\n"
              << "relative_path() = " << pathToShow.relative_path() << "\n"
              << "parent_path() = " << pathToShow.parent_path() << "\n"
              << "filename() = " << pathToShow.filename() << "\n"
              << "stem() = " << pathToShow.stem() << "\n"
              << "extension() = " << pathToShow.extension() << "\n";

    return 0;
}

