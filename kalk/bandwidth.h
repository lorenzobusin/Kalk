//file bandwidth.h

#ifndef BANDWIDTH_H
#define BANDWIDTH_H

#include<iostream>

class Bandwidth{
public:
//private:
    unsigned int ping;
    double download; //Mbps
    double upload; //Mbps

//public:
    Bandwidth(int = 0, double = 0, double = 0);
    Bandwidth(const Bandwidth&); //costruttore di copia
    ~Bandwidth();
    std::string print() const ;

    int getPing() const;
    double getDown() const;
    double getUp() const;

    void setBand(int=0, double=0, double=0);

    //overload
    Bandwidth* operator+(const Bandwidth&) const;
    Bandwidth* operator-(const Bandwidth&) const;
    Bandwidth* operator*(int) const;
    Bandwidth* operator/(int) const;
    Bandwidth* operator%(int) const;
    Bandwidth operator=(const Bandwidth&);
    bool operator==(const Bandwidth&);
    bool operator>(const Bandwidth&);
    bool operator<(const Bandwidth&);
};




#endif
