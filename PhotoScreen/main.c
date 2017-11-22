#include <stdio.h>
#include "acllib.h"

#define PIX_LEN 10
typedef struct operatingBasicPoint{
	int x;
	int y;
}oBp;
oBp *basicPoint = NULL;
struct point_Position{
	int num;
	int position_x;
	int position_y;
};
void pixel(ACL_Color color,int x,int y) ;
void pixel(ACL_Color color,int x,int y)
{
	setBrushColor(color);
	setPenColor(EMPTY);
	rectangle(x,y,x+PIX_LEN,y+PIX_LEN);
}
void moveBasicPoint(int pos_x,int pos_y);
void moveBasicPoint(int pos_x,int pos_y)
{
	basicPoint->x += PIX_LEN ;
	basicPoint->y += PIX_LEN ;
}
int Setup()
{
	struct point_Position data_Black_Pixel[]={2,13,1,3,20,1,2,14,2,3,19,2,
	7,10,3,10,18,3,
	23,8,4,
	26,6,5,
	28,5,6,
	30,4,7,
	32,3,8,
	28,5,9,
	29,4,10,
	31,3,11,
	33,2,12,
	29,4,13,
	12,3,14,2,16,14,12,19,14,
	6,4,15,1,11,15,1,13,15,1,17,15,1,19,15,2,21,15,10,24,15,
	6,4,16,1,14,16,1,20,16,9,25,16,
	6,3,17,6,10,17,6,19,17,6,26,17,1,33,17,
	1,4,18,2,7,18,1,13,18,1,21,18,2,26,18,2,30,18,
	1,4,19,2,7,19,4,11,19,4,20,19,2,26,19,2,30,19,
	1,4,20,1,8,20,1,26,20,1,30,20,
	1,5,21,1,8,21,1,26,21,1,29,21,
	3,6,22,3,26,22,
	1,8,23,1,15,23,1,26,23,
	1,8,24,1,26,24,
	1,9,25,1,25,25,
	3,8,26,1,14,26,1,24,26,
	1,7,27,3,10,27,2,22,27,2,25,27,
	1,7,28,1,10,28,3,12,28,2,12,28,2,20,28,1,27,28,
	1,7,29,1,10,29,1,12,29,7,14,29,1,22,29,1,28,29,
	1,7,30,1,10,30,1,14,30,1,20,30,1,23,30,1,26,30,1,29,30,
	1,7,31,2,10,31,1,14,31,1,19,31,1,23,31,1,25,31,1,29,31,
	4,7,32,1,12,32,1,15,32,1,18,32,2,21,32,1,25,32,1,29,32,
	1,7,33,1,9,33,2,13,33,2,16,33,1,20,33,1,25,33,1,29,33,
	1,7,34,1,9,34,1,15,34,2,18,34,1,25,34,1,29,34,
	2,6,35,1,9,35,1,11,35,1,14,35,4,26,35,
	1,5,36,2,8,36,1,11,36,1,14,36,1,16,36,1,25,36,1,28,36,
	1,5,37,1,8,37,1,10,37,1,14,37,1,21,37,1,25,37,1,28,37,
	1,4,38,2,6,38,2,9,38,1,15,38,1,20,38,1,25,38,1,28,38,
	1,4,39,1,10,39,1,15,39,2,18,39,1,25,39,1,28,39,
	1,4,40,15,10,40,1,28,40,
	1,5,41,16,9,41,1,27,41,
	22,6,42,
	18,10,43,18,10,44,18,10,45,
	18,10,46,
	7,10,47,10,19,47,
	9,8,48,11,19,48,10,7,49,12,19,49
	};
	struct point_Position data_Blue_Pixel[]={
		2,8,27,
		2,8,28,
		2,8,29,2,8,30,2,8,31,
	};
	struct point_Position data_Red_Pixel[]={
		1,9,37,
		1,5,38,1,8,38,
		5,5,39,
		5,5,40,
		3,6,41
	};
	struct point_Position data_Colour_Pixel[]={
		1,15,14,1,18,14,
		14,10,15,
		15,10,16,
		17,9,17,
		25,5,18,
		25,5,19,
		25,5,20,
		23,6,21,
		17,9,22,
		17,9,23,
		17,9,24,
		15,10,25,
		13,11,26,
		9,13,27,
		5,15,28,
		5,15,30,
		4,15,31,
		2,16,32,
		2,26,36,
		2,26,37,
		2,26,38,
		2,26,39,
		3,25,40,
		2,25,41
	};
	oBp startPoint={0,0};
	basicPoint = &startPoint;
	initWindow("cartoon_pixel",100,100,350,510);
	beginPaint();
	int i=0,j=0;
		for(i=0;i<sizeof(data_Colour_Pixel)/12;i++){
		basicPoint->x = data_Colour_Pixel[i].position_x * PIX_LEN;
		basicPoint->y = data_Colour_Pixel[i].position_y * PIX_LEN;
		for(j=0;j<data_Colour_Pixel[i].num ;j++)
		{   
			pixel(RGB(253,236,166), basicPoint->x , basicPoint->y );
				basicPoint->x += PIX_LEN ;
		}
	}
	for(i=0;i<sizeof(data_Black_Pixel)/12;i++){
		basicPoint->x = data_Black_Pixel[i].position_x * PIX_LEN;
		basicPoint->y = data_Black_Pixel[i].position_y * PIX_LEN;
		for(j=0;j<data_Black_Pixel[i].num ;j++)
		{   
			pixel(BLACK, basicPoint->x , basicPoint->y );
				basicPoint->x += PIX_LEN ;
		}
	}
		for(i=0;i<sizeof(data_Blue_Pixel)/12;i++){
		basicPoint->x = data_Blue_Pixel[i].position_x * PIX_LEN;
		basicPoint->y = data_Blue_Pixel[i].position_y * PIX_LEN;
		for(j=0;j<data_Blue_Pixel[i].num ;j++)
		{   
			pixel(RGB(77,78,231), basicPoint->x , basicPoint->y );
				basicPoint->x += PIX_LEN ;
		}
	}
		for(i=0;i<sizeof(data_Red_Pixel)/12;i++){
		basicPoint->x = data_Red_Pixel[i].position_x * PIX_LEN;
		basicPoint->y = data_Red_Pixel[i].position_y * PIX_LEN;
		for(j=0;j<data_Red_Pixel[i].num ;j++)
		{   
			pixel(RGB(244,29,26), basicPoint->x , basicPoint->y );
				basicPoint->x += PIX_LEN ;
		}
	}

	endPaint();
	return 0;
}
   
