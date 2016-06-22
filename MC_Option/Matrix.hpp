//
//  Matrix.hpp
//  jade
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Jade. All rights reserved.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>

#endif /* Matrix_hpp */



/*!
 *  @author WanLi, 16-01-23 20:01:00
 *
 *  @brief  
 *  @since 
 */
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;

class Matrix{
public:
    typedef vector<double> Row;
    Matrix(int size);
    Matrix(int size, int size2);
    Matrix(const Matrix &s);
    ~Matrix();
    Matrix &operator=(const Matrix &s);
    
    void pushRow(Row r, int n);
    double getVal(int x, int y);
    void print();
    
    void transpose();
    double trace();
    void add(const Matrix &s);
    void substract(const Matrix &s);
    void multiply(const Matrix &s);
    
    Row & operator[](int pos);
    
private:
    vector<Row> m_rows;
};

Matrix operator+(const Matrix &s1, const Matrix &s2);
Matrix operator-(const Matrix &s1, const Matrix &s2);
Matrix operator*(const Matrix &s1,const Matrix &s2);


