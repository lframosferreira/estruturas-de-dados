#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <ctype.h>

#define OPEN_PARENTHESIS '('
#define CLOSE_PARENTHESIS ')'

int countNodes(std::string& line)
{
    int count = 0;
    for (char c : line)
    {
        if (c == CLOSE_PARENTHESIS) count++;
    }
    return count;
}

void treeFromParenthesisNotation(std::string& line, std::vector<std::vector<int>>& adjMatrix, std::vector<int>& listaDeAdj)
{   
    std::stack<int> nodes;
    int currFather;
    for (int i = 0; i < line.length(); i++)
    {   
        char currValue = line.at(i);
        if (isdigit(currValue))
        {   
            int value;
            int index = i;
            while (isdigit(line.at(index)))
            {
                index++;
            }
            if (index > i + 1)
            {
                std::string valueStr = line.substr(i, index - i);
                value = std::stoi(valueStr) - 1;
                i = index - 1;
            }
            else
            {
                value = currValue - '0' - 1;
            }
            if (nodes.empty())
            {
                nodes.push(value);
            }
            else
            {   
                adjMatrix[currFather][value] = 1;
                listaDeAdj[currFather]++;

                adjMatrix[value][currFather] = 1;
                listaDeAdj[value]++;
                
                nodes.push(value); 
            }
        }
        else
        {
            if (currValue == CLOSE_PARENTHESIS)
            {   
                nodes.pop();
            }
            if (currValue == OPEN_PARENTHESIS)
            {
                continue;
            }
            if (currValue == ' ')
            {
                continue;
            }
        }
        if (!nodes.empty()) currFather = nodes.top();
    }
}

void getPruferCode(std::vector<std::vector<int>>& adjMatrix, int adjMatrixSize, std::vector<int>& listaDeAdj)
{   
    /* Caso específico onde existe apenas um nó na árvore. */
    if (adjMatrixSize == 1)
    {
        std::cout << std::endl;
        return;
    }
    
    int count = 0;
    while (count < adjMatrixSize - 1)
    {
        int lowestLeafi = -1;
        int lowestLeafj = -1;
        for (int i = 0; i < adjMatrixSize; i++)
        {
            if (listaDeAdj[i] == 1)
            {
                for (int j = 0; j < adjMatrixSize; j++)
                {   
                    if (adjMatrix[i][j] == 1)
                    {   
                        if ((lowestLeafi == -1 && lowestLeafj == -1) || (i + 1 < lowestLeafi))
                        {    
                            lowestLeafi = i;
                            lowestLeafj = j;
                        }
                    } 
                }
            }
        }
        adjMatrix[lowestLeafi][lowestLeafj] = 0;
        adjMatrix[lowestLeafj][lowestLeafi] = 0;
        listaDeAdj[lowestLeafi]--;
        listaDeAdj[lowestLeafj]--;
        count++;
        if (count == adjMatrixSize - 1)
        {
            std::cout << lowestLeafj + 1 << std::endl;
        }
        else
        {
            std::cout << lowestLeafj + 1 << " ";
        }
    }
}

int main(int argc, char* argv[])
{

    std::string line;
    
    while (std::getline(std::cin, line))
    {   

        int adjMatrixSize = countNodes(line);
        
        std::vector<int> listaDeAdj(adjMatrixSize, 0);

        std::vector<std::vector<int>> adjMatrix(adjMatrixSize);
        for (int i = 0; i < adjMatrixSize; i++)
        {   
            std::vector<int> v(adjMatrixSize, 0);
            adjMatrix[i] = v;
        } 

        treeFromParenthesisNotation(line, adjMatrix, listaDeAdj); 

        getPruferCode(adjMatrix, adjMatrixSize, listaDeAdj);
        
    }

    return 0;
}