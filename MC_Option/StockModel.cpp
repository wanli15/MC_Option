//
//  StockModel.cpp
//  Heston
//
//  Created by Jade on 01/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//

#include "StockModel.hpp"
#include <vector>
#include <iostream>
#include "Matrix.hpp"
#include <cmath>

double StockModel::rgen(){
    
    double num1 = 0.0;
    double num2 = 0.0;
    double num =  0.0;
    
    do
    {
        num1 = 2.0 * (rand()/static_cast<double>(RAND_MAX)) - 1;
        num2 = 2.0 * (rand()/static_cast<double>(RAND_MAX)) - 1;
        num = num1*num1 + num2*num2;
    }while(num > 1.0);
    
    return num1*sqrt((-2*log(num))/num);
}


