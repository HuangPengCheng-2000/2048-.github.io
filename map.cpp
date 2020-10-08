#include<iostream>
#include<array>
#include<vector>
#include<iomanip>
#include<ctime>
#include<conio.h>
#include<easyx.h>
#include<graphics.h>
#include"Map.h"

Map::Map(int flag) :successKey(flag)
{
	for (int i = 0; i < 4; ++i)//����set map ����Ԫ��Ϊ0
		for (int j = 0; j < 4; ++j)
			element[i][j] = 0;

	lines = { line0,line1,line2,line3, line4,line5, line6,line7 };
	//Ϊ���е�Ԫ��Ԫ��
	//�а�
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			lines[i][j] = &element[i][j];
	//�а�
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			lines[i + 4][j] = &element[j][i];

	//��ѡ����elementΪ1��2
	int position1, position2;
	position1 = rand() % 16;
	position2 = rand() % 16;
	while (position1 == position2)
		position2 = rand() % 16;
	int x1, x2, y1, y2;
	x1 = position1 / 4;
	x2 = position2 / 4;
	y1 = position1 % 4;
	y2 = position2 % 4;
	int ele1 = rand() % 2;
	int ele2 = rand() % 2;
	element[x1][x2] = ele1 + 1;
	element[x2][y2] = ele2 + 1;
}


int Map::getElement(int x, int y)//��ȡָ��λ��Ԫ��ֵ
{
	return element[x][y];
}

int Map::getMaxElement()
{
	int max = 0;
	for(int i=0;i<4;++i)
		for (int j = 0; j < 4; ++j)
		{
			if (element[i][j] > max)
				max = element[i][j];
		}
	return max;
}


bool Map::isMapFull()//�ж�map�Ƿ���
{
	bool t = true;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (element[i][j] == 0)
				t = false;
		}
	return t;
}


bool Map::achieveKey()//�ж��Ƿ���Ԫ�شﵽ�趨����ֵ
{
	bool t = false;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (element[i][j] == successKey)
				t = true;
		}
	return t;
}


vector<int> Map::tellMapEmptyElementPosition()//����map��0Ԫλ��
{
	vector<int> position;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			if (element[i][j] == 0)
				position.push_back(4 * i + j);//λ�ñ���
		}
	return position;
}

array<int, 3> Map::setMapZeroElementInformation()//map��0Ԫ���������ֵ ���غ��������ֵ
{
	vector<int> zeroPosition = tellMapEmptyElementPosition();
	int zeroNumber = zeroPosition.size();//0Ԫ����
	if (!zeroPosition.empty())
	{
		int zeroSelect = rand() % zeroNumber;//���ѡ��һ��0Ԫ
		int zero = zeroPosition[zeroSelect];
		int zeroX = zero / 4;
		int zeroY = zero % 4;
		int value = rand() % 2 + 1;

		element[zeroX][zeroY] = value;
		array<int, 3>information = { zeroX,zeroY,value };
		return information;
	}
	else
	{
		array<int, 3>information = { 4,4,4 };
		return information;
	}
}

bool Map::lineEmpty(int index)
{
	bool empty = true;
	for (int i = 0; i < 4; ++i)
	{
		if (*lines[index][i] != 0)
			empty = false;
	}
	return empty;
}
int Map::tellLineNonzeroNumber(int index)
{
	int cnt = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (*lines[index][i] != 0)
			cnt++;
	}

	return cnt;
}

bool Map::lineChange(int index, int changeType)
{
	bool lineChange = false;
	if (lineEmpty(index))
		return false;
	array<int, 4 >ele = { *lines[index][0],*lines[index][1], *lines[index][2] ,*lines[index][3] };
	vector<int>nonzero;
	int nonzeroNumber = 0;
	//����Ԫ����array
	switch (changeType)
	{
	case 1:
	{
		for (int i = 0; i < 4; ++i)
		{
			if (ele[i] != 0)
			{
				nonzero.push_back(ele[i]);
				nonzeroNumber++;
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < 4; ++i)
		{
			if (ele[3-i] != 0)
			{
				nonzero.push_back(ele[3-i]);
				nonzeroNumber++;
			}
		}
	}
	break;
	default:
		break;
	}
	//�Ƚ��Ƿ�����Ԫ��λ�ƶ�
	switch (changeType)
	{
	case 1:
	{
		for (int i = 0; i < nonzeroNumber; ++i)
		{
			if (ele[i] == 0)
				lineChange = true;
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < nonzeroNumber; ++i)
		{
			if (ele[3-i] == 0)
				lineChange = true;
		}
	}
	break;
	default:
		break;
	}
	bool mark = true;//�����ֹ����������Ԫ������
	for (int i = 0; i < nonzeroNumber-1&&mark; ++i)
	{
		if (nonzero[i] == nonzero[i + 1])
		{
			nonzero[i]++;
			nonzero[i + 1] = 0;
			mark = false;
			lineChange = true;
			if (i < nonzeroNumber - 2)
			{
				for (int j = i + 1; j < nonzeroNumber - 1; ++j)
				{
					nonzero[j] = nonzero[j + 1];
				}
				nonzero[nonzeroNumber - 1] = 0;
			}
		}
	}
	//���¸�ֵ��ԭline
	switch (changeType)
	{
	case 1:
	{
		for (int i = 0; i < nonzeroNumber; ++i)
			*lines[index][i] = nonzero[i];
		for (int i = nonzeroNumber; i < 4; ++i)
		*lines[index][i] = 0;
	}
	break;
	case 2:
	{
		for (int i = 0; i < nonzeroNumber; ++i)
			*lines[index][3 - i] = nonzero[i];
		for (int i = nonzeroNumber; i < 4; ++i)
			*lines[index][3 - i] = 0;
	}
	break;
	default:
		break;
	}
	return lineChange;
}

bool Map::mapChange(int mapChangeType)
{
	bool change = false;
	switch (mapChangeType)
	{
	case 1://��
	{
		for (int i = 4; i < 8; ++i)
		{
			if (lineChange(i, 1))
				change = true;
		}
	}
	break;

	case 2://��
	{
		for (int i = 4; i < 8; ++i)
		{
			if (lineChange(i, 2))
				change = true;
		}
	}
	break;

	case 3://��
	{
		for (int i = 0; i < 4; ++i)
		{
			if (lineChange(i, 1))
				change = true;
		}
	}
	break;

	case 4://��
	{
		for (int i = 0; i < 4; ++i)
		{
			if (lineChange(i, 2))
				change = true;
		}
	}
	break;

	default:
		break;
	}

	return change;
}