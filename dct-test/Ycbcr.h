#ifndef __YCBCR_H__
#define __YCBCR_H__


struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
};

struct YCbCr
{
	float Y;
	float Cb;
	float Cr;
};

struct YCbCr RGBToYCbCr(struct RGB rgb);
void printYCbCr(struct YCbCr ycbcr);

#endif