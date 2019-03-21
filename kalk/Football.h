//file Football.h
#ifndef FOOTBALL_H
#define FOOTBALL_H

#include"Match_stats.h"
#include<iostream>

class Football: public Match_stats{

private:
    int possesso_palla; // in %
    int gol_subiti;
    int corner;
    int cross;
    int rimesse_laterali;
    int rigori;
    int tiri; //tiri totali
    int tiri_in_porta;
    int precisione_tiri;// %tiri in porta/tiri totali
    int fuorigioco;
    int cartellini_gialli;
    int cartellini_rossi;

public:
    Football(int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0,
             int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0);
    ~Football();
    Football(const Football&);

    int getPpalla() const;
    int getGs() const;
    int getC() const;
    int getCross() const;
    int getRim() const;
    int getR() const;
    int getT() const;
    int getTporta() const;
    int getPrecT() const;
    int getF() const;
    int getCg() const;
    int getCr() const;
    void setFootballMatch(int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0,
                          int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0);
    //overload
    Football* operator+(const Football&) const;
    Football* operator-(const Football&) const;
    Football* operator*(int) const;
    Football* operator/(int) const;
    Football* operator%(int) const;
    Football operator=(const Football&);
    bool operator==(const Football&);
    bool operator>(const Football&);
    bool operator<(const Football&);

    std::string print() const;

};





#endif
