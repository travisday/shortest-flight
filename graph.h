#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include "diredge.h"
using std::cout;
using std::endl;
using std::vector;
using std::list;

class Graph
{
public:
    Graph();
    Graph(int v=10);
    void resizeGraph(int v);
    int vCount()const;
    int eCount()const;
    void addEdge(diredge &e);
    const list<diredge>& getList(airport v)const;

private:
    vector<list<diredge>> g;
    int vertices;
    int edges;
};

#endif // GRAPH_H
