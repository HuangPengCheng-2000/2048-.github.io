#include<iostream>
#include<array>
#include<ctime>
#include<conio.h>
#include<iomanip>
#include<easyx.h>
#include<graphics.h>
#include"dynasty.h"
#include"classic.h"
using namespace std;

int main()
{

	srand(time(0));
	bool play = true;
	do
	{
		int mode = 0;
		int gameEnd = 0;
		{
			initgraph(585, 530);
			IMAGE image;
			loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\welcome.png"));
			putimage(0, 0, &image);

			MOUSEMSG mouse;
			while (mode == 0)
			{
				if (MouseHit())
				{
					mouse = GetMouseMsg();

					if (mouse.uMsg == WM_LBUTTONDOWN)
					{
						if (mouse.x < 292)
							mode = 1;
						if (mouse.x > 292)
							mode = 2;
					}
				}
			}
			FlushMouseMsgBuffer();
			closegraph();
		}


			switch (mode)
			{
			case 1:
			{
				int hardLevel = 0;
				{
					initgraph(500, 219);
					IMAGE image;
					loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\hardlevel.png"));
					putimage(0, 0, &image);

					MOUSEMSG mouse;
					while (hardLevel == 0)
					{
						if (MouseHit())
						{
							mouse = GetMouseMsg();

							if (mouse.uMsg == WM_LBUTTONDOWN)
							{
								if (mouse.x < 166)
									hardLevel = 1;
								if (mouse.x > 167 && mouse.x < 333)
									hardLevel = 2;
								if (mouse.x > 334)
									hardLevel = 3;
							}
						}
					}
					FlushMouseMsgBuffer();
					closegraph();
				}
				Classic classic;
				classic.oneGame(hardLevel);
				do
				{
					gameEnd = 1;
					initgraph(585, 530);
					IMAGE image;
					loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\playend.png"));
					putimage(0, 0, &image);
					while (gameEnd)
					{
						MOUSEMSG mouse;

						if (MouseHit())
						{
							mouse = GetMouseMsg();
							if (mouse.uMsg == WM_LBUTTONDOWN)
							{
								if (mouse.x < 292 && mouse.y>300)
								{
									play = true;
									gameEnd = 0;
								}
								if (mouse.x > 292 && mouse.y > 300)
								{
									play = false;
									gameEnd = 0;
								}
							}
						}
					}
					FlushMouseMsgBuffer();

				} while (gameEnd);
				closegraph();
			}
			break;
			case 2:
			{
				Dynasty dynasty;
				dynasty.oneGame();
				do
				{
					gameEnd = 1;
					initgraph(585, 530);
					IMAGE image;
					loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\playend.png"));
					putimage(0, 0, &image);
					while (gameEnd)
					{
						MOUSEMSG mouse;

						if (MouseHit())
						{
							mouse = GetMouseMsg();
							if (mouse.uMsg == WM_LBUTTONDOWN)
							{
								if (mouse.x < 292 && mouse.y>300)
								{
									play = true;
									gameEnd = 0;
								}
								if (mouse.x > 292 && mouse.y > 300)
								{
									play = false;
									gameEnd = 0;
								}
							}
						}
					}
					FlushMouseMsgBuffer();

				} while (gameEnd);
				closegraph();
			}
			break;
			default:
				break;
			}
			
			do
			{
				gameEnd = 1;
				initgraph(585, 530);
				IMAGE image;
				loadimage(&image, _T("D:\\VS2019\\2048_7.06\\image\\playend.png"));
				putimage(0, 0, &image);
				while (gameEnd)
				{
					MOUSEMSG mouse;

					if (MouseHit())
					{
						mouse = GetMouseMsg();
						if (mouse.uMsg == WM_LBUTTONDOWN)
						{
							if (mouse.x < 292 && mouse.y>300)
							{
								play = true;
								gameEnd = 0;
							}
							if (mouse.x > 292 && mouse.y > 300)
							{
								play = false;
								gameEnd = 0;
							}
						}
					}
				}
				FlushMouseMsgBuffer();

			} while (gameEnd);
			closegraph();
			
	} while (play);
	return 0;
}