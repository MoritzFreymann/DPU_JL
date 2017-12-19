#include "ColorRGBA.h"
#pragma once
class VisualObject
{
public:
	VisualObject(void);
	//VisualObject(double x, double y, double r, double g, double b, double a, double value, bool visible);
	VisualObject(double x, double y, double z, ColorRGBA * color, double value, bool visible);
	~VisualObject(void);
	
	double getPosX(void);
	double getPosY(void);
	double getPosZ(void);
	double getValue(void);
	bool getVisibility(void);
	double getOpacity(void);
	ColorRGBA * getColorObject(void);
	
	void setVisualObject(double x, double y, double z, ColorRGBA * color, double value, bool visible);
	void setPosX(double x);
	void setPosY(double y);
	void setPosZ(double z);
	void setValue(double value);
	void setColor(ColorRGBA * color);
	void setVisibility(bool visible, double speed);
	
	void fadeIn(double speed);
	void fadeOut(double speed);

	double posX;
	double posY;
	double posZ;
	double Value;
private:
	bool Visibility;
	double Opacity;
	ColorRGBA * ColorP;
};
