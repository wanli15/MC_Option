//
//  Barrier.cpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "Barrier.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>

Barrier::Barrier(StockModel *s_):s(s_){
    
    DO = 80;
    UO = 150;
    K = 102;
    N = 400;
    M = 10000;
    
}

double Barrier::payoff(OptionType type){
    
    Matrix SP = s->simulation();
    vector<double> tempp(M);
    double sum = 0;
    
    switch (type)
    {
        case Call:
            
            for(int i = 0; i< M; ++i){
                
                double temp = 0.0;
                for( int j = 0; j<N; ++j){
                    
                    if( SP.getVal(i, j) > UO || SP.getVal(i, j) < DO){
                        
                        temp = 0.0;
                        break;
                        
                    } else {
                        
                        temp = SP.getVal(i, j);
                    }
                }
                
                tempp[i] = fmax(temp - K, 0);
                sum += tempp[i];
                
            }
            break;
        case Put:
            for(int i = 0; i< M; ++i){
                
                double temp = 0.0;
                for( int j = 0; j<N; ++j){
                    
                    if( SP.getVal(i, j) > UO || SP.getVal(i, j) < DO){
                        
                        temp = 0.0;
                        break;
                        
                    } else {
                        
                        temp = SP.getVal(i, j);
                    }
                }
                
                tempp[i] = fmax(K - temp, 0);
                sum += tempp[i];
                
            }
            break;
            
        default:
            
            cout<<" Wrong option type "<<endl;
            
    }
    
    return (sum/M);
    
}


void Barrier::setDO(double DO_){
    
    DO = DO_;
}

void Barrier::setUO(double UO_){
    
    UO = UO_;
}
void Barrier::setN(double N_){
    
    N = N_;
}
void Barrier::setM(double M_){
    
    M = M_;
}
void Barrier::setK(double K_){
    
    K = K_;
}

