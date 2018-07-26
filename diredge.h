#ifndef DIREDGE_H
#define DIREDGE_H
#include <iostream>
#include <cstdlib>
#include <ostream>
#include <string>
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::cout;
using std::endl;


struct route
{
    string airport;
    vector<string> airlines;
};

struct airport {
    //QString name,city, country,iata,icao;
    string name,city, country,iata,icao;

    double lat,lon;
    vector<route> routes;
    int id;

    airport(int i =-1, string in = string()){
        id = i;
        name = in;
    }

    void printInfo()
    {
        if (name.empty())
            cout<<"\n ID not found in airport map\n";
        else
        {
            cout<<"\n name = "<<name;
            cout<<"\n city = "<<city;
            cout<<"\n country = "<<country;
            cout<<"\n iata = "<<iata;
            cout<<"\n icao = "<<icao;
            cout<<"\n latitude = "<<lat;
            cout<<"\n longitude = "<<lon<<endl;
        }
    }
};

class diredge {
public:
    diredge(airport source = airport(), airport target = airport(), double ammount = -1, string al = string());
    double getCost()const;
    airport getFrom() const;
    airport getTo()const;
    friend
    std::ostream& operator<<(std::ostream& out,const diredge&);

private:
    airport from;
    airport to;
    string airline;
    double cost;
};

#endif // DIREDGE_H
