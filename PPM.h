
#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Pixel.h"
#include <vector>

using namespace std;

class PPM
{
    public:
    //constructors and destructor
    PPM();
    PPM(const PPM&);
    PPM(ifstream&);
    PPM(PPM&);
    ~PPM();

    // operators
    const Pixel& operator[](unsigned int) const;
    Pixel& operator[](unsigned int) ;
     const PPM& operator=(const PPM&) ;
    PPM& operator=(PPM&&) ;

    //getters 
    string getComment() const;
    string getMagic() const;
    unsigned int getSize() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    unsigned int getMaxColor() const;

    //setters
    void setComment(string);
    void setHeight(unsigned int);
    void setWidth(unsigned int);
    void setMagic(string);
    void setMaxColor(unsigned int);
    void resize();

    void SaveImageToFile(string);

    private:
    string comment;
    string magic;
    unsigned int height;
    unsigned int width;
    unsigned int maxColor;
    vector<Pixel> pixels;
};