#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include "graph.h"
#include "dijkstra.h"

using namespace std;

void loadMap(ifstream &file, map<int,airport> &airports, map<string, int> &index);
void loadRoutes(ifstream &file, Graph &world, map<int,airport> &airportMap);

int main(int argc, char *argv[])
{

    map<int,airport> airportMap;
    map<string, int> airportIndex;
    Graph x(10000);
    ifstream airports, routes;
    string source, destination, ans;
    bool valid = false;

    airports.open("airports.txt");
    routes.open("routes.txt");

    loadMap(airports, airportMap, airportIndex);
    loadRoutes(routes, x, airportMap);

    do {
        cout<<"Input departure airport: ";
        cin>>source;
        cout<<"Input arrival airport: ";
        cin>>destination;

        if (!airportIndex.count(source)){
            cout<<"Invalid departure airport"<<endl;
            valid = false;
        } else if (!airportIndex.count(destination)){
            cout<<"Invalid arrival airport"<<endl;
            valid = false;
        }

        if (!valid) {
            Dijkstra sp(x,airportIndex[source]);
            sp.displayPathTo(airportIndex[destination]);
            cout<<"Again?"<<endl;
            cin>>ans;
        }

    }while(ans[0] == 'Y' || 'y');


    return 0;
}


void loadRoutes(ifstream &file, Graph &world, map<int,airport> &airportMap){
    string line, airline;
    double sourceID, destinationID, cost;

    while(getline(file,line)){
        stringstream ss(line);
        ss>>sourceID>>airline>>destinationID>>cost;

        diredge route(airportMap[sourceID],airportMap[destinationID],cost,airline);
        world.addEdge(route);
    }
}


void loadMap(ifstream &file, map<int,airport> &airports, map<string, int> &index){

    string line;
    double lon, lat;
    int id;
    airport port;

    string name,city, country,iata,icao;

    while(getline(file,line)){
        stringstream ss(line);
        ss>>id>>name>>city>>country>>iata>>icao>>lon>>lat;
        port.id = id;
        port.name = name;
        port.iata = iata;
        port.icao = icao;
        port.country = country;
        port.city = city;
        port.lon = lon;
        port.lat = lat;
        airports[id] = port;
        index[iata] = id;
    }
}