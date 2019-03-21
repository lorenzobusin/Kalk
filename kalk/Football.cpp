//file Football.cpp

#include "Football.h"

Football::Football(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir,
                   int pp, int gs, int ca, int c, int rl, int r, int t, int tp, int f, int cg, int cr)
                   : Match_stats(p, fs, fc, m, pallep, pr, passaggit, passaggir){

    if(pp < 0)
        possesso_palla = 0;
    else if(pp >100)
        possesso_palla = 100;
    else
        possesso_palla = pp;

    if(gs < 0)
        gol_subiti = 0;
    else
        gol_subiti = gs;

    if(ca < 0)
        corner = 0;
    else
        corner = ca;

    if(c < 0)
        cross = 0;
    else
        cross = c;

    if(rl < 0)
        rimesse_laterali = 0;
    else
        rimesse_laterali = rl;

    if(r < 0)
        rigori = 0;
    else
        rigori = r;

    if(t < 0)
        tiri = 0;
    else
        tiri = t;

    if(tp <= 0)
        tiri_in_porta = 0;
    else if(tp > t)
        tiri_in_porta = t;
    else
        tiri_in_porta = tp;

    if(tiri <= 0)
        precisione_tiri = 0;
    else{
        float temp = float(tiri_in_porta)/float(tiri)*100;
        precisione_tiri = int(temp);
    }

    if(f < 0)
        fuorigioco = 0;
    else
        fuorigioco = f;

    if(cg < 0)
        cartellini_gialli = 0;
    else
        cartellini_gialli = cg;

    if(cr < 0)
        cartellini_rossi = 0;
    else
        cartellini_rossi = cr;

}//costruttore

Football::~Football(){

}//distruttore

Football::Football(const Football& copia):Match_stats(copia){
    possesso_palla = copia.possesso_palla;
    gol_subiti = copia.gol_subiti;
    corner = copia.corner;
    cross = copia.cross;
    rimesse_laterali = copia.rimesse_laterali;
    rigori = copia.rigori;
    tiri = copia.tiri;
    tiri_in_porta = copia.tiri_in_porta;
    precisione_tiri = copia.precisione_tiri;
    fuorigioco = copia.fuorigioco;
    cartellini_gialli = copia.cartellini_gialli;
    cartellini_rossi = copia.cartellini_rossi;
}//costruttore di copia

Football* Football::operator+(const Football& x) const{
    return new Football(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti,palle_perse + x.palle_perse,
                    palle_recuperate + x.palle_recuperate, passaggi + x.passaggi, passaggi_riusciti + x.passaggi_riusciti,possesso_palla + x.possesso_palla,
                    gol_subiti + x.gol_subiti, corner + x.corner, cross + x.cross, rimesse_laterali + x.rimesse_laterali, rigori + x.rigori, tiri + x.tiri,
                    tiri_in_porta + x.tiri_in_porta, fuorigioco + x.fuorigioco, cartellini_gialli + x.cartellini_gialli, cartellini_rossi + x.cartellini_rossi);

}//operator+

Football* Football::operator-(const Football& x) const{
    return new Football(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,palle_perse - x.palle_perse,
                    palle_recuperate - x.palle_recuperate, passaggi - x.passaggi, passaggi_riusciti - x.passaggi_riusciti, possesso_palla - x.possesso_palla,
                    gol_subiti - x.gol_subiti, corner - x.corner, cross - x.cross, rimesse_laterali - x.rimesse_laterali, rigori - x.rigori,
                    tiri - x.tiri, tiri_in_porta - x.tiri_in_porta, fuorigioco - x.fuorigioco, cartellini_gialli - x.cartellini_gialli,
                    cartellini_rossi - x.cartellini_rossi);
}//operator-

Football* Football::operator*(int x) const{
    return new Football(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x, palle_perse * x, palle_recuperate * x, passaggi * x,
                    passaggi_riusciti * x, possesso_palla * x, gol_subiti * x, corner * x, cross * x, rimesse_laterali * x,rigori * x, tiri * x,
                    tiri_in_porta * x, fuorigioco * x, cartellini_gialli * x, cartellini_rossi * x);
}//operator*

Football* Football::operator/(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!";
        return new Football();
    }
    return new Football(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x, palle_perse / x, palle_recuperate / x, passaggi / x,
                    passaggi_riusciti / x, possesso_palla / x, gol_subiti / x, corner / x, cross / x, rimesse_laterali / x,rigori / x, tiri / x,
                    tiri_in_porta / x, fuorigioco / x, cartellini_gialli / x, cartellini_rossi / x);
}//operator/

Football* Football::operator%(int x) const{
    if(x == 0){
        std::cout << "Divisione per 0!";
        return new Football();
    }
    return new Football(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x, palle_perse % x, palle_recuperate % x, passaggi % x,
                    passaggi_riusciti % x, possesso_palla % x, gol_subiti % x, corner % x, cross % x, rimesse_laterali % x,rigori % x, tiri % x,
                    tiri_in_porta % x, fuorigioco % x, cartellini_gialli % x, cartellini_rossi % x);
}//operator%

Football Football::operator=(const Football& copia){
    Match_stats::operator=(copia);

    possesso_palla = copia.possesso_palla;
    gol_subiti = copia.gol_subiti;
    corner = copia.corner;
    cross = copia.cross;
    rimesse_laterali = copia.rimesse_laterali;
    rigori = copia.rigori;
    tiri = copia.tiri;
    tiri_in_porta = copia.tiri_in_porta;
    precisione_tiri = copia.precisione_tiri;
    fuorigioco = copia.fuorigioco;
    cartellini_gialli = copia.cartellini_gialli;
    cartellini_rossi = copia.cartellini_rossi;
    return *this;
}//operator=

bool Football::operator==(const Football& x){
    return  Match_stats::operator==(x) && (possesso_palla == x.possesso_palla && gol_subiti == x.gol_subiti && corner == x.corner && cross == x.cross &&
            rimesse_laterali == x.rimesse_laterali && rigori == x.rigori && tiri == x.tiri && tiri_in_porta == x.tiri_in_porta &&
            fuorigioco == x.fuorigioco && cartellini_gialli == x.cartellini_gialli && cartellini_rossi == x.cartellini_rossi);
}//operator==

bool Football::operator>(const Football& x){
    return Match_stats::operator>(x);
}//operator>

bool Football::operator<(const Football& x){
    return Match_stats::operator<(x);
}//operator<

int Football::getPpalla() const{
    return possesso_palla;
}

int Football::getGs() const{
    return gol_subiti;
}

int Football::getC() const{
    return corner;
}

int Football::getCross() const{
    return cross;
}

int Football::getRim() const{
    return rimesse_laterali;
}

int Football::getR() const{
    return rigori;
}

int Football::getT() const{
    return tiri;
}

int Football::getTporta() const{
    return tiri_in_porta;
}

int Football::getPrecT() const{
    return precisione_tiri;
}

int Football::getF() const{
    return fuorigioco;
}

int Football::getCg() const{
    return cartellini_gialli;
}

int Football::getCr() const{
    return cartellini_rossi;
}

void Football::setFootballMatch(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir,
                                int pp, int gs, int ca, int c, int rl, int r, int t, int tp, int f, int cg, int cr){

    setMatch(p, fs, fc, m, pallep, pr, passaggit, passaggir);
    if(pp <= 0)
        possesso_palla = 0;
    else if(pp >100)
        possesso_palla = 100;
    else
        possesso_palla = pp;

    if(gs < 0)
        gol_subiti = 0;
    else
        gol_subiti = gs;

    if(ca < 0)
        corner = 0;
    else
        corner = ca;

    if(c < 0)
        cross = 0;
    else
        cross = c;

    if(rl < 0)
        rimesse_laterali = 0;
    else
        rimesse_laterali = rl;

    if(r < 0)
        rigori = 0;
    else
        rigori = r;

    if(t < 0)
        tiri = 0;
    else
        tiri = t;

    if(tp < 0)
        tiri_in_porta = 0;
    else if(tp > t)
        tiri_in_porta = t;
    else
        tiri_in_porta = tp;

    if(tiri <= 0)
        precisione_tiri = 0;
    else{
        float temp = float(tiri_in_porta)/float(tiri)*100;
        precisione_tiri = int(temp);
    }

    if(f < 0)
        fuorigioco = 0;
    else
        fuorigioco = f;

    if(cg < 0)
        cartellini_gialli = 0;
    else
        cartellini_gialli = cg;

    if(cr < 0)
        cartellini_rossi = 0;
    else
        cartellini_rossi = cr;
}

std::string Football::print() const{
    std::string text;
    text +=Match_stats::print();
    text += "<br><i>Gol: </i><br>";
    text += std::to_string(punteggio);
    text += "<br><i>Gol subiti: </i><br>";
    text += std::to_string(gol_subiti);
    text += "<br><i>Possesso palla: </i><br>";
    text += std::to_string(possesso_palla) + "%";
    text += "<br><i>Calci d'angolo:</i><br>";
    text += std::to_string(palle_perse);
    text += "<br><i>Cross:</i><br>";
    text += std::to_string(cross);
    text += "<br><i>Rimesse laterali:</i><br>";
    text += std::to_string(rimesse_laterali);
    text += "<br><i>Rigori:</i><br>";
    text += std::to_string(rigori);
    text += "<br><i>Tiri tentati:</i><br>";
    text += std::to_string(tiri);
    text += "<br><i>Tiri in porta:</i><br>";
    text += std::to_string(tiri_in_porta);
    text += "<br><i>% tiri:</i><br>";
    text += std::to_string(precisione_tiri) + "%";
    text += "<br><i>Fuorigioco:</i><br>";
    text += std::to_string(fuorigioco);
    text += "<br><i>Certellini gialli:</i><br>";
    text += std::to_string(cartellini_gialli);
    text += "<br><i>Cartellini rossi:</i><br>";
    text += std::to_string(cartellini_rossi);

    return text;

}//print
