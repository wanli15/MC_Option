//
//  main.cpp
//  Heston
//
//  Created by Jade on 01/23/16.
//  Copyright © 2016 Wanli. All rights reserved.
//
#include "Matrix.hpp"
#include <iostream>
#include "StockModel.hpp"
#include "GBM.hpp"
#include "Heston.hpp"
#include "Asia.hpp"
#include "Barrier.hpp"
#include "European.hpp"
#include "OptionModel.hpp"
#include <vector>
#include <iostream>


int main() {
   
    GBM stk;
    Heston stk_h;
    
    StockModel *s = &stk;
    StockModel *s2 = &stk_h;

    European eur_gbm(s);
    European eur_hs(s2);
    
    Asia a_gbm(s);
    Asia a_hs(s2);
   
    Barrier b_gbm(s);
    Barrier b_hs(s2);

    //select the one type option you're interested and price it
    OptionModel *op = &eur_hs;
    double payoff = op->payoff(Put);
    
    cout<<"the MC option payoff is "<<payoff<<endl;
    cout<<" Done "<<endl;
    return 0;
}
