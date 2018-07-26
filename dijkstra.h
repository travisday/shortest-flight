#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include "diredge.h"
#include "graph.h"
using std::vector;
using std::priority_queue;

struct vertex
{
    int index;
    double weight;
    vertex(int i = int(),double w = double()):index(i),weight(w){}

    friend
    bool operator<(const vertex& x,const vertex& y)
    {
        return x.weight>y.weight;
    }
    friend bool
    operator>(const vertex& x,const vertex& y)
    {
        return x.weight<y.weight;
    }
};

class Dijkstra
{
public:
    Dijkstra(const Graph&,int source);
    double distTo(int v);
    bool hasPathTo(int v);
    vector<diredge> path(int v);
    void displayPathTo(int i);
private:
    vector<diredge> predecessor;
    vector<double> distanceTo;
    priority_queue<vertex> pq;
    const double infinite = std::numeric_limits<double>::infinity();
};

#endif // DIJKSTRA_H
