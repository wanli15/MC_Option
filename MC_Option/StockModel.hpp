//  StockModel.hpp
//  Heston
//
//  Created by Jade on 01/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#ifndef StockModel_hpp
#define StockModel_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include "Matrix.hpp"



class StockModel{

public:
    double rgen();
    StockModel(){};
    virtual ~StockModel(){};
    virtual Matrix simulation()=0;
    
};



#endif /* StockModel_hpp */
