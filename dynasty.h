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
	void playerInGamePrint(Map&);//����չʾ
	void playerEndGamePrint(int endType);//����չʾ
};
#endif // !DYNASTY_H
