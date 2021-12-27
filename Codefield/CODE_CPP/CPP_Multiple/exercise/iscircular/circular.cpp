#include "circular.h"
#include "point.h"

//设置半径
void Circular::setR(int r)
{
    m_R=r;
}
//获取半径
int Circular::getR()
{
    return m_R;
}

void Circular::setCenter(Point center)
{
    m_Center=center;
}
Point Circular::getCenter()
{
    return m_Center;
}

