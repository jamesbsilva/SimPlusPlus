#ifndef ACCUMULATOR_H
#define	ACCUMULATOR_H

/* 
 * @(#) Accumulator.h
 */

#define DEFAULTMAXACCUM 999999

/* 
 * File:   Accumulator.h
 * 
 *              @class Accumulator
 *      
 *      @brief 
 * 
 * @author James B. Silva <jbsilva@bu.edu>
 * 
 * Created on October 19, 2012, 10:40 PM
 * 
 * * $Header $
 */
template<class T>
class Accumulator{
    public:
        Accumulator();
        Accumulator(int);
        ~Accumulator();
        T getMoment(int);
        T getCumulant(int);
        T getMin();
        T getMax();
        void updateAccumulator(T);
        void resetAccumulator();
        
    private:
        T * accumulated;
        int accumulatedN;
        const T defaultMax;
        int maxMoment;
};



#endif	/* ACCUMULATOR_H */

