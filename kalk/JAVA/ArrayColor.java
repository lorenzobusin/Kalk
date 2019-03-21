
public class ArrayColor{
    private int size;
    private Color[] vector;
            
    ArrayColor(int s){
        size = s;
        vector = new Color[size];
    }//constructor
            
            
    ArrayColor( ArrayColor x){
        size = x.size;
        System.arraycopy(x.vector, 0, vector, 0, size);
    }//copy constructor
    
    ArrayColor(){
        size = 0;
        vector = new Color[size];
        
    }
          
    //operations
    
    void add(int pos,  Color x){
        vector[pos] = x;
    }//add
    
 
    void print(){
        for(int i = 0; i < size; i++){
          vector[i].print();
        }
    }//print
    
     boolean isEmpty(){
         return size > 0;
    }//isEmpty
    
    ArrayColor sum( ArrayColor x){
        int max_size;
        if(size >= x.size)
            max_size = size;
        else
            max_size = x.size;

        ArrayColor temp = new ArrayColor(max_size);

        for(int i = 0; i < temp.size ; i++){
            if(i < size && i < x.size)
                temp.vector[i] = vector[i].sum(x.vector[i]);
            if(i < size && i >= x.size)
                temp.vector[i] = vector[i];
            if(i >= size && i < x.size)
                temp.vector[i] = x.vector[i];
        }//for
        return temp;
    }//sum
    
    ArrayColor substract( ArrayColor x){
        int max_size;
        if(size >= x.size)
            max_size = size;
        else
            max_size = x.size;

      ArrayColor temp = new ArrayColor(max_size);
       Color zero = new Color();
      
        for(int i = 0; i < temp.size ; i++){
            if(i < size && i < x.size)
                temp.vector[i] = vector[i].substract(x.vector[i]);
            if(i < size && i >= x.size)
                temp.vector[i] = zero.substract(vector[i]);
            if(i >= size && i < x.size)
                temp.vector[i] = zero.substract(x.vector[i]);
        }//for
        return temp;
    }//substract
    
    ArrayColor multiplication(int x){
        ArrayColor temp = new ArrayColor(size);
        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].multiplication(x);
        }//for
        return temp;
    }//multiplication
    
    ArrayColor division(int x){
        ArrayColor temp = new ArrayColor(size);
        if(x == 0){
            System.out.println( "Divisione per 0!!!");
            return temp;
        }//if

        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].division(x);
        }//for
        return temp;
    }//division
    
    ArrayColor mod(int x){
        ArrayColor temp = new ArrayColor(size);
        if(x == 0){
            System.out.println( "Divisione per 0!!!");
            return temp;
        }//if

        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].mod(x);
        }//for
        return temp;
    }//mod    
    
    boolean equalTo( ArrayColor x){
        if(size != x.size)
          return false;

       boolean flag = true;
       for(int i = 0;(i < size) && (flag); i++){
               flag = vector[i].equalTo(x.vector[i]);
       }//for
       return flag;
    }//equalTo
    
    Color tot(){
        Color sum = new Color();
        for(int i = 0; i < size; i++)
            sum = sum.sum(vector[i]);
        return sum;
    }//tot
    
    Color media(){
        return tot().division(size);
    }//media
    
     Color mediana(){
        return vector[size/2];
    }//mediana
    
    void moda(){
        int[] temp = new int[size];
        int cont;
        for(int i = 0; i < size; i++){
            cont = 0;
            for(int j = 0; j < size; j++){
                if(vector[i].equalTo(vector[j]))
                    cont++;
            }//for
           temp[i] = cont; // per ogni valore salvo su temp[] il numero di ripetizioni
        }//for

        int massimo = temp[0];
        for(int i = 0; i < size; i++){  // trovo il numero che si ripete più volte
             if(temp[i] > massimo)
             massimo = temp[i];
        }//for

        boolean doppio;
        for(int k = 0; k < size; k++){ // visualizza gli elementi che si ripetono più volte senza considerare doppioni
            if(temp[k] == massimo){
                doppio = false;
                for(int a = k-1; a >= 0 && doppio == false; a--){
                  if(vector[k].equalTo(vector[a]))
                      doppio = true;
                }//for
                if(doppio == false){
                    vector[k].print();
                    System.out.println();
                }
        }//if
    }//for

    System.out.println();
  
    }//moda
    
    Color max(){
        Color massimo = vector[0];
        for(int i = 0; i < size; i++){
            if(vector[i].greaterThan(massimo))
                massimo = vector[i];
        }
        return massimo;
    }//max

    Color min(){
        Color minimo = vector[0];
        for(int i = 0; i < size; i++){
            if(vector[i].lessThan(minimo))
                minimo = vector[i];
        }
        return minimo;
    }//min
    
    void ordinamentoCrescente(){
       int fine;
       for (fine = size - 1; fine > 0; fine-- ){
             for (int i=0; i<fine; i++)
               if (vector[i].greaterThan(vector[i+1])){
                 Color temp = vector[i];
                 vector[i] = vector[i+1];
                 vector[i+1] = temp;
               }
         }
    }//ordinamentoCrescente
    
    void ordinamentoDecrescente(){
       int fine;
       for (fine = size - 1; fine > 0; fine-- ){
             for (int i=0; i<fine; i++)
               if (vector[i].lessThan(vector[i+1])){
                 Color temp = vector[i];
                 vector[i] = vector[i+1];
                 vector[i+1] = temp;
               }
         }
    }//ordinamentoDecrescente
    
     ArrayColor union( ArrayColor x){
        ArrayColor temp = new ArrayColor(size + x.size);
        int cont = 0;
        for(int i = 0; i < size; i++){
            temp.vector[cont] = vector[i];
            cont++;
        }//for

        for(int j = 0; j < x.size; j++){
            temp.vector[cont] = x.vector[j];
            cont++;
        }//for
        return temp;
    }//union
    
     ArrayColor intersection( ArrayColor x){
        int cont = 0;
        ArrayColor temp = new ArrayColor(size);
        boolean flag;
        for(int i = 0; i < size; i++){
            flag = true;
            for(int j = 0; j < (x.size) && (flag); j++){
                if(vector[i].equalTo(x.vector[j])){
                    temp.vector[cont] = vector[i];
                    cont++;
                    flag = false;
                }
             }//for
         }//for
        temp.size = cont;
        return temp;
    }//intersection
     
    boolean greaterThan(ArrayColor x){
        return tot().greaterThan(x.tot());
    }//greaterThan
    
    boolean lessThan(ArrayColor x){
        return tot().lessThan(x.tot());
    }//lessThan
}
