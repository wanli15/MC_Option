//
//  European.hpp
//  Heston
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef European_hpp
#define European_hpp
#include <iostream>
#include "Matrix.hpp"
#include "StockModel.hpp"
#include "OptionModel.hpp"
#include <stdio.h>


class European:public OptionModel{
    
    StockModel *s;
    double K ;
    double N ;
    double M ;
    
public:
    
    European(StockModel *s_);
    double payoff( OptionType type);
    
    void setK( double K_);
    void setN( double N_);
    void setM( double M_);
    ~European(){};
};


#endif /* European_hpp */
