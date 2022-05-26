#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct Node
{
    int value;
    int fatherBranchBeauty;
    int fatherBranchID;
    Node* father;
    std::vector<Node*> descendentNodes;

    Node(){};

    Node(int value, int fatherBranchBeauty, int fatherBranchID)
    {
        this->value = value;
        this->fatherBranchBeauty = fatherBranchBeauty;
        this->fatherBranchID = fatherBranchID;
    }

};

class Tree
{
    public:

        std::map<int,Node*> allTreeNodes;

        int numberOfBranches;

        int beauty;

        Node* root;

        Tree()
        {
            this->root = new Node(0, 0, -1); 
            this->numberOfBranches = 0;
            this->allTreeNodes.insert({0, this->root});
        }

        void insert(int di, int ai, int bi, int wi)
        {
            Node* ascendent;
            Node* descendent;
            if (ai == di + 1)
            {
                ascendent = this->allTreeNodes.at(bi);
                descendent = new Node(ai, wi, di);
            }
            else{
                ascendent = this->allTreeNodes.at(ai);
                descendent = new Node(bi, wi, di);
            }
            this->allTreeNodes.insert({descendent->value, descendent});
            descendent->father = ascendent;
            ascendent->descendentNodes.push_back(descendent);
            this->numberOfBranches++;
        }


        void print(Node* node)
        {
            std::cout << "Os filhos do Node " << node->value << ":" << std::endl;
            for (auto node : node->descendentNodes){
                std::cout << node->value << " ";
            }
            std::cout << std::endl;
            for (auto node : node->descendentNodes){
                print(node);
            }
        }

};

int getTreeBeauty(Node* root)
{   
    int count = 0;
    for (Node* node : root->descendentNodes)
    {
        count += node->fatherBranchBeauty;
        count += getTreeBeauty(node);
    }
    return count;
}

std::map<int, int> treeBeautys;

void getEverySubtreeBeauty(Node* auxNode)
{
    for (Node* node : auxNode->descendentNodes)
    {
        treeBeautys.insert({node->value, getTreeBeauty(node)});
        getEverySubtreeBeauty(node);
    }
}

int optimizeTree(Tree& tree, Node* root, std::vector<int>& galhosCortados)
{   
    int numDeCortes = 0;
    for (auto node : root->descendentNodes)
    {
        if (node->fatherBranchBeauty <= 0)
        {
            int totalBranchBeauty = treeBeautys.at(node->value) + node->fatherBranchBeauty;
            if (totalBranchBeauty < 0)
            {   
                tree.beauty -= totalBranchBeauty;
                galhosCortados.push_back(node->father->value);
                numDeCortes++;
            }
        }
        
        numDeCortes += optimizeTree(tree, node, galhosCortados);    
    }
    return numDeCortes;
}

int main(int argc, char* argv[])
{   
    Tree tree;

    int numberOfNodes;

    std::vector<int> galhosCortados;

    scanf("%d", &numberOfNodes);

    int di, ai, bi, wi;

    for (int i = 0; i < numberOfNodes - 1; i++)
    {
        scanf("%d%d%d%d", &di, &ai, &bi, &wi);
        tree.insert(di, ai, bi, wi);
    }

    tree.beauty = getTreeBeauty(tree.root);

    getEverySubtreeBeauty(tree.root);

    int numCortes = optimizeTree(tree, tree.root, galhosCortados);

    sort(galhosCortados.begin(), galhosCortados.end());

    std::cout << tree.beauty << " " << numCortes << std::endl;

    if (numCortes > 0)
    {
        for (int e : galhosCortados)
        {
            std::cout << e << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}