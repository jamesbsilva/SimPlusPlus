// File and Version Information:  Accumulator.cpp
// $Header$
//
// Description:
//
//
// Author(s):
// James B. Silva <jbsilva@bu.edu>
#include "Accumulator.h"

template<class T>
Accumulator<T>::Accumulator(int maxMean){
    maxMoment = maxMean;
    defaultMax = DEFAULTMAXACCUM;
    accumulated = new T[maxMoment+2];
    resetAccumulator();
}
template<class T>
Accumulator<T>::Accumulator(){
    maxMoment = 6;
    defaultMax = DEFAULTMAXACCUM;
    accumulated = new T[maxMoment+2];
    resetAccumulator();
}

template<class T>
Accumulator<T>::~Accumulator(){
    delete accumulated;
    accumulated =0;
}

template<class T>
T Accumulator<T>::getMoment(int n){
    return (accumulated[n+2]/accumulatedN);
}

template<class T>
T Accumulator<T>::getMax(){
    return accumulated[0];
}

template<class T>
T Accumulator<T>::getMin(){
    return accumulated[1];
}

template<class T>
T Accumulator<T>::getCumulant(int n){
    return (accumulated[n+2]/accumulatedN);
}

template<class T>
void Accumulator<T>::updateAccumulator(T newVal){
    accumulatedN++;
    T temp;
    accumulated[0] = (accumulated[0] > newVal) ? accumulated[0]: newVal;
    accumulated[1] = (accumulated[1] < newVal) ? accumulated[1]: newVal;
    for(int i = 2; i < (maxMoment+2);i++){
        temp = newVal;
        for(int j=0;j<(i-2);j++){
            temp *= newVal;
        }
        accumulated[i] += temp;
    }
}

template<class T>
void Accumulator<T>::resetAccumulator(){
    accumulatedN = 0;
    accumulated[0] = 0;
    accumulated[1] = defaultMax;
    for(int i = 2; i < (maxMoment+2);i++){
        accumulated[i]=0;
    }
}



