#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

typedef struct {
	unsigned short type;
	unsigned int size;
	unsigned short reserved1;
	unsigned short reserved2;
	unsigned int offset;
} BMPHeader;

typedef struct {
	unsigned int size;
	int width;
	int height;
	unsigned short planes;
	unsigned short bitCount;
	unsigned int compression;
	unsigned int imageSize;
	int xPixelsPerM;
	int yPixelsPerM;
	unsigned int colorsUsed;
	unsigned int importantColors;
} InfoHeader;

typedef struct {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} RGB;

int main()
{
	FILE *f = NULL, *out = NULL;
	if((f=fopen("input.bmp","rb"))==NULL)
	{
		perror("Nu s-a putut deschide fisierul de intrare!");
		exit(-1);
	}

	if((out = fopen("output.bmp", "wb")) == NULL)
	{
		perror("Nu s-a putut deschide fisierul de iesire!");
		exit(-1);
	}

	BMPHeader bmp;
	fread(&bmp, sizeof(BMPHeader), 1, f);

	InfoHeader Info;
	fread(&Info, sizeof(InfoHeader), 1, f);

	fwrite(&bmp, sizeof(BMPHeader), 1, out);
	fwrite(&Info, sizeof(InfoHeader), 1, out);

	int extraBytes = bmp.offset - (sizeof(BMPHeader) + sizeof(InfoHeader));
	unsigned char buffer;
	for (int i = 0; i < extraBytes; i++) 
	{
    	fread(&buffer, 1, 1, f);
    	fwrite(&buffer, 1, 1, out);
	}

	int padding = (4 - (Info.width * 3) % 4) % 4;

	for(int i = 0; i < Info.height; i++)
	{
		for(int j = 0; j < Info.width; j++)
		{
			RGB pixel;
			fread(&pixel, sizeof(RGB), 1, f);

			unsigned char gray = (pixel.red + pixel.green + pixel.blue) / 3;

			RGB pixelgray = {gray, gray, gray};
			fwrite(&pixelgray, sizeof(RGB), 1, out);
		}

	fseek(f, padding, SEEK_CUR);
	for(int j = 0; j < padding; j++)
		fputc(0x00, out);
	}

	if(fclose(f) != 0)
	{
		perror("Nu s-a putut inchide fisierul de intrare!");
		exit(-1);
	}

	if(fclose(out) != 0)
	{
		perror("Nu s-a putut inchide fisierul de iesire!");
		exit(-1);
	}
	return 0;
}