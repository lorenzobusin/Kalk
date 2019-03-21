
public class Basketball extends Match_stats{
    
    private int punti_subiti;
    private int rimbalzi_off;
    private int rimbalzi_dif;
    private int assist;
    private int stoppate;
    private int tiri2;
    private int tiri2_segnati;
    private int precisione2;
    private int tiri3;
    private int tiri3_segnati;
    private int precisione3;
    private int precisione_tiri;
    private int liberi;
    private int liberi_segnati;
    private int precisione_liberi;
    
    Basketball(int p, int fs, int fc, int m, int pallep, int pr, int passaggit, int passaggir, int ps, int rimoff,
                       int rimdif, int a,int stop, int t2, int t2segn, int t3, int t3segn, int l, int lsegn){
        
        super(p, fs, fc, m, pallep, pr, passaggit, passaggir);
        
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
        else if(t2segn > t2)
            tiri2_segnati = t2;
        else
            tiri2_segnati = t2segn;
        
        if(t2 <= 0)
            precisione2 = 0;
        else{
            float temp = (float)(tiri2_segnati)/(float)(tiri2)*100;
            precisione2 = (int)temp;
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
            float temp2 = (float)(tiri3_segnati)/(float)(tiri3)*100;
            precisione3 = (int)temp2;
        }
        
        if(tiri2 + tiri3 <= 0)
            precisione_tiri = 0;
        else{
            float temp3 = (float)(tiri2_segnati + tiri3_segnati)/(float)(tiri2 + tiri3)*100;
            precisione_tiri = (int)temp3;
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
        if(liberi <= 0)
            precisione_liberi = 0;
        else{
            float temp4 = (float)(liberi_segnati)/(float)(liberi)*100;
            precisione_liberi = (int)temp4;
        }
    }//constructor
    
    Basketball(final Basketball x){
        
        super(x);
        
        punti_subiti = x.punti_subiti;
        rimbalzi_off = x.rimbalzi_off;
        rimbalzi_dif = x.rimbalzi_dif;
        assist = x.assist;
        stoppate = x.stoppate;
        tiri2 = x.tiri2;
        tiri2_segnati = x.tiri2_segnati;
        precisione2 = x.precisione2;
        tiri3 = x.tiri3;
        tiri3_segnati = x.tiri3_segnati;
        precisione3 = x.precisione3;
        precisione_tiri = x.precisione_tiri;
        liberi = x.liberi;
        liberi_segnati = x.liberi_segnati;
        precisione_liberi = x.precisione_liberi;
    }//copy constructor
    
    Basketball(){
        this(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }

    Basketball sum(final Basketball x){
        return new Basketball(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti, palle_perse + x.palle_perse,
                              palle_recuperate + x.palle_recuperate, passaggi + x.passaggi, passaggi_riusciti + x.passaggi_riusciti, punti_subiti + x.punti_subiti,
                              rimbalzi_off + x.rimbalzi_off, rimbalzi_dif + x.rimbalzi_dif, assist + x.assist, stoppate + x.stoppate, tiri2 + x.tiri2, tiri2_segnati + x.tiri2_segnati,
                              tiri3 + x.tiri3, tiri3_segnati + x.tiri3_segnati, liberi + x.liberi, liberi_segnati + x.liberi_segnati);
    }//sum
    
    Basketball substract(final Basketball x){
        return new Basketball(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,palle_perse - x.palle_perse,
                              palle_recuperate - x.palle_recuperate, passaggi - x.passaggi, passaggi_riusciti - x.passaggi_riusciti, punti_subiti - x.punti_subiti,
                              rimbalzi_off - x.rimbalzi_off, rimbalzi_dif - x.rimbalzi_dif, assist - x.assist, stoppate - x.stoppate, tiri2 - x.tiri2, tiri2_segnati - x.tiri2_segnati,
                              tiri3 - x.tiri3, tiri3_segnati - x.tiri3_segnati, liberi - x.liberi, liberi_segnati - x.liberi_segnati);
    }//substract
    
    Basketball multiplication(int x){
        return new Basketball(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x,palle_perse * x, palle_recuperate * x, passaggi * x,
                              passaggi_riusciti * x, punti_subiti * x, rimbalzi_off * x, rimbalzi_dif * x, assist * x, stoppate * x, tiri2 * x,
                              tiri2_segnati * x, tiri3 * x, tiri3_segnati * x, liberi * x, liberi_segnati * x);
    }//multiplication
        
    Basketball division(int x){
        if (x == 0){
        System.out.println("Errore divisione per 0");
        return new Basketball();
        }
        
        return new Basketball(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x,palle_perse / x, palle_recuperate / x, passaggi / x,
                              passaggi_riusciti / x, punti_subiti / x, rimbalzi_off / x, rimbalzi_dif / x, assist / x, stoppate / x, tiri2 / x,
                              tiri2_segnati / x, tiri3 / x, tiri3_segnati / x, liberi / x, liberi_segnati / x);
    }//division
    
    Basketball mod(int x){
        if (x == 0){
        System.out.println("Errore divisione per 0");
        return new Basketball();
        }
        
        return new Basketball(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x,palle_perse % x, palle_recuperate % x, passaggi % x,
                              passaggi_riusciti % x, punti_subiti % x, rimbalzi_off % x, rimbalzi_dif % x, assist % x, stoppate % x, tiri2 % x,
                              tiri2_segnati % x, tiri3 % x, tiri3_segnati % x, liberi % x, liberi_segnati % x);
    }//mod
    
    boolean greatherThan(final Basketball x){
        return super.greaterThan(x);
    }//greatherThan
    
    boolean lessThan(final Basketball x){
        return super.lessThan(x);
    }//lessThan
    
    boolean equalTo(final Basketball x){
        return super.equalTo(x) && (punti_subiti == x.punti_subiti && rimbalzi_off == x.rimbalzi_off && rimbalzi_dif == x.rimbalzi_dif &&
                                    assist == x.assist && stoppate == x.stoppate && tiri2 == x.tiri2 && tiri2_segnati == x.tiri2_segnati &&
                                    tiri3 == x.tiri3 && tiri3_segnati == x.tiri3_segnati && liberi == x.liberi && liberi_segnati == x.liberi_segnati &&
                                    precisione2 == x.precisione2 && precisione3 == x.precisione3 && precisione_liberi == x.precisione_liberi &&
                                    precisione_tiri == x.precisione_tiri);
    }//equalTo
    
    void print(){
        super.print();
        System.out.println("Punti: " + punteggio + "\nPunti subiti: " + punti_subiti + "\nRimbalzi offensivi: " + rimbalzi_off + "\nRimbalzi difensivi: " + rimbalzi_dif +
                           "\nAssist: " + assist + "\nTiri da 2 tentati: " + tiri2 + "\nTiri da 2 segnati: " + tiri2_segnati + "\nPercentuale tiri da 2: " + precisione2 +
                           " % \nTiri da 3 tentati: " + tiri3 + "\nTiri da 3 segnati: " + tiri3_segnati + "\nPercentuale tiri da 3: " + precisione3 + " % \nTiri liberi: " + liberi +
                           "\nTiri liberi segnati: " + liberi_segnati + "\nPrecisione tiri liberi: " + precisione_liberi + " % \n");
    }//print
    
}
