//
//  GBM.hpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//
#include "StockModel.hpp"
#ifndef GBM_hpp
#define GBM_hpp
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <stdio.h>



class GBM: public StockModel{
    
    double S;
    double r;
    double sigma;
    double T;
    double N;
    double M;
    
    
public:
    
    GBM();
    GBM(double Stock,double r,double sigma, double T, double N);
    Matrix random();
    Matrix simulation();
    
    void setStock(double S_);
    void setr(double r_);
    void setsigma(double sigma_);
    void setT(double T_);
    void setN(double N_);
    void setM(double M_);
    ~GBM(){};
    
};



#endif /* GBM_hpp */
