#ifndef CLASSIC_H
#define CLASSIC_H
#include<vector>
#include<array>
#include<iostream>
#include"map.h"
using namespace std;

class Classic
{
public:
	Classic() {}
	~Classic() {}
	int gameEnd(Map);	
	void setMapZeroElement(Map&);
	void oneGame(int hardLevel);
	void playerInGamePrint(Map&);//����չʾ
	void playerEndGamePrint(int endType);//����չʾ����ʤ����ʧ��
};
#endif // !CLASSIC_H
