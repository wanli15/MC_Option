//
//  European.cpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "European.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>

European::European( StockModel *s_):s(s_){
    
    K = 102;
    N = 400;
    M = 10000;
    
}

double European::payoff(OptionType type){
    
    Matrix SP = s->simulation();
    
    vector<double> tempp(M);
    double sum = 0;
    
    switch(type)
    {
            
        case Call:
            
            for(int i = 0; i< M; ++i)
            {
                
                tempp[i] = fmax(SP.getVal(i, N-1)- K, 0);
                sum += tempp[i];
                
            }
            
            break;
            
        case Put:
            
            for(int i = 0; i< M; ++i)
            {
                
                tempp[i] = fmax(K - SP.getVal(i, N-1), 0);
                sum += tempp[i];
                
            }
            
            break;
            
        default:
            cout<<" Wrong option type "<<endl;
    }
    
    return (sum/ M);
    
    
}
