#pragma once
#include "Pixel.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

Pixel::Pixel()
{
    red = 0;
    blue = 0;
    green = 0;
}

Pixel::Pixel(const Pixel & toCopy)
{
    this->red = toCopy["red"];
    this->green= toCopy["green"];
    this->blue= toCopy["blue"];
}

Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b)
{
    red = r;
    green = g;
    blue = b;
}

Pixel::~Pixel()
{
}

const unsigned int &Pixel::operator[](const char *index) const
{
    try
    {
        if (strcmp("red", index) == 0)
        {
            return this->red;
        }
        else if (strcmp("green", index) == 0)
        {
            return this->green;
        }
        else if (strcmp("blue", index) == 0)
        {
            return this->blue;
        }
        throw(InputOutOfBoundsException("Error, invalid index at : ", index));
    }

    catch (InputOutOfBoundsException &e)
    {
        cout << e.returnError() << e.returnOffendingIndex();
    }
}
unsigned int &Pixel::operator[](const char *index)
{

    try
    {
        if (strcmp("red", index) == 0)
        {
            return this->red;
        }
        else if (strcmp("green", index) == 0)
        {
            return this->green;
        }
        else if (strcmp("blue", index) == 0)
        {
            return this->blue;
        }
        throw(InputOutOfBoundsException("Error, invalid index at : ", index));
    }

    catch (InputOutOfBoundsException &e)
    {
        cout << e.returnError() << e.returnOffendingIndex();
    }
}
Pixel::InputOutOfBoundsException::InputOutOfBoundsException(const char * mes, const char * ind)
{
    this->errorMessage = mes;
    this->offendingIndex = ind;
}

const char *Pixel::InputOutOfBoundsException::returnError()
{
    return this->errorMessage;
}

const char *Pixel::InputOutOfBoundsException::returnOffendingIndex()
{
    return this->offendingIndex;
}
