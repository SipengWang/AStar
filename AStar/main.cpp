#include <QCoreApplication>
#include <main.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int _map[HEIGHT][LENGTH] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 0, 0, 0, 0, 1, 1, 0, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
                                1, 0, 0, 1, 0, 1, 1, 1, 0, 1,
                                1, 1, 1, 1, 1, 1, 0, 0, 0, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int _start[2] = {3,3};
    int _end[2] = {3,0};

    Node _node[HEIGHT][LENGTH] = {0}

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = 0; j < LENGTH; j++)
        {
            _node[i][j].x = j;
            _node[i][j].y = i;
            if(_map[i][j] == 0)
                _node[i][j].type = FORBID;
            if(_map[i][j] == 1)
                _node[i][j].type = BLANK;
        }
    }

    FindWay(_start, _end, _node);

    return 0;
}
