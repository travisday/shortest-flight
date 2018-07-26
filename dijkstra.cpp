#include "dijkstra.h"
#include <queue>


Dijkstra::Dijkstra(const Graph &graph, int source)
{
    distanceTo.resize(graph.vCount(),infinite);
    predecessor.resize(graph.vCount());
    distanceTo[source] = 0;
    pq.push(vertex(source,0));
    while(!pq.empty()) {
        int index  = pq.top().index;
        pq.pop();
        for(diredge x : graph.getList(index))
        {
            int w  = x.getTo().id;
            if(distanceTo[w]>distanceTo[index]+x.getCost())
            {
                distanceTo[w]  = distanceTo[index] + x.getCost();
                predecessor[w] = x;
                pq.push(vertex(w,distanceTo[w]));
            }
        }
    }
}

double Dijkstra::distTo(int v)
{
    return distanceTo[v];
}

bool Dijkstra::hasPathTo(int v)
{
    return distanceTo[v]<infinite;
}

vector<diredge> Dijkstra::path(int v)
{
    vector<diredge> path;
    if(hasPathTo(v))
    {
        for(diredge e = predecessor[v];e.getFrom().id!=-1;e=predecessor[e.getFrom().id])
            path.push_back(e);
    }
    return path;
}

void Dijkstra::displayPathTo(int i)
{
    vector<diredge> thePath = path(i);
    cout<<"("<<distanceTo[i]<<") ";
    for(int i = thePath.size()-1;i>=0;--i)
        cout<<thePath[i]<<' ';
    cout<<endl;
}
