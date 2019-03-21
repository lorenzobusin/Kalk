
#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>

template<class T>
class Array {

private:
    unsigned int size;
    unsigned int capacity;
    T* vector;

public:

    Array(unsigned int = 0, unsigned int = 0);
    Array(const Array&);
    ~Array();
    void setElement(int, T);
    void printArray() const;
    bool isEmpty() const;
    void push_back(T);
    T pop_back();

    T getObj(int) const;
    int getSize() const;
    int getCapacity() const;

    //overload
    Array operator+(const Array&) const;
    Array operator-(const Array&) const;
    Array operator*(int) const;
    Array operator/(int) const;
    Array operator%(int) const;
    bool operator==(const Array&) const;
    bool operator>(const Array&) const;
    bool operator<(const Array&) const;
    Array operator=(const Array&);
    int &operator[](int); //subscripting
    const int &operator[](int) const;

    //operazioni
    T tot() const;
    T media() const;
    T mediana() const;
    Array moda() const;
    T max() const;
    T min() const;
    void ordinamentoCrescente();
    void ordinamentoDecrescente();
    Array unione(const Array&) const;
    Array intersezione(const Array&) const;
};

template<class T>
Array<T>::Array(unsigned int s, unsigned int c){
    size = s;
    capacity = c;
    vector = new T[capacity];
}//costruttore

template<class T>
Array<T>::Array(const Array& copia){
    capacity = copia.capacity;
    size = copia.size;
    vector = new T[capacity];
    for(unsigned int i = 0; i < size; i++)
      vector[i] = copia.vector[i];
}

template<class T>
Array<T>::~Array(){
    delete[] vector;
}//~Array

template<class T>
void Array<T>::setElement(int pos, T obj){
    vector[pos] = obj;
}

//overload
template<class T>
Array<T> Array<T>::operator+(const Array& x) const{
    unsigned int max_size;
    unsigned int max_capacity;

    if(size >= x.size){
        max_capacity = capacity;
        max_size = size;
    }
    else{
        max_capacity = capacity;
        max_size = x.size;
    }

    Array<T> a(max_size, max_capacity);

    for(unsigned int i = 0; i < a.size ; i++){
        if(i < size && i < x.size)
            a.vector[i] = *(vector[i] + x.vector[i]);
        if(i < size && i >= x.size)
            a.vector[i] = vector[i];
        if(i >= size && i < x.size)
            a.vector[i] = x.vector[i];
    }//for

    return a;
}//operator+

template<class T>
Array<T> Array<T>::operator-(const Array& x) const{
    unsigned int max_size;
    unsigned int max_capacity;

    if(size >= x.size){
        max_capacity = capacity;
        max_size = size;
    }
    else{
        max_capacity = capacity;
        max_size = x.size;
    }

    Array<T> a(max_size, max_capacity);
    T zero = T();

    for(unsigned int i = 0; i < a.size ; i++){
        if(i < size && i < x.size)
            a.vector[i] = *(vector[i] - x.vector[i]);
        if(i < size && i >= x.size)
            a.vector[i] = *(zero - vector[i]);
        if(i >= size && i < x.size)
            a.vector[i] = *(zero - x.vector[i]);
    }//for
    return a;
}//operator-

template<class T>
Array<T> Array<T>::operator*(int x) const{
    Array<T> a(size, capacity);
    for(unsigned int i = 0; i < a.size ; i++){
        a.vector[i] = *(vector[i] * x);
    }//for
    return a;
}//operator*

template<class T>
Array<T> Array<T>::operator/(int x) const{
    Array<T> a(size, capacity);
    if(x == 0){
        std::cout << "Divisione per 0!!!";
        return a;
    }//if

    for(unsigned int i = 0; i < a.size ; i++){
        a.vector[i] = *(vector[i] / x);
    }//for
    return a;
}//operator/

template<class T>
Array<T> Array<T>::operator%(int x) const{
    Array<T> a(size, capacity);
    if(x == 0){
        std::cout << "Divisione per 0!!!";
        return a;
    }//if

    for(unsigned int i = 0; i < a.size ; i++){
        a.vector[i] = *(vector[i] % x);
    }//for
    return a;
}//operator%

template<class T>
bool Array<T>::operator==(const Array& x) const{
    if(size != x.size)
       return false;

    bool flag = true;
    for(unsigned int i = 0;(i < size) && (flag); i++){
        if(!(vector[i] == x.vector[i]))
            flag = false;
    }//for
    return flag;
}//operator==

template<class T>
bool Array<T>::operator>(const Array& x) const{
    return tot() > x.tot();
}//operator>

template<class T>
bool Array<T>::operator<(const Array& x) const{
    return tot() < x.tot();
}//operator>

template<class T>
Array<T> Array<T>::operator= (const Array& copia){

    if (size != copia.size){
        delete [] vector;
        size = copia.size;
        capacity = copia.capacity;
        vector = new T[capacity];
     }//if

    for (unsigned int i = 0; i < size; i++)
        vector[i] = copia.vector[i];

    return *this;

}//operator=

template<class T>
int &Array<T>::operator[] (int subscript){
  if (subscript < 0 || subscript >= size){
    exit(1);
  }//if
  return vector[subscript];
}//operator[]

template<class T>
const int &Array<T>::operator[] (int subscript) const {
    if (subscript < 0 || subscript >= size){
      exit(10);
    }//if
    return vector[subscript];
}//operator[] const

template<class T>
void Array<T>::printArray() const{
  for ( int i = 0; i < size; i++)
      std::cout <<vector[i]<<" ";
}//printArray

template<class T>
bool Array<T>::isEmpty() const{

  return (size) ? true : false;

}//isEmpty

template<class T>
T Array<T>::tot() const{
    T sum = T();
    for(unsigned int i = 0; i < size; i++)
        sum = *(sum + vector[i]);
    return sum;
}//tot

template<class T>
T Array<T>::media() const{
    return *(tot() / size);
}//media

template<class T>
T Array<T>::mediana() const{
    return vector[size/2];
}//mediana

template<class T>
Array<T> Array<T>::moda() const{
    int temp[size];
    Array<T> a(0,capacity);
    int cont;
    for(unsigned int i = 0; i < size; i++){
        cont = 0;
        for(unsigned int j = 0; j < size; j++){
            if(vector[i] == vector[j])
                cont++;
        }//for
       temp[i] = cont; // per ogni valore salvo su temp[] il numero di ripetizioni
    }//for

    int massimo = temp[0];
    for(unsigned int i = 0; i < size; i++){  // trovo il numero che si ripete più volte
         if(temp[i] > massimo)
         massimo = temp[i];
    }//for

    bool doppio;
    for(unsigned int k = 0; k < size; k++){ // visualizza gli elementi che si ripetono più volte senza considerare doppioni
        if(temp[k] == massimo){
            doppio = false;
            for(int a = k-1; a >= 0 && doppio == false; a--){
              if(vector[k] == vector[a])
                  doppio = true;
            }//for
            if(doppio == false)
       // cout <<vector[k] << " ";
          a.push_back(vector[k]);

      }//if
    }//for

    return a;

}//moda

template<class T>
T Array<T>::max() const{
    T massimo = vector[0];
    for(unsigned int i = 0; i < size; i++){
        if(vector[i] > massimo)
            massimo = vector[i];
    }
    return massimo;
}

template<class T>
T Array<T>::min() const{
    T minimo = vector[0];
    for(unsigned int i = 0; i < size; i++){
        if(vector[i] < minimo)
            minimo = vector[i];
    }
    return minimo;
}

template<class T>
void Array<T>::ordinamentoCrescente(){
    int fine;
       for (fine = size - 1; fine > 0; fine-- ){
             for (int i=0; i<fine; i++)
               if (vector[i]>vector[i+1]){
                 T tmp = vector[i];
                 vector[i] = vector[i+1];
                 vector[i+1] = tmp;
               }
         }
}

template<class T>
void Array<T>::ordinamentoDecrescente(){
    int fine;
       for (fine = size - 1; fine > 0; fine-- ){
             for (int i=0; i<fine; i++)
               if (vector[i]<vector[i+1]){
                 T tmp = vector[i];
                 vector[i] = vector[i+1];
                 vector[i+1] = tmp;
               }
         }
}

template<class T>
Array<T> Array<T>::unione(const Array& x) const{
    Array<T> a(size + x.size, capacity + x.capacity);
    int cont = 0;
    for(unsigned int i = 0; i < size; i++){
        a.vector[cont] = vector[i];
        cont++;
    }//for

    for(unsigned int j = 0; j < x.size; j++){
        a.vector[cont] = x.vector[j];
        cont++;
    }//for
    return a;
}//unione

template<class T>
Array<T> Array<T>::intersezione(const Array& x) const{
    int cont = 0;
    Array<T> a(size, capacity);
    bool flag;
    for(unsigned int i = 0; i < size; i++){
        flag = true;
        for(unsigned int j = 0; j < (x.size) && (flag); j++){
            if(vector[i] == x.vector[j]){
                a.vector[cont] = vector[i];
                cont++;
                flag = false;
            }
         }//for
     }//for
    a.size = cont;
    return a;
}//intersezione

template<class T>
void Array<T>::push_back(T x){
    if(size + 1 <= capacity){
        vector[size] = x;
        size++;
     }
}//push_back

template<class T>
T Array<T>::pop_back(){
    T temp;
    if(size){
        temp = vector[size-1];
        size--;
    }
    return temp;
}//pop_back

template<class T>
int Array<T>::getSize() const{
    return size;
}//getSize

template<class T>
int Array<T>::getCapacity() const{
    return capacity;
}//getCapacity

template<class T>
T Array<T>::getObj(int i) const{
    if(i > size)
        return vector[size];
    else
        return vector[i];
}//getObj

#endif // ARRAY_H
