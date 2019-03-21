
public class Kalk {
    
    public static void main(String[] args) {
        
        Color c1 = new Color(50,60,70);
        Color c2 = new Color(200,100,50);
        Color c3 = new Color(50,60,70);
        Color c4 = new Color(229,156,100);
        Color c5 = new Color(67,10,0);
        Color c6 = new Color(200,100,50);
        ArrayColor arrColor1 = new ArrayColor(4);
        ArrayColor arrColor2 = new ArrayColor(2);
        arrColor1.add(0,c1);
        arrColor1.add(1,c2);
        arrColor1.add(2,c3);
        arrColor1.add(3,c4);
        arrColor2.add(0,c5);
        arrColor2.add(1,c6);
        
        System.out.println("OPERAZIONI CON COLOR\n");
        System.out.println("Somma\n");
        c3.sum(c5).print();
        System.out.println("Sottrazione\n");
        c4.substract(c5).print();
        System.out.println("Moltiplicazione per 2\n");
        c3.multiplication(2).print();
        System.out.println("Divisione per 2\n");
        c3.division(2).print();
        System.out.println("Modulo per 2\n");
        c3.mod(2).print();
        System.out.println("Negazione\n");
        c4.negation();
        c4.print();
        
        System.out.println("OPERAZIONI CON ARRAY DI COLORI\n");
        System.out.println("Somma\n");
        arrColor1.sum(arrColor2).print();
        System.out.println("Sottrazione\n");
        arrColor1.substract(arrColor2).print();
        System.out.println("Moltiplicazione per 2\n");
        arrColor1.multiplication(2).print();
        System.out.println("Divisione per 2\n");
        arrColor1.division(2).print();
        System.out.println("Modulo per 2\n");
        arrColor1.mod(2).print();
        System.out.println("Array1 == array2?\n");
        if(arrColor1.equalTo(arrColor2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Array1 > array2?\n");
        if(arrColor1.greaterThan(arrColor2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Array1 < array2?\n");
        if(arrColor1.lessThan(arrColor2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Totale array1\n");
        arrColor1.tot().print();
        System.out.println("Media array1\n");
        arrColor1.media().print();
        System.out.println("Mediana array1\n");
        arrColor1.mediana().print();
        System.out.println("Moda array1\n");
        arrColor1.moda();
        System.out.println("Massimo array1\n");
        arrColor1.max().print();
        System.out.println("Minimo array1\n");
        arrColor1.min().print();
        System.out.println("Ordinamento crescente array1\n");
        arrColor1.ordinamentoCrescente();
        arrColor1.print();
        System.out.println("Ordinamento decrescente array1\n");
        arrColor1.ordinamentoDecrescente();
        arrColor1.print();
        System.out.println("Unione tra array1 e array2\n");
        arrColor1.union(arrColor2).print();
        System.out.println("Intersezione tra array1 e array\n");
        arrColor1.intersection(arrColor2).print();
        
        
        Bandwidth b1 = new Bandwidth(100,77,0);
        Bandwidth b2 = new Bandwidth(10,100,20);
        Bandwidth b3 = new Bandwidth(100,77,0);
        Bandwidth b4 = new Bandwidth(200,55,10);
        Bandwidth b5 = new Bandwidth(22,77,30);
        Bandwidth b6 = new Bandwidth(100,77,0);
        ArrayBandwidth arrBand1 = new ArrayBandwidth(4);
        ArrayBandwidth arrBand2 = new ArrayBandwidth(2);
        arrBand1.add(0,b1);
        arrBand1.add(1,b2);
        arrBand1.add(2,b3);
        arrBand1.add(3,b4);
        arrBand2.add(0,b5);
        arrBand2.add(1,b6);
        
        System.out.println("OPERAZIONI CON BANDWIDTH\n");
        System.out.println("Somma\n");
        b3.sum(b5).print();
        System.out.println("Sottrazione\n");
        b4.substract(b5).print();
        System.out.println("Moltiplicazione per 2\n");
        b3.multiplication(2).print();
        System.out.println("Divisione per 2\n");
        b3.division(2).print();
        System.out.println("Modulo per 2\n");
        b3.mod(2).print();
        
        System.out.println("OPERAZIONI CON ARRAY DI BANDWIDTH\n");
        System.out.println("Somma\n");
        arrBand1.sum(arrBand2).print();
        System.out.println("Sottrazione\n");
        arrBand1.substract(arrBand2).print();
        System.out.println("Moltiplicazione per 2\n");
        arrBand1.multiplication(2).print();
        System.out.println("Divisione per 2\n");
        arrBand1.division(2).print();
        System.out.println("Modulo per 2\n");
        arrBand1.mod(2).print();
        System.out.println("Array1 == array2?\n");
        if(arrBand1.equalTo(arrBand2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Array1 > array2?\n");
        if(arrBand1.greaterThan(arrBand2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Array1 < array2?\n");
        if(arrBand1.lessThan(arrBand2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("Totale array1\n");
        arrBand1.tot().print();
        System.out.println("Media array1\n");
        arrBand1.media().print();
        System.out.println("Mediana array1\n");
        arrBand1.mediana().print();
        System.out.println("Moda array1\n");
        arrBand1.moda();
        System.out.println("Massimo array1\n");
        arrBand1.max().print();
        System.out.println("Minimo array1\n");
        arrBand1.min().print();
        System.out.println("Ordinamento crescente array1\n");
        arrBand1.ordinamentoCrescente();
        arrBand1.print();
        System.out.println("Ordinamento decrescente array1\n");
        arrBand1.ordinamentoDecrescente();
        arrBand1.print();
        System.out.println("Unione tra array1 e array2\n");
        arrBand1.union(arrBand2).print();
        System.out.println("Intersezione tra array1 e array\n");
        arrBand1.intersection(arrBand2).print();
        
        
        Match_stats m1 = new Match_stats(10,5,3,4,5,8,19,2);
        Match_stats m2 = new Match_stats(10,22,3,4,5,1,19,2);
        Match_stats m3 = new Match_stats(23,3,1,6,8,4,2,3);
        Match_stats m4 = new Match_stats(23,3,1,6,8,4,2,3);
        Match_stats m5 = new Match_stats(3,4,5,8,1,2,33,4);
        Match_stats m6 = new Match_stats(10,5,3,4,5,8,19,2);
        ArrayMatch_stats arrMatch1 = new ArrayMatch_stats(4);
        ArrayMatch_stats arrMatch2 = new ArrayMatch_stats(2);
        arrMatch1.add(0,m1);
        arrMatch1.add(1,m2);
        arrMatch1.add(2,m3);
        arrMatch1.add(3,m4);
        arrMatch2.add(0,m5);
        arrMatch2.add(1,m6);
        
        System.out.println("\nOPERAZIONI CON MATCH_STATS\n");
        System.out.println("\nSomma\n");
        m3.sum(m5).print();
        System.out.println("\nSottrazione\n");
        m4.substract(m5).print();
        System.out.println("\nMoltiplicazione per 2\n");
        m3.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        m3.division(2).print();
        System.out.println("\nModulo per 2\n");
        m3.mod(2).print();
        
        System.out.println("\nOPERAZIONI CON ARRAY DI MATCH_STATS\n");
        System.out.println("\nSomma\n");
        arrMatch1.sum(arrMatch2).print();
        System.out.println("\nSottrazione\n");
        arrMatch1.substract(arrMatch2).print();
        System.out.println("\nMoltiplicazione per 2\n");
        arrMatch1.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        arrMatch1.division(2).print();
        System.out.println("\nModulo per 2\n");
        arrMatch1.mod(2).print();
        System.out.println("\nArray1 == array2?\n");
        if(arrMatch1.equalTo(arrMatch2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 > array2?\n");
        if(arrMatch1.greaterThan(arrMatch2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 < array2?\n");
        if(arrMatch1.lessThan(arrMatch2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nTotale array1\n");
        arrMatch1.tot().print();
        System.out.println("\nMedia array1\n");
        arrMatch1.media().print();
        System.out.println("\nMediana array1\n");
        arrMatch1.mediana().print();
        System.out.println("\nModa array1\n");
        arrMatch1.moda();
        System.out.println("\nMassimo array1\n");
        arrMatch1.max().print();
        System.out.println("\nMinimo array1\n");
        arrMatch1.min().print();
        System.out.println("\nOrdinamento crescente array1\n");
        arrMatch1.ordinamentoCrescente();
        arrMatch1.print();
        System.out.println("\nOrdinamento decrescente array1\n");
        arrMatch1.ordinamentoDecrescente();
        arrMatch1.print();
        System.out.println("\nUnione tra array1 e array2\n");
        arrMatch1.union(arrMatch2).print();
        System.out.println("\nIntersezione tra array1 e array\n");
        arrMatch1.intersection(arrMatch2).print();
        
        
        Football f1 = new Football(10,5,3,4,5,8,19,2,5,6,7,8,2,12,23,4,5,6,7);
        Football f2 = new Football(10,22,3,4,5,1,19,2,8,3,5,6,9,10,7,4,6,7,8);
        Football f3 = new Football(23,3,1,6,8,4,2,3,1,22,5,8,3,4,5,6,7,8,2);
        Football f4 = new Football(10,22,3,4,5,1,19,2,8,3,5,6,9,10,7,4,6,7,8);
        Football f5 = new Football(3,4,5,8,1,2,33,4,7,7,7,7,3,2,1,2,4,5,6);
        Football f6 = new Football(10,5,3,4,5,8,19,2,5,6,7,8,2,12,23,4,5,6,7);
        ArrayFootball arrFoot1 = new ArrayFootball(4);
        ArrayFootball arrFoot2 = new ArrayFootball(2);
        arrFoot1.add(0,f1);
        arrFoot1.add(1,f2);
        arrFoot1.add(2,f3);
        arrFoot1.add(3,f4);
        arrFoot2.add(0,f5);
        arrFoot2.add(1,f6);
        
        System.out.println("\nOPERAZIONI CON FOOTBALL\n");
        System.out.println("\nSomma\n");
        f3.sum(f5).print();
        System.out.println("\nSottrazione\n");
        f4.substract(f5).print();
        System.out.println("\nMoltiplicazione per 2\n");
        f3.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        f3.division(2).print();
        System.out.println("\nModulo per 2\n");
        f3.mod(2).print();
        
        System.out.println("\nOPERAZIONI CON ARRAY DI FOOTBALL\n");
        System.out.println("\nSomma\n");
        arrFoot1.sum(arrFoot2).print();
        System.out.println("\nSottrazione\n");
        arrFoot1.substract(arrFoot2).print();
        System.out.println("\nMoltiplicazione per 2\n");
        arrFoot1.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        arrFoot1.division(2).print();
        System.out.println("\nModulo per 2\n");
        arrFoot1.mod(2).print();
        System.out.println("\nArray1 == array2?\n");
        if(arrFoot1.equalTo(arrFoot2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 > array2?\n");
        if(arrFoot1.greaterThan(arrFoot2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 < array2?\n");
        if(arrFoot1.lessThan(arrFoot2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nTotale array1\n");
        arrFoot1.tot().print();
        System.out.println("\nMedia array1\n");
        arrFoot1.media().print();
        System.out.println("\nMediana array1\n");
        arrFoot1.mediana().print();
        System.out.println("\nModa array1\n");
        arrFoot1.moda();
        System.out.println("\nMassimo array1\n");
        arrFoot1.max().print();
        System.out.println("\nMinimo array1\n");
        arrFoot1.min().print();
        System.out.println("\nOrdinamento crescente array1\n");
        arrFoot1.ordinamentoCrescente();
        arrMatch1.print();
        System.out.println("\nOrdinamento decrescente array1\n");
        arrFoot1.ordinamentoDecrescente();
        arrFoot1.print();
        System.out.println("\nUnione tra array1 e array2\n");
        arrFoot1.union(arrFoot2).print();
        System.out.println("\nIntersezione tra array1 e array\n");
        arrFoot1.intersection(arrFoot2).print();
        
        
        Basketball bb1 = new Basketball(10,5,3,4,5,8,19,2,5,6,7,8,2,12,23,4,5,6,7);
        Basketball bb2 = new Basketball(100,4,1,7,8,2,22,3,4,5,12,16,7,8,8,6,14,2,4);
        Basketball bb3 = new Basketball(100,4,1,7,8,2,22,3,4,5,12,16,7,8,8,6,14,2,4);
        Basketball bb4 = new Basketball(80,55,10,5,6,8,12,18,24,5,9,19,4,23,27,4,3,4,7);
        Basketball bb5 = new Basketball(22,77,30,8,1,19,24,30,6,8,8,8,9,5,2,12,23,4,5);
        Basketball bb6 = new Basketball(10,5,3,4,5,8,19,2,5,6,7,8,2,12,23,4,5,6,7);
        ArrayBasketball arrBask1 = new ArrayBasketball(4);
        ArrayBasketball arrBask2 = new ArrayBasketball(2);
        arrBask1.add(0,bb1);
        arrBask1.add(1,bb2);
        arrBask1.add(2,bb3);
        arrBask1.add(3,bb4);
        arrBask2.add(0,bb5);
        arrBask2.add(1,bb6);
        
        System.out.println("\nOPERAZIONI CON BASKETBALL\n");
        System.out.println("\nSomma\n");
        bb3.sum(bb5).print();
        System.out.println("\nSottrazione\n");
        bb4.substract(bb5).print();
        System.out.println("\nMoltiplicazione per 2\n");
        bb3.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        bb3.division(2).print();
        System.out.println("\nModulo per 2\n");
        bb3.mod(2).print();
        
        System.out.println("\nOPERAZIONI CON ARRAY DI BASKETBALL\n");
        System.out.println("\nSomma\n");
        arrBask1.sum(arrBask2).print();
        System.out.println("\nSottrazione\n");
        arrBask1.substract(arrBask2).print();
        System.out.println("\nMoltiplicazione per 2\n");
        arrBask1.multiplication(2).print();
        System.out.println("\nDivisione per 2\n");
        arrBask1.division(2).print();
        System.out.println("\nModulo per 2\n");
        arrBask1.mod(2).print();
        System.out.println("\nArray1 == array2?\n");
        if(arrBask1.equalTo(arrBask2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 > array2?\n");
        if(arrBask1.greaterThan(arrBask2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nArray1 < array2?\n");
        if(arrBask1.lessThan(arrBask2))
            System.out.println("TRUE\n");
        else
            System.out.println("FALSE\n");
        System.out.println("\nTotale array1\n");
        arrBask1.tot().print();
        System.out.println("\nMedia array1\n");
        arrBask1.media().print();
        System.out.println("\nMediana array1\n");
        arrBask1.mediana().print();
        System.out.println("\nModa array1\n");
        arrBask1.moda();
        System.out.println("\nMassimo array1\n");
        arrBask1.max().print();
        System.out.println("\nMinimo array1\n");
        arrBask1.min().print();
        System.out.println("\nOrdinamento crescente array1\n");
        arrBask1.ordinamentoCrescente();
        arrBask1.print();
        System.out.println("\nOrdinamento decrescente array1\n");
        arrBask1.ordinamentoDecrescente();
        arrBask1.print();
        System.out.println("\nUnione tra array1 e array2\n");
        arrBask1.union(arrBask2).print();
        System.out.println("\nIntersezione tra array1 e array\n");
        arrBask2.intersection(arrBask2).print();
        
    }

}
