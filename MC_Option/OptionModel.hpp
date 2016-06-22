
//  OptionModel.hpp
//  Heston
//
//  Created by Jade on 01/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef OptionModel_hpp
#define OptionModel_hpp

#include <stdio.h>
#include <iostream>
#include "Matrix.hpp"
#include "StockModel.hpp"

enum OptionType{ Call, Put };

class OptionModel{

public:
   
    OptionModel(){};
    virtual double payoff(OptionType type)=0;
    ~OptionModel(){};
};




#endif /* OptionModel_hpp */
