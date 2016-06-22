//
//  Barrier.hpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef Barrier_hpp
#define Barrier_hpp
#include <iostream>
#include "Matrix.hpp"
#include "StockModel.hpp"
#include "OptionModel.hpp"
#include <stdio.h>



class Barrier:public OptionModel{
    
    StockModel *s;
    double DO;
    double UO;
    double N;
    double M;
    double K;
    
public:
    
    Barrier(StockModel *s_);
    double payoff(OptionType type);
    
    void setDO(double DO_);
    void setUO(double UO_);
    void setN(double N_);
    void setM(double M_);
    void setK(double K_);
    
    ~Barrier(){};
    
};

#endif /* Barrier_hpp */
