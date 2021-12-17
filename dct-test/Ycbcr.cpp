#include "Ycbcr.h"
#include <stdio.h>

struct YCbCr RGBToYCbCr(struct RGB rgb) {
	float fr = (float)rgb.R / 255;
	float fg = (float)rgb.G / 255;
	float fb = (float)rgb.B / 255;

	struct YCbCr ycbcr;
	ycbcr.Y = (float)(0.2989 * fr + 0.5866 * fg + 0.1145 * fb);
	ycbcr.Cb = (float)(-0.1687 * fr - 0.3313 * fg + 0.5000 * fb);
	ycbcr.Cr = (float)(0.5000 * fr - 0.4184 * fg - 0.0816 * fb);

	return ycbcr;
}


void printYCbCr(struct YCbCr ycbcr) {
	printf("-----------Printing YCbCr -----------\n");
	printf("Y: %f\t", ycbcr.Y);
	printf("Cb: %f\t", ycbcr.Cb);
	printf("Cr: %f\t", ycbcr.Cr);
	printf("\n-------------------------------------\n");
}