#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include "index.h"

using namespace std;

class Node
{
public:
    int x, y;
    int G, H, F;
    int type;
    Node *parent;
    //vector<Node> OpenList;
};

int FindWay(int (&start)[2], int (&end)[2], Node (&node)[HEIGHT][LENGTH]);
void FindNextNode(int (&start)[2], int (&end)[2], Node *CurrNode, Node (&node)[HEIGHT][LENGTH], vector<Node> *OpenList);
bool compare(Node a, Node b);
void PrintWay(Node *CurrNode, Node (&node)[HEIGHT][LENGTH]);
void PlotWay(Node (&node)[HEIGHT][LENGTH]);

#endif // NODE_H
