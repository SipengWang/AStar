#include "node.h"

using namespace std;

bool comp(Node a, Node b)
{
    return a.F < b.F;
}

int FindWay(int (&start)[2], int (&end)[2], Node (&node)[HEIGHT][LENGTH])
{
    Node CurrNode;
    vector<Node> OpenList{};
    Node *_CurrNode = &CurrNode;
    vector<Node> *_OpenList = &OpenList;

    static int count = 0;

    node[start[1]][start[0]].x = start[0];
    node[start[1]][start[0]].y = start[1];
    node[start[1]][start[0]].type = CLOSE;
    OpenList.push_back(node[start[1]][start[0]]);


    while(1)
    {
        if(OpenList.size() == 0)
        {
            cout << "Fail to Find the Best Path." << endl;
            return 1;
        }

        sort(OpenList.begin(), OpenList.end(), comp);
        CurrNode = OpenList[0];

        OpenList.erase(OpenList.begin());


        CurrNode.type = CLOSE;
        node[CurrNode.y][CurrNode.x].type = CLOSE;

        count++;

        if(CurrNode.x == end[0] && CurrNode.y == end[1])
        {

            PrintWay(_CurrNode, node);
            PlotWay(node);
            return 0;
        }

        FindNextNode(start, end, _CurrNode, node, _OpenList);

    }
};

void FindNextNode(int (&start)[2], int (&end)[2], Node *CurrNode, Node (&node)[HEIGHT][LENGTH], vector<Node> *OpenList)
{
    //up
    if(CurrNode->y > 0)
    {
        Node temp = node[(CurrNode->y) - 1][CurrNode->x];

        if(temp.type == OPEN)
        {
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            if(temp.G + temp.H < temp.F)
            {
                temp.F = temp.G + temp.H;
                temp.parent = &node[CurrNode->y][CurrNode->x];
                node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
                OpenList->push_back(temp);
            }
        }

        if(temp.type == BLANK)
        {
            temp.type = OPEN;
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            temp.F = temp.G + temp.H;
            temp.parent = &node[CurrNode->y][CurrNode->x];
            node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
            OpenList->push_back(temp);
        }

    }

    //down
    if(CurrNode->y < HEIGHT - 1)
    {
        Node temp = node[CurrNode->y + 1][CurrNode->x];

        if(temp.type == OPEN)
        {
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            if(temp.G + temp.H < temp.F)
            {
                temp.F = temp.G + temp.H;
                temp.parent = &node[CurrNode->y][CurrNode->x];
                node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
                OpenList->push_back(temp);
            }
        }


        if(temp.type == BLANK)
        {
            temp.type = OPEN;
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            temp.F = temp.G + temp.H;
            temp.parent = &node[CurrNode->y][CurrNode->x];
            node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
            OpenList->push_back(temp);
        }

    }

    //left
    if(CurrNode->x > 0)
    {
        Node temp = node[CurrNode->y][CurrNode->x - 1];

        if(temp.type == OPEN)
        {
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            if(temp.G + temp.H < temp.F)
            {
                temp.F = temp.G + temp.H;
                temp.parent = &node[CurrNode->y][CurrNode->x];
                node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
                OpenList->push_back(temp);
            }
        }
        if(temp.type == BLANK)
        {
            temp.type = OPEN;
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            temp.F = temp.G + temp.H;
            temp.parent = &node[CurrNode->y][CurrNode->x];
            node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
            OpenList->push_back(temp);
        }

    }


    //right
    if(CurrNode->x < LENGTH - 1)
    {
        Node temp = node[CurrNode->y][CurrNode->x + 1];

        if(temp.type == OPEN)
        {
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            if(temp.G + temp.H < temp.F)
            {
                temp.F = temp.G + temp.H;
                temp.parent = &node[CurrNode->y][CurrNode->x];
                node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
                OpenList->push_back(temp);
            }
        }

        if(temp.type == BLANK)
        {
            temp.type = OPEN;
            temp.G = abs(temp.x - start[0]) + abs(temp.y - start[1]);
            temp.H = abs(temp.x - end[0]) + abs(temp.y - end[1]);
            temp.F = temp.G + temp.H;
            temp.parent = &node[CurrNode->y][CurrNode->x];
            node[temp.y][temp.x].parent = &node[CurrNode->y][CurrNode->x];
            OpenList->push_back(temp);
        }

    }

}

void PrintWay(Node *CurrNode, Node (&node)[HEIGHT][LENGTH])
{

    cout << "The Best Path is: " << endl;

    do
    {
        cout << CurrNode->x << "," << CurrNode->y << endl;
        node[CurrNode->y][CurrNode->x].type = PATH;
        CurrNode = node[CurrNode->y][CurrNode->x].parent;
    }while(CurrNode != NULL);

}

void PlotWay(Node (&node)[HEIGHT][LENGTH])
{
    cout << "The Map is: " << endl;
    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            if(node[i][j].type == PATH)
                cout << "* ";
            else if(node[i][j].type == FORBID)
                cout << "o ";
            else
                cout << ". ";
        }
        cout << endl;
    }

}
