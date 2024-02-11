
#pragma once
class Pixel
{
    public:
    Pixel();
    Pixel(const Pixel&);
    Pixel(unsigned int, unsigned int, unsigned int);
    ~Pixel();
    const unsigned int& operator[](const char*) const;
    unsigned int& operator[](const char*);
    private:
    unsigned int blue;
    unsigned int red;
    unsigned int green;
    class InputOutOfBoundsException
    {
        public:
        InputOutOfBoundsException(const char*, const char*);        
        const char* returnError();
        const char* returnOffendingIndex();
        private:
        const char* errorMessage ;
        const char* offendingIndex ;

    };
};