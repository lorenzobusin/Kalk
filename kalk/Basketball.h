//file Basketball.h
#ifndef BASKETBALL_H
#define BASKETBALL_H

#include"Match_stats.h"
#include<iostream>

class Basketball : public Match_stats{

private:
    int punti_subiti;
    int rimbalzi_off;
    int rimbalzi_dif;
    int assist;
    int stoppate;
    int tiri2;
    int tiri2_segnati;
    int precisione2;
    int tiri3;
    int tiri3_segnati;
    int precisione3;
    int precisione_tiri;
    int liberi;
    int liberi_segnati;
    int precisione_liberi;

public:
    Basketball(int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0,int = 0,
               int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0);
    ~Basketball();
    Basketball(const Basketball&);

    int getPs() const;
    int getRo() const;
    int getRd() const;
    int getA() const;
    int getS() const;
    int getT2() const;
    int getT2s() const;
    int getP2() const;
    int getT3() const;
    int getT3s() const;
    int getP3() const;
    int getPt() const;
    int getL() const;
    int getLs() const;
    int getPl() const;
    void setBasketMatch(int = 0, int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0,int = 0,
                        int = 0, int = 0, int = 0,int = 0, int = 0, int = 0, int = 0);

    //overload
    Basketball* operator+(const Basketball&) const;
    Basketball* operator-(const Basketball&) const;
    Basketball* operator*(int) const;
    Basketball* operator/(int) const;
    Basketball* operator%(int) const;
    Basketball operator=(const Basketball&);
    bool operator==(const Basketball&);
    bool operator>(const Basketball&);
    bool operator<(const Basketball&);

    std::string print() const;

};

#endif
