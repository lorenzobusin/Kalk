
public class Football extends Match_stats{
    private int possesso_palla; // in %
    private int gol_subiti;
    private int corner;
    private int cross;
    private int rimesse_laterali;
    private int rigori;
    private int tiri; //tiri totali
    private int tiri_in_porta;
    private int precisione_tiri;// %tiri in porta/tiri totali
    private int fuorigioco;
    private int cartellini_gialli;
    private int cartellini_rossi;
    
    Football(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir,
            int pp, int gs, int ca, int c, int rl, int r, int t, int tp, int f, int cg, int cr){
        
        super(p, fs, fc, m, pallep, pr, passaggit, passaggir);
        
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

        if(tp < 0)
            tiri_in_porta = 0;
        else if(tp > tiri)
            tiri_in_porta = t;
        else
            tiri_in_porta = tp;

        if(tiri <= 0)
            precisione_tiri = 0;
        else{
            float temp = (float)(tiri_in_porta)/(float)(tiri)*100;
            precisione_tiri = (int)temp;
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

    }//constructor
    
    Football(final Football x){
        super(x);
        possesso_palla = x.possesso_palla;
        gol_subiti = x.gol_subiti;
        corner = x.corner;
        cross = x.cross;
        rimesse_laterali = x.rimesse_laterali;
        rigori = x.rigori;
        tiri = x.tiri;
        tiri_in_porta = x.tiri_in_porta;
        precisione_tiri = x.precisione_tiri;
        fuorigioco = x.fuorigioco;
        cartellini_gialli = x.cartellini_gialli;
        cartellini_rossi = x.cartellini_rossi;
    }//copy constructor
    
    Football(){
        this(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    
    Football sum(final Football x){
        return new Football(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti,palle_perse + x.palle_perse,
                            palle_recuperate + x.palle_recuperate, passaggi + x.passaggi, passaggi_riusciti + x.passaggi_riusciti,possesso_palla + x.possesso_palla,
                            gol_subiti + x.gol_subiti, corner + x.corner, cross + x.cross, rimesse_laterali + x.rimesse_laterali, rigori + x.rigori, tiri + x.tiri,
                            tiri_in_porta + x.tiri_in_porta, fuorigioco + x.fuorigioco, cartellini_gialli + x.cartellini_gialli, cartellini_rossi + x.cartellini_rossi);
    }//sum
    
    Football substract(final Football x){
        return new Football(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,palle_perse - x.palle_perse,
                            palle_recuperate - x.palle_recuperate, passaggi - x.passaggi, passaggi_riusciti - x.passaggi_riusciti,possesso_palla - x.possesso_palla,
                            gol_subiti - x.gol_subiti, corner - x.corner, cross - x.cross, rimesse_laterali - x.rimesse_laterali, rigori - x.rigori, tiri - x.tiri,
                            tiri_in_porta - x.tiri_in_porta, fuorigioco - x.fuorigioco, cartellini_gialli - x.cartellini_gialli, cartellini_rossi - x.cartellini_rossi);
    }//substract
    
    Football multiplication(int x){
        return new Football(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x, palle_perse * x, palle_recuperate * x, passaggi * x,
                            passaggi_riusciti * x, possesso_palla * x, gol_subiti * x, corner * x, cross * x, rimesse_laterali * x,rigori * x, tiri * x,
                            tiri_in_porta * x, fuorigioco * x, cartellini_gialli * x, cartellini_rossi * x);
    }//multiplication
    
    Football division(int x){
        if (x == 0){
        System.out.println("Errore divisione per 0");
        return new Football();
        }
        
        return new Football(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x, palle_perse / x, palle_recuperate / x, passaggi / x,
                            passaggi_riusciti / x, possesso_palla / x, gol_subiti / x, corner / x, cross / x, rimesse_laterali / x,rigori / x, tiri / x,
                            tiri_in_porta / x, fuorigioco / x, cartellini_gialli / x, cartellini_rossi / x);
    }//division
    
    Football mod(int x){
        if (x == 0){
        System.out.println("Errore divisione per 0");
        return new Football();
        }
        
        return new Football(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x, palle_perse % x, palle_recuperate % x, passaggi % x,
                            passaggi_riusciti % x, possesso_palla % x, gol_subiti % x, corner % x, cross % x, rimesse_laterali % x,rigori % x, tiri % x,
                            tiri_in_porta % x, fuorigioco % x, cartellini_gialli % x, cartellini_rossi % x);
    }//mod
    
    boolean greaterThan(final Match_stats x){
        return super.greaterThan(x);
    }//greaterThan
    
    final boolean lessThan(final Match_stats x){
        return super.lessThan(x);
    }//lessThan
    
    boolean equalTo(final Football x){
        return super.equalTo(x) && (possesso_palla == x.possesso_palla && gol_subiti == x.gol_subiti && corner == x.corner && cross == x.cross &&
            rimesse_laterali == x.rimesse_laterali && rigori == x.rigori && tiri == x.tiri && tiri_in_porta == x.tiri_in_porta &&
            fuorigioco == x.fuorigioco && cartellini_gialli == x.cartellini_gialli && cartellini_rossi == x.cartellini_rossi);
    }//equalTo
    
    void print(){
        super.print();
        System.out.println("Gol: " + punteggio + "\nGol subiti: " + gol_subiti + "\nPossesso palla: " + possesso_palla + " %" + "\nCalci d'angolo: " + corner +
                           "\nCross: " + cross + "\nRimesse laterali: " + rimesse_laterali + "\nRigori: " + rigori + "\nTiri tentati: " + tiri + "\nTiri in porta: " + tiri_in_porta +
                           "\nPrecisione tiri: " + precisione_tiri + " %" + "\nFuorigioco: " + fuorigioco + "\nCartellini gialli: " + cartellini_gialli + "\nCartellini rossi: " + cartellini_rossi);
    }//print
}
