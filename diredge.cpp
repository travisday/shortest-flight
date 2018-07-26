#include "diredge.h"

diredge::diredge(airport source, airport target, double ammount, string al)
{
    from = source;
    to = target;
    cost = ammount;
    airline = al;

}

std::ostream& operator<<(std::ostream &out, const diredge &edge)
{
    string source = edge.getFrom().name, destination = edge.getTo().name;

    for (int i=0;i<source.size();++i){
        int pos = source.find_first_of('_');
        if (pos)
            source[pos] = ' ';
    }
    for (int i=0;i<destination.size();++i){
        int pos = destination.find_first_of('_');
        if (pos)
            destination[pos] = ' ';
    }

    out<<source<<"->"<<destination<<" by "<<edge.airline<<" ["<<edge.getCost()<<"]";

    return out;
}

airport diredge::getFrom()const{
    return from;
}

airport diredge::getTo()const
{
    return to;
}

double diredge::getCost()const
{
    return cost;
}
