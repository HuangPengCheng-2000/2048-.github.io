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
	int successKey;//��Ϸʤ����ֵ
	array<int*, 4>line0;//0-3Ϊ�а�
	array<int*, 4>line1;
	array<int*, 4>line2;
	array<int*, 4>line3;
	array<int*, 4>line4;//4-7Ϊ�а�
	array<int*, 4>line5;
	array<int*, 4>line6;
	array<int*, 4>line7;
	array<array<int*, 4>, 8> lines;//��λ�����������
	//public: setMapZeroElement() ���躯��
	vector<int> tellMapEmptyElementPosition();//����map��0Ԫλ��
	//public:bool mapChange(int mapChangeType)���躯��
	bool lineEmpty(int index);//ָ�����Ƿ�Ϊ��
	int tellLineNonzeroNumber(int index);//����ָ���еķ���Ԫ�صĸ���
	bool lineChange(int index, int changeType);//��ָ���л��н��б任�������������Ƿ������ʵ���Ա仯

public:
	Map(int flag);//���캯����������ʼ��
	~Map() {}
	int getElement(int x, int y);//��ȡָ��λ��Ԫ��ֵ
	int getMaxElement();//��ȡ���Ԫ�ص�ֵ
	bool isMapFull();//�ж�map�Ƿ���
	bool achieveKey();//�ж��Ƿ���Ԫ�شﵽ�趨����ֵ
	array<int,3> setMapZeroElementInformation();//map��0Ԫ���������ֵ ���غ��������ֵ
	bool mapChange(int mapChangeType);//��map���б任�������������Ƿ������ʵ���Ա仯
};
#endif // !MAP_H
