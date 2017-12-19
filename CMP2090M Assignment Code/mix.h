#pragma once
#ifndef mix_h
#define mix_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Image.h"
#include "RW.h"

class Mix
{

private:
	float fRed;
	float fGreen;
	float fBlue;
	Image MixImage;
	std::vector<Image*> ImgVec;
public:
	void SetImage(Image image)
	{
		MixImage = image;
	}

	Mix()
	{
		Reset();
	}

	void Reset()
	{
		fRed = 0;
		fGreen = 0;
		fBlue = 0;
	}
	void AddRed(float NewR)
	{
		fRed += NewR;
	}
	void AddGreen(float NewG)
	{
		fGreen = NewG;
	}
	void AddBlue(float NewB)
	{
		fBlue = NewB;
	}
	float GetRed()
	{
		return fRed;
	}
	float GetGreen()
	{
		return fGreen;
	}
	float GetBlue()
	{
		return fBlue;
	}

	void AddImage(Image &img)
	{
		ImgVec.push_back(&img);
	}

	Image Mean()
	{
		size_t ImageTotal = ImgVec.size();
		std::cout << "Total Images loaded: " << ImageTotal << std::endl;
		int CurImg = 0;
		int CurPix = 0;
		float fR;
		float fG;
		float fB;
		int PixelTotal = (MixImage.w) * (MixImage.h); // Total pixels in the image
		std::cout << "Total pixels per Image: " << PixelTotal << std::endl;
		for (CurPix = 0; CurPix < PixelTotal; CurPix++)
		{
			fR = 0;
			fG = 0;
			fB = 0;

			for (CurImg = 0; CurImg < ImageTotal; CurImg++)
			{
				fR += ImgVec[CurImg]->pixels[CurPix].r; 
				fG += ImgVec[CurImg]->pixels[CurPix].g;
				fB += ImgVec[CurImg]->pixels[CurPix].b;
			}
			
			MixImage.pixels[CurPix].r = (fR / ImageTotal);
			MixImage.pixels[CurPix].g = (fG) / ImageTotal;
			MixImage.pixels[CurPix].b = (fB / ImageTotal);
		}
		std::cout << "Images Mixed with Mean!" << std::endl;
		RW write;
		write.writePPM(MixImage, "Images/ImageStacker_set1/MEANY.ppm");
		return MixImage;
	}
	//Image Median(std::vector<Image*>)
	//Image Sigma(std::vector<Image*>)

};
#endif