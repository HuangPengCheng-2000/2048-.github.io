#ifndef MAP_H
#define MAP_H
#include<iostream>
#include<array>
#include<vector>
using namespace std;

class Map
{
private:
	int element[4][4];
	int successKey;//游戏胜利阈值
	array<int*, 4>line0;//0-3为行绑定
	array<int*, 4>line1;
	array<int*, 4>line2;
	array<int*, 4>line3;
	array<int*, 4>line4;//4-7为列绑定
	array<int*, 4>line5;
	array<int*, 4>line6;
	array<int*, 4>line7;
	array<array<int*, 4>, 8> lines;//单位行列组成数组
	//public: setMapZeroElement() 所需函数
	vector<int> tellMapEmptyElementPosition();//返回map中0元位置
	//public:bool mapChange(int mapChangeType)所需函数
	bool lineEmpty(int index);//指定行是否为空
	int tellLineNonzeroNumber(int index);//返回指定行的非零元素的个数
	bool lineChange(int index, int changeType);//对指定行或列进行变换操作，并返回是否进行了实质性变化

public:
	Map(int flag);//构造函数，包含初始化
	~Map() {}
	int getElement(int x, int y);//获取指定位置元素值
	int getMaxElement();//获取最大元素的值
	bool isMapFull();//判断map是否满
	bool achieveKey();//判断是否有元素达到设定的阈值
	array<int,3> setMapZeroElementInformation();//map中0元进行随机赋值 返回横纵坐标和值
	bool mapChange(int mapChangeType);//对map进行变换操作，并返回是否进行了实质性变化
};
#endif // !MAP_H
