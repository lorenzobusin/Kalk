public class Match_stats {
    protected int punteggio;
    protected int falli_subiti;
    protected int falli_commessi;
    protected int minuti;
    protected int palle_perse;
    protected int palle_recuperate;
    protected int passaggi; // passaggi totali
    protected int passaggi_riusciti;
    protected int precisione_passaggi; //% passaggi riusciti/passaggi totali
    
    Match_stats(int p, int fs, int fc, int m, int pp, int pr, int passaggit, int passaggir){
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
            float temp = ((float)passaggi_riusciti)/((float)passaggi)*100;
            precisione_passaggi = (int) temp;
        }

    }//constructor
    
    Match_stats( Match_stats x){
        this(x.punteggio, x.falli_subiti, x.falli_commessi, x.minuti, x.palle_perse, x.palle_recuperate, x.passaggi, x.passaggi_riusciti);
    }//copy constructor
    
    
    Match_stats(){
        this(0, 0, 0, 0, 0, 0, 0, 0);
    }
    
    //operations
    
     Match_stats sum( Match_stats x){
        return new Match_stats(punteggio + x.punteggio, falli_subiti + x.falli_subiti, falli_commessi + x.falli_commessi, minuti + x.minuti,
                       palle_perse + x.palle_perse, palle_recuperate + x.palle_recuperate, passaggi + x.passaggi,
                       passaggi_riusciti + x.passaggi_riusciti);
    }//sum
    
     Match_stats substract( Match_stats x){
        return new Match_stats(punteggio - x.punteggio, falli_subiti - x.falli_subiti, falli_commessi - x.falli_commessi, minuti - x.minuti,
                       palle_perse - x.palle_perse, palle_recuperate - x.palle_recuperate, passaggi - x.passaggi,
                       passaggi_riusciti - x.passaggi_riusciti);
    }//substract
    
    Match_stats multiplication(int x){
        return new Match_stats(punteggio * x, falli_subiti * x, falli_commessi * x, minuti * x, palle_perse * x, palle_recuperate * x, passaggi * x,
                       passaggi_riusciti * x);
    }//multiplication
    
    Match_stats division(int x){
        if (x == 0){
        System.out.println("Errore divisione per 0");
        return new Match_stats();
        }

        return new Match_stats(punteggio / x, falli_subiti / x, falli_commessi / x, minuti / x, palle_perse / x, palle_recuperate / x, passaggi / x,
                       passaggi_riusciti / x);
    }//division
    
    Match_stats mod(int x){
       if (x == 0){
       System.out.println("Errore divisione per 0");
       return new Match_stats();
       }
    
       return new Match_stats(punteggio % x, falli_subiti % x, falli_commessi % x, minuti % x, palle_perse % x, palle_recuperate % x, passaggi % x,
                       passaggi_riusciti % x); 
    }//mod
    
    boolean greaterThan( Match_stats x){
        return punteggio > x.punteggio;
    }//greaterThan
    
    boolean lessThan( Match_stats x){
        return punteggio < x.punteggio;
    }//lessThan
    
    boolean equalTo( Match_stats x){
        return (punteggio == x.punteggio && falli_subiti == x.falli_subiti && falli_commessi == x.falli_commessi && minuti == x.minuti &&
                palle_perse == x.palle_perse && palle_recuperate == x.palle_recuperate && passaggi == x.passaggi &&
                passaggi_riusciti == x.passaggi_riusciti);
    }//equalTo
    
    void print(){
        System.out.println("\nFalli subiti: " + falli_subiti + "\nFalli commessi: " + falli_commessi + "\nMinuti giocati: " + minuti + "\nPalle perse: " + palle_perse +
                           "\nPalle recuperate: " + palle_recuperate + "\nPassaggi effettuati: " + passaggi + "\nPassaggi riusciti: " + passaggi_riusciti + "\nPrecisione passaggi: " + precisione_passaggi + " %");
    }//print
    
}
