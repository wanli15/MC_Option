//
//  Asia.cpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "Asia.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>

Asia::Asia( StockModel *s_):s(s_){
    
    K = 102;
    N = 400;
    M = 10000;
    
}

double Asia::payoff( OptionType type){
    
    Matrix SP = s->simulation();
    vector<double> tempp(M);
    double sum2 = 0;
    
    switch(type)
    {
        case Call:
            
            for(int i = 0; i< M; ++i){
                
                double sum = 0;
                for( int j = 0; j<N; ++j){
                    sum += SP.getVal(i, j);
                }
                tempp[i] = sum/N;
                tempp[i] = fmax(tempp[i]-K, 0);
                sum2 += tempp[i];
                
            }
            
            break;
        case Put:
            
            for(int i = 0; i< M; ++i){
                
                double sum = 0;
                for( int j = 0; j<N; ++j){
                    sum += SP.getVal(i, j);
                }
                tempp[i] = sum/N;
                tempp[i] = fmax(K- tempp[i], 0);
                sum2 += tempp[i];
                
            }
            
            break;
        default:
            
            cout<<" Wrong option type "<<endl;
            
            
    }
    return (sum2/ M);
    
}

void Asia::setK( double K_){
    
    K = K_;
}
void Asia::setN( double N_){
    
    N = N_;
}
void Asia::setM( double M_){
    
    M = M_;
}
