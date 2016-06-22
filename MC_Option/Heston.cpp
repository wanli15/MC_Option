//
//  Heston.cpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>
#include "Heston.hpp"

Heston::Heston(){
    
    kappa = 2;
    theta = 0.01;
    rho = 0.1;
    vv = 0.225;
    S = 100;
    v = 0.01;
    T = 1;
    r = 0.05;
    N = 400;
    M = 10000;
}


Matrix Heston::vol_rand(){
    
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

Matrix Heston::stock_rand( Matrix random1, Matrix random2, double correl ){
    
    Matrix r(M, N);
    for( int i = 0; i < M; ++i){
        
        vector<double> ran(N, 0.0);
        for( int j = 0; j <N; ++j){
            
            ran[j] = correl * random1.getVal(i, j) + sqrt(1 - correl*correl) * random2.getVal(i, j);
        }
        r.pushRow(ran, i);
    }
    
    return r;
}



Matrix Heston::simulation(){
    
    double dt = T/N;
    Matrix r1 = vol_rand();
    Matrix r2 = vol_rand();
    Matrix st_r = stock_rand(r1, r2, rho);
    Matrix HSs(M, N);
    
    
    for( int i = 0; i< M; ++i){
        
        vector<double> tempv(N, 0);
        tempv[0] = v + kappa*(theta - v)* dt + vv*sqrt(v * dt)* r1.getVal(i, 0);
        tempv[0] = fmax(tempv[0], 0);
        
        vector<double> temps(N, 0);
        temps[0] = S * exp((r - 0.5 * tempv[0])*dt + sqrt(dt * tempv[0])*st_r.getVal(i, 0));
        
        for( int j = 1; j< N; ++j){
            
            tempv[j] = tempv[j-1] + kappa*(theta - tempv[j-1])* dt + vv*sqrt(tempv[j-1] * dt)* r1.getVal(i, j);
            tempv[j] = fmax(tempv[j], 0);
            temps[j] = temps[j-1]* exp((r - 0.5 *  tempv[j])*dt + sqrt(dt * tempv[j])*st_r.getVal(i, j));
            
        }
        
        HSs.pushRow(temps, i);
    }
    
    return HSs;
    
}


void Heston::setStock(double S_){
    
    S = S_;
}
void Heston::setr(double r_){
    
    r = r_;
}
void Heston::setv(double v_){
    
    v = v_;
}
void Heston::setrho(double rho_){
    
    rho = rho_;
}
void Heston::settheta(double theta_){
    
    theta = theta_;
}
void Heston::setkappa(double kappa_){
    
    kappa = kappa_;
}
void Heston::setvv(double vv_){
    
    vv = vv_;
}
void Heston::setT(double T_){
    
    T = T_;
}
void Heston::setN(double N_){
    
    N = N_;
}
void Heston::setM(double M_){
    
    M = M_;
}
