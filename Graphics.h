#pragma once
#include "PPM.h"
#include "Pixel.h"
using namespace std;
class Graphics
{
    public:
    const PPM& ApplyFilter(PPM&, const char*);
    const PPM& MakeGrayScale(PPM&);
    const PPM& RotateImage(PPM&, double);
    const PPM& ScaleImage(PPM&, double);
    const PPM& TranslateImage(PPM&, int, int);
};