#include <iostream>
#include <string>
#include <algorithm>

const char sand = '.';
const std::string diamond = "<>";

void removeSand(std::string& line){
    line.erase(std::remove(line.begin(), line.end(), sand), line.end());
}

int extractDiamonds(std::string& line){
    std::size_t pos = line.find(diamond);
    if (pos == std::string::npos) return 0;
    line.erase(pos, 2);
    return 1 + extractDiamonds(line);
}


int main(int argc, char* argv[])
{
    int numLines;
    std::string line;
    std::cin >> numLines;
    for (int i = 0; i < numLines; i++){
        std::cin >> line;
        removeSand(line);
        std::cout << extractDiamonds(line) << std::endl;
    }
    return 0;
}