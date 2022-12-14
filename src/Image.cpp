#include<iostream>

class Image
{
	public:
	struct Pixel
	{
	public:
		float r;
		float g;
		float b;
	public:
		Pixel():r(0),g(0),b(0) {}
		Pixel(float color): r(color),g(color),b(color){}
		Pixel(float red, float green, float blue):r(red),g(green),b(blue){}
		Pixel& operator = (const Pixel& pixel)
		{
			return *this;
		}
	};
public:
	unsigned int width;
	unsigned int height;
	Pixel* pixel;
public: 
	Image():width(0),height(0)
	{
		pixel = nullptr;
	}
	Image(const unsigned int& width, const unsigned int& height): width(width),height(height)
	{
		pixel = new Pixel(width*height);
		for(int i=0; i<width*height;i++)
		{
			pixel[i] = Image::Black;
		}
	}
	Image(const unsigned int& width, const unsigned int& height, const Pixel& color):
	width(width),height(height)
	{
		pixel = new Pixel(width*height);
		for(int i=0; i<width*height;i++)
		{
			pixel[i] = color;
		}
	}
	~Image()
	{
		delete[] pixel;
	}
	static const Pixel Black, White, Red, Green, Blue;
};

const Image::Pixel Image::Black = Image::Pixel(0);
const Image::Pixel Image::White = Image::Pixel(1);
const Image::Pixel Image::Red = Image::Pixel(1,0,0);
const Image::Pixel Image::Green = Image::Pixel(0,1,0);
const Image::Pixel Image::Blue = Image::Pixel(0,0,1);
	