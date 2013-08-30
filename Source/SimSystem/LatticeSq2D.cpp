// File and Version Information:  LatticeSq2D<T>.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>
#include "LatticeSq2D.h"

template<class T>
LatticeSq2D<T>::LatticeSq2D(int length){
    L = length;
    lattice = new T[L*L];
    size = L*L;
}
template<class T>
LatticeSq2D<T>::LatticeSq2D(int length, T initV){
    L = length;
    lattice = new T[L*L];
    size = L*L;
    for(int u = 0; u < L*L; u++){
        lattice[u] = initV;
    }
}

template<class T>
LatticeSq2D<T>::LatticeSq2D(){
    lattice = new T[L*L];
    size = L*L;
}

template<class T>
LatticeSq2D<T>::~LatticeSq2D<T>(){
    delete lattice;
    lattice = 0;
}

template<class T>
int LatticeSq2D<T>::getDimension() const{
    return dimension;
}

template<class T>
int LatticeSq2D<T>::getSize() const{
    return size;
}

template<class T>
int LatticeSq2D<T>::getIndexX(int u){
    return (int)(u%L);
}

template<class T>
int LatticeSq2D<T>::getIndexY(int u){
    return (int)((u/L)%L);
}

template<class T>
int LatticeSq2D<T>::getIndex(int i, int j){
    return (i+j*L);
}

template <class T>
T LatticeSq2D<T>::getSum() const{
    return sum;
}


template <class T>
T LatticeSq2D<T>::calcSum() const{
    T accum = 0;
    for(int i=0;i<L*L;i++){
        accum += lattice[i];
    }
    sum = accum;
    return accum;
}


template<class T>
void LatticeSq2D<T>::setValue(int i,int j, T newVal){
    T oldVal = lattice[i+j*L];
    lattice[i+j*L] = newVal;
    sum += (newVal-oldVal);
}

template<class T>
T LatticeSq2D<T>::getValue(int i,int j) const{
    return lattice[i+j*L];
}

template <class T>
T LatticeSq2D<T>::getValue(int i) const{
    return lattice[i];
}


template <class T>
T LatticeSq2D<T>::getSumSqRange(int i,int j, int range) const{
    T accum = 0;
    int x;int y;
    for(int u=0;u<(2*range+1);u++){for(int v=0;v<(2*range+1);v++){
        x= ((i-range+u+L)%L);
        y= ((j-range+v+L)%L);
        if(x==i && y==j){}else{accum += lattice[x+y*L];}
    }}
    return accum;
}


/*
 *  Simple test of latticesq2d
 */
int mainLat(int argc, char** argv) {
    LatticeSq2D<int>  lat(10,2);
    printf("Lattice Size: %d  \n",(int)lat.getSize());
    printf("Lattice Val 2: %d  \n",lat.getValue(2));
    lat.setValue(3,0,5);
    printf("Lattice Val 3: %d  \n",lat.getValue(3));
    printf("Lattice Val 4: %d  \n",lat.getSumSqRange(3,0,3));
    printf("Val : %d  \n",(2*7*7-2));
}