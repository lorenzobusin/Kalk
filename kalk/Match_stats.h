//file Match_stats.h
#ifndef MATCH_STATS_H
#define MATCH_STATS_H

#include<iostream>

class Match_stats{

protected:
    int punteggio;
    int falli_subiti;
    int falli_commessi;
    int minuti;
    int palle_perse;
    int palle_recuperate;
    int passaggi; // passaggi totali
    int passaggi_riusciti;
    int precisione_passaggi; //% passaggi riusciti/passaggi totali


public:
    Match_stats(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0); //costruttore
    virtual ~Match_stats(); // distruttore
    Match_stats(const Match_stats&); //costruttore di copia

    int getPunt() const;
    int getFs() const;
    int getFc() const;
    int getM() const;
    int getPp() const;
    int getPr() const;
    int getPass() const;
    int getPassr() const;
    void setMatch(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);

    //overload
    virtual Match_stats* operator+(const Match_stats&) const;
    virtual Match_stats* operator-(const Match_stats&) const;
    virtual Match_stats* operator*(int) const;
    virtual Match_stats* operator/(int) const;
    virtual Match_stats* operator%(int) const;
    virtual Match_stats operator=(const Match_stats&);
    virtual bool operator==(const Match_stats&);
    virtual bool operator>(const Match_stats&);
    virtual bool operator<(const Match_stats&);

    virtual std::string print() const;
    std::string print_basic() const;
};


#endif
