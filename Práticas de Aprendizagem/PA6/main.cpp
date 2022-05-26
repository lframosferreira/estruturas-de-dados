#include <iostream>
#include <string>

int upperCaseCharToInt(char& c)
{   
    int res = c - '0' - 17;
    return res;
}

int getLineHash(std::string line, int num)
{   
    int res = 0;
    for (int i = 0; i < line.size(); i++)
    {
        res += i + num + upperCaseCharToInt(line.at(i));
    }
    return res;
}

int main(int argc, char* argv[])
{   
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int L;
        std::cin >> L;
        int hashValue = 0;
        getchar();
        for (int j = 0; j < L; j++)
        {
            std::string line;
            std::getline(std::cin, line);
            hashValue += getLineHash(line, j);
        }
        std::cout << hashValue << std::endl;
    } 

    return 0;
}