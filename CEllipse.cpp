#include "CEllipse.h"
CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	pointone = P1;
	pointtwo = P2;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::Draw Ellipse	
	pGUI->DrawEllipse(pointone, pointtwo, FigGfxInfo, Selected);
}

bool CEllipse::IsPointInside(int x, int y)
{
    // Calculate the normalized coordinates relative to the center
    double normalizedX = (x - (pointone.x + pointtwo.x) / 2.0) / ((pointtwo.x - pointone.x) / 2.0);
    double normalizedY = (y - (pointone.y + pointtwo.y) / 2.0) / ((pointtwo.y - pointone.y) / 2.0);

    // Check if the point satisfies the ellipse equation
    return (normalizedX * normalizedX + normalizedY * normalizedY) <= 1.0;
}

string CEllipse::GetInfo()
{
    return "First point: (" + to_string(pointone.x) + ", " + to_string(pointone.y) + ")" + 
        " - Second point: (" + to_string(pointtwo.x) + ", " + to_string(pointtwo.y) + ")" + 
        " - Area = " + to_string(CalcArea());
}

//omar
void CEllipse::resizeMe(int factor)
{
    // Calculate the center of the ellipse
    int centerX = (pointone.x + pointtwo.x) / 2;
    int centerY = (pointone.y + pointtwo.y) / 2;

    // Resize the distance from the center to the second point by the factor
    int newRadiusX = factor * (pointtwo.x - centerX) / 2;
    int newRadiusY = factor * (pointtwo.y - centerY) / 2;

    // Update the coordinates of the second point
    pointtwo.x = centerX + newRadiusX;
    pointtwo.y = centerY + newRadiusY;

    //check if it exceeds the drawing area
}


float CEllipse::CalcArea()
{
    // Calculate the radius of the ellipse
    int radiusX = abs(pointtwo.x - pointone.x) / 2;
    int radiusY = abs(pointtwo.y - pointone.y) / 2;

    // Calculate the area of the ellipse using the formula: pi * radiusX * radiusY
    float area = 3.14159f * radiusX * radiusY;

    return area;
}

//omar //does it excceds the drawing area

//omar return the details