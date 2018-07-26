#include "graph.h"

Graph::Graph(){
    vertices = 0;
    edges = 0;
}


Graph::Graph(int v){
    vertices = v;
    edges = 0;
    g.resize(v);

}

void Graph::addEdge(diredge &e){
    g[e.getFrom().id].push_back(e);
    edges++;
}

const list<diredge> &Graph::getList(airport v) const
{
    return g[v.id];
}

void Graph::resizeGraph(int v){
    g.resize(v);
    vertices = v;
}

int Graph::vCount()const{
    return vertices;
}

int Graph::eCount()const{
    return edges;
}
