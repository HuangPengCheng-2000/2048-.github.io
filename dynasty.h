#ifndef DYNASTY_H
#define DYNASTY_H
#include<vector>
#include<array>
#include<iostream>
#include"map.h"
using namespace std;

class Dynasty
{
public:
	Dynasty(){}
	~Dynasty() {}
	int gameEnd(Map&);
	void setMapZeroElement(Map&);
	void oneGame();
	void playerInGamePrint(Map&);//局内展示
	void playerEndGamePrint(int endType);//局终展示
};
#endif // !DYNASTY_H
