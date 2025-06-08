#include <stdio.h>
#include <math.h>

void fulg(double x1, double y1, double x2, double y2, int depth)
{
	if(depth == 0)
	{
		printf("L %.2f %.2f", x2, y2);
	}
	else
	{
		double dx = (x2 - x1)/3.0;
		double dy = (y2 - y1)/3.0;
		double x3 = x1 + dx;
		double y3 = y1 + dy;
		double x5 = x1 + 2*dx;
		double y5 = y1 + 2*dy;
		double x4 = (x1 + x2)/2 + sqrt(3.0)*(y1 - y2)/6.0;
		double y4 = (y1 + y2)/2 + sqrt(3.0)*(x2 - x1)/6.0;
		fulg(x1, y1, x3, y3, depth-1);
		fulg(x3, y3, x4, y4, depth-1);
		fulg(x4, y4, x5, y5, depth-1);
		fulg(x5, y5, x2, y2, depth-1);
	}
}

int main(void)
{
	printf("<?xml version=\"1.0\"?>\n");
    printf("<svg version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\" width=\"800\" height=\"800\">\n");
    printf("<path fill=\"navy\" stroke=\"black\" stroke-width=\"1\" d=\"");
	double x1 = 100, y1 = 500, x2 = 500, y2 = 500, x3 = (x1 + x2)/2, y3 = y1 - sqrt(3.0)*(x2 - x1)/2; 
	int depth = 6;
	printf("M %.2f %.2f", x1, y1);
	fulg(x1, y1, x2, y2, depth);
	fulg(x2, y2, x3, y3, depth);
	fulg(x3, y3, x1, y1, depth);
	printf("Z"); 
	printf("\"/>\n</svg>\n");
	return 0;
}