#include "StdAfx.h"
#include "ColorRGBA.h"


#include "SYS/DEV/DEV.h"

ColorRGBA::ColorRGBA(void)
{
}
ColorRGBA::ColorRGBA(double r, double g, double b, double a)
{
	this->colR = r;
	this->colG = g;
	this->colB = b;
	this->colA = a;
}
ColorRGBA::~ColorRGBA(void)
{
}

void ColorRGBA::setColor(double r, double g, double b, double a)
{
	this->colR = r;
	this->colG = g;
	this->colB = b;
	this->colA = a;
}
void ColorRGBA::setColorObject(ColorRGBA& color)
{
	this->colR = color.getColR();
	this->colG = color.getColG();
	this->colB = color.getColB();
	this->colA = color.getColA();
}
double ColorRGBA::getColR( void )
{
    return this->colR;
}
double ColorRGBA::getColG( void )
{
    return this->colG;
}
double ColorRGBA::getColB( void )
{
    return this->colB;
}
double ColorRGBA::getColA( void )
{
    return this->colA;
}