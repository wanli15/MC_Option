//
//  Heston.hpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef Heston_hpp
#define Heston_hpp
#include "StockModel.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <stdio.h>


class Heston:public StockModel{
    
    double kappa;
    double theta;
    double rho;
    double vv;
    double S;
    double v;
    double T;
    double r;
    double N;
    double M;
    
public:
    Heston();
    Matrix vol_rand();
    Matrix stock_rand(Matrix random1, Matrix random2, double roh );
    Matrix simulation();
    
    void setStock(double S_);
    void setr(double r_);
    void setv(double v_);
    void setrho(double rho_);
    void settheta(double theta_);
    void setkappa(double kappa_);
    void setvv(double vv_);
    void setT(double T_);
    void setN(double N_);
    void setM(double M_);
    ~Heston(){};
    
};

#endif /* Heston_hpp */
