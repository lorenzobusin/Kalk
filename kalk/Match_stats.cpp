#include "Match_stats.h"

Match_stats::Match_stats(int p, int fs, int fc, int m, int pp, int pr, int passaggit, int passaggir){
    if(p < 0)
        punteggio = 0;
    else
        punteggio = p;

    if(fs < 0)
        falli_subiti = 0;
    else
        falli_subiti = fs;

    if(fc < 0)
        falli_commessi = 0;
    else
        falli_commessi = fc;

    if(m < 0)
        minuti = 0;
    else
        minuti = m;

    if(pp < 0)
        palle_perse = 0;
    else
        palle_perse = pp;

    if(pr < 0)
        palle_recuperate = 0;
    else
        palle_recuperate = pr;

    if(passaggit < 0)
        passaggi = 0;
    else
        passaggi = passaggit;

    if(passaggir < 0)
        passaggi_riusciti = 0;
    else if(passaggir > passaggit)
        passaggi_riusciti = passaggit;
    else
        passaggi_riusciti = passaggir;

    if(passaggi <= 0)
            precisione_passaggi = 0;
    else{
        float temp = float(passaggi_riusciti)/float(passaggi)*100;
        precisione_passaggi = int(temp);
    }
}//costruttore

Match_stats::~Match_stats(){

}//distruttore

Match_stats::Match_stats(const Match_stats& copia){
    punteggio = copia.punteggio;
    falli_subiti = copia.falli_subiti;
    falli_commessi = copia.falli_commessi;
    minuti = copia.minuti;
    palle_perse = copia.palle_perse;
    palle_recuperate = copia.palle_recuperate;
    passaggi_riusciti = copia.passaggi_riusciti;
    passaggi = copia.passaggi;
    precisione_passaggi = copia.precisione_passaggi;
}//costruttore di copia

int Match_stats::getPunt() const{
    return punteggio;
}

int Match_stats::getFs() const{
    return falli_subiti;
}

int Match_stats::getFc() const{
    return falli_commessi;
}

int Match_stats::getM() const{
    return minuti;
}

int Match_stats::getPp() const{
    return palle_perse;
}

int Match_stats::getPr() const{
    return palle_recuperate;
}

int Match_stats::getPass() const{
    return passaggi;
}

int Match_stats::getPassr() const{
    return passaggi_riusciti;
}

void Match_stats::setMatch(int p, int fs, int fc, int m, int pp, int pr, int passaggit, int passaggir){
    if(p < 0)
        punteggio = 0;
    else
        punteggio = p;

    if(fs < 0)
        falli_subiti = 0;
    else
        falli_subiti = fs;

    if(fc < 0)
        falli_commessi = 0;
    else
        falli_commessi = fc;

    if(m < 0)
        minuti = 0;
    else
        minuti = m;

    if(pp < 0)
        palle_perse = 0;
    else
        palle_perse = pp;

    if(pr < 0)
        palle_recuperate = 0;
    else
        palle_recuperate = pr;

    if(passaggit < 0)
        passaggi = 0;
    else
        passaggi = passaggit;

    if(passaggir < 0)
        passaggi_riusciti = 0;
    else if(passaggir > passaggit)
        passaggi_riusciti = passaggit;
    else
        passaggi_riusciti = passaggir;

    if(passaggi <= 0)
            precisione_passaggi = 0;
    else{
        float temp = float(passaggi_riusciti)/float(passaggi)*100;
        precisione_passaggi = int(temp);
    }
}//setMatch

Match_stats* Match_stats::operator+(const Match_stats& x) const{
    return new Match_stats(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti,
                       palle_perse + x.palle_perse, palle_recuperate + x.palle_recuperate, passaggi + x.passaggi,
                       passaggi_riusciti + x.passaggi_riusciti);
}//operator+

Match_stats* Match_stats::operator-(const Match_stats& x) const{
    return new Match_stats(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,
                       palle_perse - x.palle_perse, palle_recuperate - x.palle_recuperate, passaggi - x.passaggi,
                       passaggi_riusciti - x.passaggi_riusciti);
}//operator-

Match_stats* Match_stats::operator*(int x) const{
    return new Match_stats(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x, palle_perse * x, palle_recuperate * x, passaggi * x,
                       passaggi_riusciti * x);
}//operator*

Match_stats* Match_stats::operator/(int x) const{

    if (x == 0){
        std::cout << "Errore divisione per 0";
        return new Match_stats();
    }

    return new Match_stats(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x, palle_perse / x, palle_recuperate / x, passaggi / x,
                       passaggi_riusciti / x);
}//operator/

Match_stats* Match_stats::operator%(int x) const{

    if (x == 0){
        std::cout << "Errore divisione per 0";
        return new Match_stats();
    }

    return new Match_stats(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x, palle_perse % x, palle_recuperate % x, passaggi % x,
                       passaggi_riusciti % x);
}//operator%

Match_stats Match_stats::operator=(const Match_stats& copia){
    punteggio = copia.punteggio;
    falli_subiti = copia.falli_subiti;
    falli_commessi = copia.falli_commessi;
    minuti = copia.minuti;
    palle_perse = copia.palle_perse;
    palle_recuperate = copia.palle_recuperate;
    passaggi_riusciti = copia.passaggi_riusciti;
    passaggi = copia.passaggi;
    precisione_passaggi = copia.precisione_passaggi;
    return *this;
}//operator=

bool Match_stats::operator==(const Match_stats& x){
    return (punteggio == x.punteggio && falli_subiti == x.falli_subiti && falli_commessi == x.falli_commessi && minuti == x.minuti &&
            palle_perse == x.palle_perse && palle_recuperate == x.palle_recuperate && passaggi == x.passaggi &&
            passaggi_riusciti == x.passaggi_riusciti);
}//operator==

bool Match_stats::operator>(const Match_stats& x){
    return punteggio > x.punteggio;
}//operator>

bool Match_stats::operator<(const Match_stats& x){
    return punteggio < x.punteggio;
}

std::string Match_stats::print_basic() const{

    std::string text = "<i>Punteggio:</i><br>";
    text += std::to_string(punteggio);
    text += "<br><i>Falli subiti:</i><br>";
    text += std::to_string(falli_subiti);
    text += "<br><i>Falli commessi:</i><br>";
    text += std::to_string(falli_commessi);
    text += "<br><i>Minuti giocati:</i><br>";
    text += std::to_string(minuti);
    text += "<br><i>Palle perse:</i><br>";
    text += std::to_string(palle_perse);
    text += "<br><i>Palle recuperate:</i><br>";
    text += std::to_string(palle_recuperate);
    text += "<br><i>Passaggi:</i><br>";
    text += std::to_string(passaggi);
    text += "<br><i>Passaggi riusciti:</i><br>";
    text += std::to_string(passaggi_riusciti);
    text += "<br><i>% passaggi:</i><br>";
    text += std::to_string(precisione_passaggi) + "%";

    return text;

}//print_basic

std::string Match_stats::print() const{

    std::string text;
    text += "<br><i>Falli subiti:</i><br>";
    text += std::to_string(falli_subiti);
    text += "<br><i>Falli commessi:</i><br>";
    text += std::to_string(falli_commessi);
    text += "<br><i>Minuti giocati:</i><br>";
    text += std::to_string(minuti);
    text += "<br><i>Palle perse:</i><br>";
    text += std::to_string(palle_perse);
    text += "<br><i>Palle recuperate:</i><br>";
    text += std::to_string(palle_recuperate);
    text += "<br><i>Passaggi:</i><br>";
    text += std::to_string(passaggi);
    text += "<br><i>Passaggi riusciti:</i><br>";
    text += std::to_string(passaggi_riusciti);
    text += "<br><i>% passaggi:</i><br>";
    text += std::to_string(precisione_passaggi) + "%";

    return text;
}//print
