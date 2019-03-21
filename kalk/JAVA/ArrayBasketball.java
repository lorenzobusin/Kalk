
public class ArrayBasketball {
    private int size;
    private Basketball[] vector;
            
    ArrayBasketball(int s){
        size = s;
        vector = new Basketball[size];
    }//constructor
            
            
    ArrayBasketball( ArrayBasketball x){
        size = x.size;
        System.arraycopy(x.vector, 0, vector, 0, size);
    }//copy constructor
    
    ArrayBasketball(){
        size = 0;
        vector = new Basketball[size];
        
    }
          
    //operations
    
    void add(int pos, Basketball x){
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
    
    ArrayBasketball sum( ArrayBasketball x){
        int max_size;
        if(size >= x.size)
            max_size = size;
        else
            max_size = x.size;

        ArrayBasketball temp = new ArrayBasketball(max_size);

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
    
    ArrayBasketball substract( ArrayBasketball x){
        int max_size;
        if(size >= x.size)
            max_size = size;
        else
            max_size = x.size;

     ArrayBasketball temp = new ArrayBasketball(max_size);
       Basketball zero = new Basketball();
      
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
    
    ArrayBasketball multiplication(int x){
        ArrayBasketball temp = new ArrayBasketball(size);
        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].multiplication(x);
        }//for
        return temp;
    }//multiplication
    
    ArrayBasketball division(int x){
        ArrayBasketball temp = new ArrayBasketball(size);
        if(x == 0){
            System.out.println( "Divisione per 0!!!");
            return temp;
        }//if

        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].division(x);
        }//for
        return temp;
    }//division
    
    ArrayBasketball mod(int x){
        ArrayBasketball temp = new ArrayBasketball(size);
        if(x == 0){
            System.out.println( "Divisione per 0!!!");
            return temp;
        }//if

        for(int i = 0; i < temp.size ; i++){
            temp.vector[i] = vector[i].mod(x);
        }//for
        return temp;
    }//mod    
    
    boolean equalTo( ArrayBasketball x){
        if(size != x.size)
          return false;

       boolean flag = true;
       for(int i = 0;(i < size) && (flag); i++){
               flag = vector[i].equalTo(x.vector[i]);
       }//for
       return flag;
    }//equalTo
    
    Basketball tot(){
        Basketball sum = new Basketball();
        for(int i = 0; i < size; i++)
            sum = sum.sum(vector[i]);
        return sum;
    }//tot
    
    Basketball media(){
        return tot().division(size);
    }//media
    
     Basketball mediana(){
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
    
    Basketball max(){
        Basketball massimo = vector[0];
        for(int i = 0; i < size; i++){
            if(vector[i].greaterThan(massimo))
                massimo = vector[i];
        }
        return massimo;
    }//max

    Basketball min(){
        Basketball minimo = vector[0];
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
                 Basketball temp = vector[i];
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
                 Basketball temp = vector[i];
                 vector[i] = vector[i+1];
                 vector[i+1] = temp;
               }
         }
    }//ordinamentoDecrescente
    
     ArrayBasketball union( ArrayBasketball x){
        ArrayBasketball temp = new ArrayBasketball(size + x.size);
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
    
     ArrayBasketball intersection( ArrayBasketball x){
        int cont = 0;
        ArrayBasketball temp = new ArrayBasketball(size);
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
     
    boolean greaterThan(ArrayBasketball x){
        return tot().greaterThan(x.tot());
    }//greaterThan
    
    boolean lessThan(ArrayBasketball x){
        return tot().lessThan(x.tot());
    }//lessThan
}
