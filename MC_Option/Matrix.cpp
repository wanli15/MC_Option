//
//  Matrix.cpp
//  jade
//
//  Created by Jade on 1/23/16.
//  Copyright © 2016 Jade. All rights reserved.
//

#include "Matrix.hpp"



Matrix::Matrix(int size)
{
    for (unsigned i=0; i<size; ++i)
    {
        vector<double> row(size,0);
        m_rows.push_back(row);
    }
}

Matrix::Matrix(int size, int size2)
{
    for(unsigned i=0;i<size;++i)
    {
        vector<double> row(size2,0);
        m_rows.push_back(row);
    }
}

Matrix::Matrix(const Matrix &s):m_rows(s.m_rows){
}

void Matrix::pushRow(Row r, int n){
    if ( n > m_rows.size()-1) {
        cout<<"Can't insert more Row!"<<endl;
        return;
    }
    m_rows[n] = r;
}

double Matrix::getVal(int x, int y){
    try {
        return m_rows[x][y];
    } catch (exception) {
        cout<<"No correct data @ ["<<x<<","<<y<<"]"<<endl;
    }
    return 911.0;
}

void Matrix::print(){
    for(int ii=0;ii<m_rows.size();ii++){
        for(int jj=0 ;jj<=m_rows[0].size();jj++)
            printf("%f  ",m_rows[ii][jj]);
        std::cout<<endl;
    }
}

Matrix::~Matrix()
{
    
}


Matrix &Matrix::operator=(const Matrix &s)
{
    if(this != &s)
    {
        m_rows=s.m_rows;
    }
    
    return *this;
}

Matrix::Row & Matrix::operator[](int pos)
{
    return m_rows[pos];
}

void Matrix::transpose()
{
    vector<Row> rows;
    for(unsigned i=0; i<m_rows[0].size();++i)
    {
        vector<double> row(m_rows.size());
        for(unsigned j=0;j<m_rows.size();++j)
        {
            row[j]=m_rows[j][i];
        }
        rows.push_back(row);
    }
    m_rows.swap(rows);
}

double Matrix::trace()
{
    if(m_rows.size()!=m_rows[0].size())
    {
        return 0;
    }
    double total=0;
    for (unsigned i=0;i<m_rows.size();++i)
    {
        total +=m_rows[i][i];
    }
    return total;
}

void Matrix::add(const Matrix &s)
{
    if(m_rows.size()!=s.m_rows.size()||m_rows[0].size()!=s.m_rows[0].size())
    {
        throw new runtime_error(" invalid matrix dimensions ");
    }
    for(unsigned i=0; i<m_rows.size(); ++i)
    {
        for(unsigned j=0; j<m_rows[0].size(); ++j)
        {
            m_rows[i][j] +=s.m_rows[i][j];
        }
    }
}

void Matrix::substract(const Matrix &s)
{
    if (m_rows.size()!=s.m_rows.size()||m_rows[0].size()!=s.m_rows[0].size())
    {
        throw new runtime_error(" invalid matrix dimensions " );
    }
    for (unsigned i=0;i<m_rows.size();++i)
    {
        for (unsigned j=0; j<m_rows[0].size();++j)
        {
            m_rows[i][j] +=s.m_rows[i][j];
        }
    }
}

void Matrix::multiply(const Matrix &s)
{
    if(m_rows[0].size()!=s.m_rows.size())
    {
        throw new runtime_error(" invalid matrix dimension " );
    }
    vector<Row> rows;
    for (unsigned i=0;i<m_rows.size(); ++i)
    {
        vector<double> row;
        
        for (unsigned j=0; j<s.m_rows.size();++j)
        {
            double Mij=0;
            
            for(unsigned k=0;k<m_rows[0].size();++k)
            {
                Mij +=m_rows[i][k] * s.m_rows[k][j];
            }
            
            row.push_back(Mij);
        }
        rows.push_back(row);
    }
    m_rows.swap(rows);
}

Matrix operator+(const Matrix &s1, const Matrix &s2)
{
    Matrix s(s1);
    s.add(s2);
    return s;
}

Matrix operator-(const Matrix &s1, const Matrix &s2)
{
    Matrix s(s1);
    s.substract(s2);
    return 2;
}

Matrix operator*(const Matrix &s1, const Matrix &s2)
{
    Matrix s(s1);
    s.multiply(s2);
    return s;
}