#include<iostream>
#include<array>
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<easyx.h>
#include<graphics.h>
#include"classic.h"
using namespace std;


int Classic::gameEnd(Map map)//≈–∂œ“ªæ÷ «∑Ò÷’÷π,0Œ¥÷’÷π£¨1ªÒ §÷’÷π£¨2 ß∞‹÷’÷π
{
	int end = 0;

	if (map.achieveKey())
		end = 1;
	else
	{
		if (map.isMapFull())
		{
			array < Map, 4 >m= {map, map, map, map};
			array<bool, 4>c = { false,false,false,false };
			for (int i = 0; i < 4; ++i)
				c[i]=m[i].mapChange(i + 1);
			if (c[0]||c[1]||c[2]||c[3])
				end = 0;
			else
			{
				Sleep(2000);
				end = 2;
			}
		}
		else
			end = 0;
	}

	return end;
}

void Classic::setMapZeroElement(Map& map)
{
	array<int, 3> information = map.setMapZeroElementInformation();
	int x= information[0];
	int y = information[1];
	int value = information[2];	
	IMAGE image;
	if (x < 4) 
	{
		switch (value)
		{
		case 1:
		{
			loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\2.png"));
			putimage(x * 124, y * 124, &image);
		}
		break;
		case 2:
		{
			loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\4.png"));
			putimage(x * 124, y * 124, &image);
		}
		break;
		default:
			break;
		}
	}
}

void Classic::oneGame(int hardLevel)
{
	int flag;
	switch (hardLevel)
	{
	case 1:
		flag = 7;
		break;
	case 2:
		flag = 9;
		break;
	case 3:
		flag = 11;
		break;
	default:
		flag = 9;
		break;
	}

	Map map(flag);
	initgraph(495, 739);
	IMAGE img;
	loadimage(&img, _T("D:\\VS2019\\2048_7.06\\image\\back.png"));
	putimage(0, 0, &img);

	playerInGamePrint(map);
	IMAGE image;
	loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\fourDirections.png"));
	putimage(0, 496, &image);
	while (gameEnd(map) == 0)
	{
		int choose = 0;
		MOUSEMSG mouse;
		while (choose == 0)
		{
			if (MouseHit())
			{
				mouse = GetMouseMsg();
				if (mouse.uMsg == WM_LBUTTONDOWN)
				{
					if (mouse.y < 617 && mouse.y < 496 + mouse.x && mouse.y < 738 - mouse.x)
						choose = 3;
					if (mouse.y > 617 && mouse.y > 496 + mouse.x && mouse.y > 738 - mouse.x)
						choose = 4;
					if (mouse.x < 121 && mouse.y>496 + mouse.x && mouse.y < 738 - mouse.x)
						choose = 1;
					if (mouse.x > 121 && mouse.y < 496 + mouse.x && mouse.y > 738 - mouse.x)
						choose = 2;
				}
			}
		}
		bool change = map.mapChange(choose);
		if (change)
		{
			playerInGamePrint(map);
			Sleep(300);
			setMapZeroElement(map);
			playerInGamePrint(map);
		}
	}
	closegraph();
	int endType = gameEnd(map);
	playerEndGamePrint(endType);
}

void Classic::playerInGamePrint(Map& map)
{
	for (int x = 0; x < 4; ++x)
		for (int y = 0; y < 4; ++y)
		{
			IMAGE image;
			switch (map.getElement(x, y))
			{
			case 0:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 1:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\2.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 2:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\4.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 3:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\8.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 4:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\16.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 5:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\32.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 6:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\64.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 7:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\128.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 8:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\256.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 9:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\512.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 10:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\1024.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 11:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\2048.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			default:
				break;
			}
		}

}

void Classic::playerEndGamePrint(int endType)
{
	switch (endType)
	{
	case 1:
	{
		initgraph(720, 430);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\success.png"));
		putimage(0, 0, &image);
	}
	break;
	case 2:
	{
		initgraph(800, 700);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\fail.png"));
		putimage(0, 0, &image);
	}
	break;
	default:
		break;
	}
	Sleep(3000);
	closegraph();
}