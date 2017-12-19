#include "StdAfx.h"
#include "VisualObject.h"


#include "SYS/DEV/DEV.h"


VisualObject::VisualObject(void)
{
}
VisualObject::VisualObject(double x, double y, double z, ColorRGBA * color, double value, bool visible)
{
	this->posX = x;
	this->posY = y;
	this->posZ = z;
	this->Value = value;
	this->ColorP = new ColorRGBA(*color);
	this->Visibility = visible;
	if(visible == true) {
		this->Opacity = this->ColorP->getColA();
	} else {
		this->Opacity = 0;
	}

	//g_LogSys << "DPUCooperativeInterface: VisibleObject Created" << endl;
}
VisualObject::~VisualObject(void)
{
	//g_LogSys << "DPUCooperativeInterface: VisibleObject Deleted" << endl;
}

void VisualObject::setVisualObject(double x, double y, double z, ColorRGBA * color, double value, bool visible)
{
	this->posX = x;
	this->posY = y;
	this->posZ = z;
	this->Value = value;
	this->ColorP = new ColorRGBA(*color);
	this->Visibility = visible;
	if(visible == true) {
		this->Opacity = this->ColorP->getColA();
	} else {
		this->Opacity = 0;
	}
}

void VisualObject::setPosX(double x)
{
	this->posX = x;
}

void VisualObject::setPosY(double y)
{
	this->posY = y;
}

void VisualObject::setPosZ(double z)
{
	this->posZ = z;
}

void VisualObject::setValue(double value)
{
	this->Value = value;
}

void VisualObject::setColor(ColorRGBA * color)
{
	this->ColorP = new ColorRGBA(*color);
}

void VisualObject::setVisibility(bool visible, double speed)
{
	if(visible == true) {
		this->fadeIn(speed);
	} else {
		this->fadeOut(speed);
	}
}

void VisualObject::fadeIn(double speed)
{
	this->Visibility = true;
	if(this->Opacity < this->ColorP->getColA()) {
		this->Opacity = this->Opacity + speed*0.05;
	}

	if(this->Opacity > this->ColorP->getColA()) {
		this->Opacity = this->ColorP->getColA();
	}
}

void VisualObject::fadeOut(double speed)
{
	if(this->Opacity >= 0) {
		this->Opacity = this->Opacity - speed*0.05;
	}

	if(this->Opacity < 0) {
		this->Opacity = 0;
		this->Visibility = false;
	}
}



double VisualObject::getPosX( void )
{
    return this->posX;
}

double VisualObject::getPosY( void )
{
    return this->posY;
}

double VisualObject::getPosZ( void )
{
    return this->posZ;
}

double VisualObject::getValue( void )
{
    return this->Value;
}

bool VisualObject::getVisibility( void )
{
    return this->Visibility;
}

double VisualObject::getOpacity( void )
{
    return this->Opacity;
}

ColorRGBA * VisualObject::getColorObject( void )
{
	return this->ColorP;
}
