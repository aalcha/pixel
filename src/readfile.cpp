#include <string.h>
#include <fstream>

#include "image.cpp"
//PPM image format
Image readPPM(const char* filename)
{
    std::ifstream ifs;
    ifs.open(filename, std::ios::binary);

    Image src;
    try{
        if(ifs.fail())
        {
            throw("Can't open file");
        }
    std::string header;
    int w,h,b;
    /*if(strcmp(header.c_str(),"P6")!=0)
        throw("Can't read input file");
*/
    ifs>>w>>h>>b;
    src.width = w;
    src.height = h;
    src.pixel = new Pixel[w*h];
    ifs.ignore(256, '\n');
    unsigned char pix[3];
    for(int i=0; i<w*h; i++)
    {
        ifs.read(reinterpret_cast<char*>(pix),3);
        src.pixel[i].r = pix[0]/255.f;
        src.pixel[i].g = pix[0]/255.f;
        src.pixel[i].b = pix[0]/255.f;
    }

    }
    catch(const char* err)
    {
        fprintf(stderr,"%s\n",err);
    }
    return src;
}

int main()
{
    Image dst {readPPM("Sample.txt")};
    return 0;
}