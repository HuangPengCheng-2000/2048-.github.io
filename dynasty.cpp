#include<iostream>
#include<array>
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<easyx.h>
#include<graphics.h>
#include"dynasty.h"
using namespace std;

int Dynasty::gameEnd(Map& map)//判断一局是否终止,0未终止，其余给出终止时的最大元素值
{
	int end = 0;

		if (map.isMapFull())
		{
			array < Map, 4 >m = { map, map, map, map };
			array<bool, 4>c = { false,false,false,false };
			for (int i = 0; i < 4; ++i)
				c[i] = m[i].mapChange(i + 1);
			if (c[0] || c[1] || c[2] || c[3])
				end = 0;
			else
			{
				Sleep(2000);
				end = map.getMaxElement();
			}
		}
		else
			end = 0;

	return end;
}

void Dynasty::setMapZeroElement(Map& map)
{
	array<int, 3> information = map.setMapZeroElementInformation();
	int x = information[0];
	int y = information[1];
	int value = information[2];
	if (x != 4) 
	{
		IMAGE image;
		switch (value)
		{
		case 1:
		{
			loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\xia.png"));
			putimage(x * 124, y * 124, &image);
		}
		break;
		case 2:
		{
			loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\qin.png"));
			putimage(x * 124, y * 124, &image);
		}
		break;
		default:
			break;
		}
	}
}

void Dynasty::oneGame()
{
	int flag = 12;

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

void Dynasty::playerInGamePrint(Map& map)
{
	for (int x = 0; x < 4; ++x)
		for (int y = 0; y < 4; ++y)
		{
			IMAGE image;
			switch (map.getElement(x, y))
			{
			case 0:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\00.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 1:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\xia.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 2:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\qin.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 3:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\han.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 4:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\jin.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 5:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\sui.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 6:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\tang.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 7:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\song.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 8:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\yuan.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 9:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\ming.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 10:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\qing.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			case 11:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\minguo.png"));
				putimage(x * 124, y * 124, &image);
			}
			case 12:
			{
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\prc.png"));
				putimage(x * 124, y * 124, &image);
			}
			break;
			default:
				break;
			}
		}

}

void Dynasty::playerEndGamePrint(int endType)
{
	switch (endType)
	{
	case 1:case 2:case 3:case 4:case 5:
	{
		initgraph(720, 430);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\fail.png"));
		putimage(0, 0, &image);
	}
	break;
	case 6:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0tang.png"));
		putimage(0, 0, &image);
	}
	break;
	case 7:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0song.png"));
		putimage(0, 0, &image);
	}
	break;
	case 8:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0yuan.png"));
		putimage(0, 0, &image);
	}
	break;
	case 9:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0ming.png"));
		putimage(0, 0, &image);
	}
	break;
	case 10:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0qing.png"));
		putimage(0, 0, &image);
	}
	break;
	case 11:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0minguo.png"));
		putimage(0, 0, &image);
	}
	break;
	case 12:
	{
		initgraph(555, 124);
		IMAGE image;
		loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\0prc.png"));
		putimage(0, 0, &image);
	}
	break;
	default:
		break;
	}
	Sleep(3000);
	closegraph();
}
