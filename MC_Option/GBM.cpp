//
//  GBM.cpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "GBM.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>



GBM::GBM(){
    
    S = 100;
    r = 0.05;
    sigma = 0.2;
    T = 1;
    N = 400;
    M = 10000;
}


Matrix GBM::random(){
    
    Matrix r(M, N);
    
    for( int i = 0; i< M; ++i){
        
        vector<double> temp(N);
        for(int j = 0; j< N; ++j){
            
            double e = rgen();
            temp[j] = e;
            
        }
        r.pushRow(temp, i);
    }
    
    return r;
}

Matrix GBM::simulation(){
    
    Matrix gbm_s(M, N);
    Matrix e = random();
    double dt = T/N;
    
    for( int i = 0; i< M; ++i){
        
        vector<double> temp(N);
        temp[0] = S * exp((r - 0.5* sigma * sigma)*dt + sigma * sqrt(dt)* e.getVal(i, 0));
        
        for( int j = 1; j< N; ++j){
            
            temp[j] = temp[j-1] * exp((r - 0.5* sigma * sigma)*dt + sigma * sqrt(dt)* e.getVal(i, j));
        }
        gbm_s.pushRow( temp, i);
    }
    
    return gbm_s;
}



void GBM::setStock(double S_){
    
    S = S_;
}
void GBM::setr(double r_){
    
    r = r_;
}
void GBM::setsigma(double sigma_){
    
    sigma = sigma_;
}
void GBM::setT(double T_){
    
    T = T_;
}
void GBM::setN(double N_){
    
    N = N_;
}

void GBM::setM(double M_){
    
    M = M_;
}



