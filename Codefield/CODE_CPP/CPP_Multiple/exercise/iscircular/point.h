#pragma once
#include <iostream>
using namespace std;

class Point
{
public:
    void setX(int x);//设置x
    int getX();

    void setY(int y);//设置y
    int getY();

    


private:
    int m_X;
    int m_Y;
};