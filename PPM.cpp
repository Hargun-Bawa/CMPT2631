#pragma once
#include "PPM.h"
#include "Pixel.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

PPM::PPM() : height{0}, width {0}, maxColor{255}, comment{ ""}, magic {""}
{
}

PPM::PPM(const PPM & toCopy)
{
    this->setMagic(toCopy.getMagic());
    this->setComment(toCopy.getComment());
    this->setHeight(toCopy.getHeight());
    this->setWidth(toCopy.getWidth());
    this->setMaxColor(toCopy.getMaxColor());
    this->resize();
    for(int i = 0; i< this->getSize(); i++)
    {
        pixels[i] = toCopy[i];
    }
}

PPM::PPM(ifstream & file)
{
    file >> magic;
    file >> comment;
    file >> height;
    file >> width;
    file >> maxColor;
    resize();
    for(int i = 0; i < height*width; i++)
    {
        int r, g, b;
        file >> r >> g >> b;
        pixels[i]["red"] = r;
        pixels[i]["green"] = g;
        pixels[i]["blue"] = b;
    }
}

const Pixel &PPM::operator[](unsigned int index) const
{
    return pixels[index];
}

Pixel &PPM::operator[](unsigned int index)
{
    return pixels[index];
}

const PPM &PPM::operator=(const PPM & toCopy)
{    
    this->setMagic(toCopy.getMagic());
    this->setComment(toCopy.getComment());
    this->setHeight(toCopy.getHeight());
    this->setWidth(toCopy.getWidth());
    this->setMagic(toCopy.getMagic());
    this->setMaxColor(toCopy.getMaxColor());
    this->resize();
    for(int i = 0; i< this->getSize(); i++)
    {
        pixels[i] = toCopy[i];
    }
    return *this;
}

PPM &PPM::operator=(PPM && toCopy)
{
    swap(height, toCopy.height);
    swap(width, toCopy.width);
    swap(magic, toCopy.magic);
    swap(maxColor, toCopy.maxColor);
    swap(pixels, toCopy.pixels);
    swap(comment, toCopy.comment);
    
    return *this;

}

string PPM::getComment() const
{
    return this->comment; 
}

string PPM::getMagic() const
{
    return this->magic;
}

unsigned int PPM::getSize() const
{
    return this->height * this->width;
}

unsigned int PPM::getWidth() const
{
    return this->width;
}

unsigned int PPM::getHeight() const
{
    return this->height;
}

unsigned int PPM::getMaxColor() const
{
    return this->maxColor;
}

void PPM::setComment(string s)
{
    this->comment = s;
}

void PPM::setHeight(unsigned int h)
{
    this->height = h;
}

void PPM::setWidth(unsigned int w)
{
    this-> width = w;
}

void PPM::setMagic(string m)
{
    this->magic = m;
}

void PPM::setMaxColor(unsigned int m)
{
    this->maxColor = m;
}

void PPM::resize()
{
    pixels.clear();
    pixels.reserve(height*width);
}

void PPM::SaveImageToFile(string filename)
{
    fstream file;
    file.open(filename);
    file << magic << "\n" << comment << "\n" << width <<" " << height << "\n" << maxColor << "\n";
    for( int i = 0; i < getSize(); i++)
    {
        file << pixels[i]["red"] << " " << pixels[i]["green"] << " " << pixels[i]["blue"] << " ";
    } 
}
