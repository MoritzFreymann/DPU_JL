#pragma once
class ColorRGBA
{
public:
	ColorRGBA(void);
	ColorRGBA(double r, double g, double b, double a);
	~ColorRGBA(void);
	
	void setColor(double r, double g, double b, double a);
	void setColorObject(ColorRGBA& color);
	double getColR(void);
	double getColG(void);
	double getColB(void);
	double getColA(void);

private:
	double colR;
	double colG;
	double colB;
	double colA;
};