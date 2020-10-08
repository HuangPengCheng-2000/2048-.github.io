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
	void playerInGamePrint(Map&);//局内展示
	void playerEndGamePrint(int endType);//局终展示：获胜还是失败
};
#endif // !CLASSIC_H
