#include "Basketball.h"


Basketball::Basketball(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir, int ps, int rimoff,
                       int rimdif, int a,int stop, int t2, int t2segn, int t3, int t3segn, int l, int lsegn)
                       : Match_stats(p, fs, fc, m, pallep, pr, passaggit, passaggir){
    if(p < 0)
        punti_subiti = 0;
    else
        punti_subiti = ps;

    if(rimoff < 0)
        rimbalzi_off = 0;
    else
        rimbalzi_off = rimoff;

    if(rimdif < 0)
        rimbalzi_dif = 0;
    else
        rimbalzi_dif = rimdif;

    if(a < 0)
        assist = 0;
    else
        assist = a;

    if(stop < 0)
        stoppate = 0;
    else
        stoppate = stop;

    if(t2 < 0)
        tiri2 = 0;
    else
        tiri2 = t2;

    if(t2segn < 0)
        tiri2_segnati = 0;
    else if (t2segn > t2)
        tiri2_segnati = t2;
    else
        tiri2_segnati = t2segn;

    if(t2 <= 0)
        precisione2 = 0;
    else{
        float temp1 = float(tiri2_segnati) / float(tiri2) * 100;
        precisione2 = int(temp1);
    }

    if(t3 < 0)
        tiri3 = 0;
    else
        tiri3 = t3;

    if(t3segn < 0)
        tiri3_segnati = 0;
    else if(t3segn > t3)
        tiri3_segnati = t3;
    else
        tiri3_segnati = t3segn;

    if(t3 <= 0)
        precisione3 = 0;
    else{
        float temp2 = float(tiri3_segnati) / float(tiri3) * 100;
        precisione3 = int(temp2);
    }

    if(tiri2 + tiri3 <= 0)
        precisione_tiri = 0;
    else{
        float temp3 = float(tiri2_segnati + tiri3_segnati)/float(tiri2 + tiri3) * 100;
        precisione_tiri = int(temp3);
    }

    if(l < 0)
        liberi = 0;
    else
        liberi = l;

    if(lsegn < 0)
        liberi_segnati = 0;
    else if(lsegn > l)
        liberi_segnati = l;
    else
        liberi_segnati = lsegn;

    if(l <= 0)
        precisione_liberi = 0;
    else{
        float temp4 = float(liberi_segnati) / float(liberi) * 100;
        precisione_liberi = int(temp4);
    }

}//costruttore

Basketball::~Basketball(){

}//distruttore

Basketball::Basketball(const Basketball& copia) : Match_stats(copia){
    punti_subiti = copia.punti_subiti;
    rimbalzi_off = copia.rimbalzi_off;
    rimbalzi_dif = copia.rimbalzi_dif;
    assist = copia.assist;
    stoppate = copia.stoppate;
    tiri2 = copia.tiri2;
    tiri2_segnati = copia.tiri2_segnati;
    precisione2 = copia.precisione2;
    tiri3 = copia.tiri3;
    tiri3_segnati = copia.tiri3_segnati;
    precisione3 = copia.precisione3;
    precisione_tiri = copia.precisione_tiri;
    liberi = copia.liberi;
    liberi_segnati = copia.liberi_segnati;
    precisione_liberi = copia.precisione_liberi;
}//costruttore di copia

int Basketball::getPs() const{
    return punti_subiti;
}

int Basketball::getRo() const{
    return rimbalzi_off;
}

int Basketball::getRd() const{
    return rimbalzi_dif;
}

int Basketball::getA() const{
    return assist;
}

int Basketball::getS() const{
    return stoppate;
}

int Basketball::getT2() const{
    return tiri2;
}

int Basketball::getT2s() const{
    return tiri2_segnati;
}

int Basketball::getP2() const{
    return precisione2;
}

int Basketball::getT3() const{
    return tiri3;
}

int Basketball::getT3s() const{
    return tiri3_segnati;
}

int Basketball::getP3() const{
    return precisione3;
}

int Basketball::getPt() const{
    return precisione_tiri;
}

int Basketball::getL() const{
    return liberi;
}

int Basketball::getLs() const{
    return liberi_segnati;
}

int Basketball::getPl() const{
    return precisione_liberi;
}

void Basketball::setBasketMatch(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir, int ps, int rimoff,
                                int rimdif, int a,int stop, int t2, int t2segn, int t3, int t3segn, int l, int lsegn){

    setMatch(p, fs, fc, m, pallep, pr, passaggit, passaggir);

    if(p < 0)
        punti_subiti = 0;
    else
        punti_subiti = ps;

    if(rimoff < 0)
        rimbalzi_off = 0;
    else
        rimbalzi_off = rimoff;

    if(rimdif < 0)
        rimbalzi_dif = 0;
    else
        rimbalzi_dif = rimdif;

    if(a < 0)
        assist = 0;
    else
        assist = a;

    if(stop < 0)
        stoppate = 0;
    else
        stoppate = stop;

    if(t2 < 0)
        tiri2 = 0;
    else
        tiri2 = t2;

    if(t2segn < 0)
        tiri2_segnati = 0;
    else if (t2segn > t2)
        tiri2_segnati = t2;
    else
        tiri2_segnati = t2segn;

    if(t2 <= 0)
        precisione2 = 0;
    else{
        float temp1 = float(tiri2_segnati) / float(tiri2) * 100;
        precisione2 = int(temp1);
    }

    if(t3 < 0)
        tiri3 = 0;
    else
        tiri3 = t3;

    if(t3segn < 0)
        tiri3_segnati = 0;
    else if(t3segn > t3)
        tiri3_segnati = t3;
    else
        tiri3_segnati = t3segn;

    if(t3 <= 0)
        precisione3 = 0;
    else{
        float temp2 = float(tiri3_segnati) / float(tiri3) * 100;
        precisione3 = int(temp2);
    }

    if(tiri2 + tiri3 <= 0)
        precisione_tiri = 0;
    else{
        float temp3 = float(tiri2_segnati + tiri3_segnati)/float(tiri2 + tiri3) * 100;
        precisione_tiri = int(temp3);
    }

    if(l < 0)
        liberi = 0;
    else
        liberi = l;

    if(lsegn < 0)
        liberi_segnati = 0;
    else if(lsegn > l)
        liberi_segnati = l;
    else
        liberi_segnati = lsegn;

    if(l <= 0)
        precisione_liberi = 0;
    else{
        float temp4 = float(liberi_segnati) / float(liberi) * 100;
        precisione_liberi = int(temp4);
    }
}//setMatch

Basketball* Basketball::operator+(const Basketball& x) const{
    return new Basketball(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti, palle_perse + x.palle_perse,
                      palle_recuperate + x.palle_recuperate, passaggi + x.passaggi, passaggi_riusciti + x.passaggi_riusciti, punti_subiti + x.punti_subiti,
                      rimbalzi_off + x.rimbalzi_off, rimbalzi_dif + x.rimbalzi_dif, assist + x.assist, stoppate + x.stoppate, tiri2 + x.tiri2, tiri2_segnati + x.tiri2_segnati,
                      tiri3 + x.tiri3, tiri3_segnati + x.tiri3_segnati, liberi + x.liberi, liberi_segnati + x.liberi_segnati);
}//operator+

Basketball* Basketball::operator-(const Basketball& x) const{
    return new Basketball(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,palle_perse - x.palle_perse,
                      palle_recuperate - x.palle_recuperate, passaggi - x.passaggi, passaggi_riusciti - x.passaggi_riusciti, punti_subiti - x.punti_subiti,
                      rimbalzi_off - x.rimbalzi_off, rimbalzi_dif - x.rimbalzi_dif, assist - x.assist, stoppate - x.stoppate, tiri2 - x.tiri2, tiri2_segnati - x.tiri2_segnati,
                      tiri3 - x.tiri3, tiri3_segnati - x.tiri3_segnati, liberi - x.liberi, liberi_segnati - x.liberi_segnati);
}//operator-

Basketball* Basketball::operator*(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!";
        return new Basketball();
    }
    return new Basketball(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x,palle_perse * x, palle_recuperate * x, passaggi * x,
                      passaggi_riusciti * x, punti_subiti * x, rimbalzi_off * x, rimbalzi_dif * x, assist * x, stoppate * x, tiri2 * x,
                      tiri2_segnati * x, tiri3 * x, tiri3_segnati * x, liberi * x, liberi_segnati * x);
}//operator*

Basketball* Basketball::operator/(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!";
        return new Basketball();
    }
    return new Basketball(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x,palle_perse / x, palle_recuperate / x, passaggi / x,
                      passaggi_riusciti / x, punti_subiti / x, rimbalzi_off / x, rimbalzi_dif / x, assist / x, stoppate / x, tiri2 / x,
                      tiri2_segnati / x, tiri3 / x, tiri3_segnati / x, liberi / x, liberi_segnati / x);
}//operator/

Basketball* Basketball::operator%(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!";
        return new Basketball();
    }
    return new Basketball(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x,palle_perse % x, palle_recuperate % x, passaggi % x,
                      passaggi_riusciti % x, punti_subiti % x, rimbalzi_off % x, rimbalzi_dif % x, assist % x, stoppate % x, tiri2 % x,
                      tiri2_segnati % x, tiri3 % x, tiri3_segnati % x, liberi % x, liberi_segnati % x);
}//operator%

Basketball Basketball::operator=(const Basketball& copia){
    Match_stats::operator=(copia);

    punti_subiti = copia.punti_subiti;
    rimbalzi_off = copia.rimbalzi_off;
    rimbalzi_dif = copia.rimbalzi_dif;
    assist = copia.assist;
    stoppate = copia.stoppate;
    tiri2 = copia.tiri2;
    tiri2_segnati = copia.tiri2_segnati;
    precisione2 = copia.precisione2;
    tiri3 = copia.tiri3;
    tiri3_segnati = copia.tiri3_segnati;
    precisione3 = copia.precisione3;
    precisione_tiri = copia.precisione_tiri;
    liberi = copia.liberi;
    liberi_segnati = copia.liberi_segnati;
    precisione_liberi = copia.precisione_liberi;

    return *this;
}//operator=

bool Basketball::operator==(const Basketball& x){
    return Match_stats::operator==(x) && (punti_subiti == x.punti_subiti && rimbalzi_off == x.rimbalzi_off && rimbalzi_dif == x.rimbalzi_dif &&
                                         assist == x.assist && stoppate == x.stoppate && tiri2 == x.tiri2 && tiri2_segnati == x.tiri2_segnati &&
                                         tiri3 == x.tiri3 && tiri3_segnati == x.tiri3_segnati && liberi == x.liberi && liberi_segnati == x.liberi_segnati &&
                                         precisione2 == x.precisione2 && precisione3 == x.precisione3 && precisione_liberi == x.precisione_liberi &&
                                         precisione_tiri == x.precisione_tiri);
}//operator==

bool Basketball::operator>(const Basketball& x){
    return Match_stats::operator>(x);
}//operator>

bool Basketball::operator<(const Basketball& x){
    return Match_stats::operator<(x);
}//operator<

std::string Basketball::print() const{

    std::string text;
    text += Match_stats::print();
    text += "<br><i>Punti: </i><br>";
    text += std::to_string(punteggio);
    text += "<br><i>Punti subiti: </i><br>";
    text += std::to_string(punti_subiti);
    text += "<br><i>Rimbalzi off:</i><br>";
    text += std::to_string(rimbalzi_off);
    text += "<br><i>Rimbalzi dif:</i><br>";
    text += std::to_string(rimbalzi_dif);
    text += "<br><i>Assist: </i><br>";
    text += std::to_string(assist);
    text += "<br><i>Tiri 2 tentati:</i><br>";
    text += std::to_string(tiri2);
    text += "<br><i>Tiri 2 segnati:</i><br>";
    text += std::to_string(tiri2_segnati);
    text += "<br><i>% tiri da 2:</i><br>";
    text += std::to_string(precisione2) +"%";
    text += "<br><i>Tiri 3 tentati:</i><br>";
    text += std::to_string(tiri3);
    text += "<br><i>Tiri 3 segnati:</i><br>";
    text += std::to_string(tiri3_segnati);
    text += "<br><i>% tiri da 3:</i><br>";
    text += std::to_string(precisione3) + "%";
    text += "<br><i>% tiri: </i><br>";
    text += std::to_string(precisione_tiri) + "%";
    text += "<br><i>Liberi: </i><br>";
    text += std::to_string(liberi);
    text += "<br><i>Liberi segnati: </i><br>";
    text += std::to_string(liberi_segnati);
    text += "<br><i>% liberi: </i><br>";
    text += std::to_string(precisione_liberi) + "%";

    return text;
}//print



