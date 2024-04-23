// main.cpp
#include <iostream>

void platformSpecificCode() {
#ifdef _WIN32
    std::cout << "Running on Windows" << std::endl;
#elif __linux__
    std::cout << "Running on Linux" << std::endl;
#elif __APPLE__
    std::cout << "Running on macOS" << std::endl;
#else
    std::cout << "Running on an unknown platform" << std::endl;
#endif
}

int main() {
    platformSpecificCode();
    return 0;
}