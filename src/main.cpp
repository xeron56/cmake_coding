// main.cpp
#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    boost::filesystem::path current_path = boost::filesystem::current_path();
    std::cout << "Current path: " << current_path << std::endl;
    return 0;
}