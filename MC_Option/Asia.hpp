//
//  Asia.hpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef Asia_hpp
#define Asia_hpp
#include <iostream>
#include "Matrix.hpp"
#include "StockModel.hpp"
#include "OptionModel.hpp"
#include <stdio.h>

class Asia:public OptionModel{
    
    StockModel *s;
    double K ;
    double N ;
    double M ;
    
public:
    
    Asia(StockModel *s_);
    double payoff(OptionType type);
    ~Asia(){};
    
    void setK( double K_);
    void setN( double N_);
    void setM( double M_);
    
};


#endif /* Asia_hpp */
