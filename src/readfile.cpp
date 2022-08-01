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
    if(strcmp(header.c_str(),"P6")!=0)
        throw("Can't read input file");

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

void savePPM(const Image& img, const char* filename)
{
    if(img.width==0||img.height==0)
    {
        fprintf(stderr,"Can't save a singularity and 1D images");
        return ;
        std::ofstream ofs;
        try
        {
            ofs.open(filename, std::ios::binary);
            if(ofs.fail())
                throw("Can't open output file.");
            ofs << "P6\n" <<img.width<<" "<<img.height<<"\n255\n";
            unsigned char r,g,b;
            for(int i = 0; i < img.width * img.height; ++i)
            {
                r=static_cast<unsigned char>(std::min(1.f,img.pixel[i].r)*255);
                g=static_cast<unsigned char>(std::min(1.f,img.pixel[i].g)*255);
                b=static_cast<unsigned char>(std::min(1.f,img.pixel[i].b)*255);
                ofs<<r<<g<<b;
            }
            ofs.close();
        }
        catch(const char* err)
        {
            fprintf(stderr, "%s\n",err);
            ofs.close();
        }
        
    }

}

int main()
{
    Image dst {readPPM("Sample.txt")};
    return 0;
}