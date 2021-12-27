#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circular
{
public:
    //设置半径
    void setR(int r);
    //获取半径
    int getR();
    void setCenter(Point center);//设置圆心
    Point getCenter();
private:
    int m_R;//半径
    Point m_Center;//圆心
};