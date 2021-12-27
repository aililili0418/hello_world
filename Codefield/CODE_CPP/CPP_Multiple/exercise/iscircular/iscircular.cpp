#include <iostream>
using namespace std;
#include "circular.h"
#include "point.h"


void compare(Circular &c, Point &p)
{
    //计算2点之间的距离 平方
    int distance=
        (c.getCenter().getX()-p.getX())*(c.getCenter().getX()-p.getX())+
        (c.getCenter().getY()-p.getY())*(c.getCenter().getY()-p.getY());   

    //计算半径平方
    int rdistance=c.getR()*c.getR();

    //判断
    if(distance==rdistance)
    {
        cout<<"点在圆上"<< endl;
    }
    else if (distance>rdistance)
    {
        cout<<"点在圆外"<< endl;
    }
    else
    {
        cout<<"点在圆外"<< endl;
    }
    

}
int main()
{
    Circular c;
    Point center;
    center.setX(10);
    center.setY(0);
    c.setCenter(center);
    c.setR(10);

    Point p;
    p.setX(10);
    p.setY(11);

    compare(c,p);
    system("pause");
    
}