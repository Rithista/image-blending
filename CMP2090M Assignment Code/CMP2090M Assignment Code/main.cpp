//main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Image.h"
#include "mix.h"
#include "RW.h"

void PrintStart();
void MixImages();
void WriteImage(Image, std::string);




int main()
{


	PrintStart();
	MixImages();
	std::cin.get();


	return 0;
}

void PrintStart()
{
	std::cout << "====================================" << std::endl;
	std::cout << "|  Harry Jones' C++ Image Blender  |" << std::endl;
	std::cout << "====================================" << std::endl;
}


void MixImages()
{
	Mix mix;
	RW read;
	Image imgs[12];
	for (int CurrentImage = 0; CurrentImage < 13; CurrentImage++)
	{
		std::string fileName;
		fileName = ("Images/ImageStacker_set1/IMG_") + std::to_string(CurrentImage + 1) + ".ppm";
		const char *FileChar = fileName.c_str();
		Image *img = &imgs[0];
		*img = read.readPPM(FileChar, fileName);
		mix.AddImage(*img);
		mix.SetImage(*img);
	}

	Image image = mix.Mean();
	//WriteImage(image, "meanPPM");
	//image = mix.Median();
	//WriteImage(image, "medianPPM");
	//image = mix.Sigma();
	//WriteImage(image, "sigmaPPM");
}

void WriteImage(Image image, std::string MixName)
{
	RW write;
	std::string OutputName;
	OutputName = ("Images/ImageStacker_set1/") + MixName + ".ppm";
	const char *OutputChar = OutputName.c_str();
	write.writePPM(image, OutputChar);
}
