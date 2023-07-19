#pragma once
#include <thread>
#include <list>
class Print
{
public:
	void Initialize();
	void Update();
	void Draw();

private:
	int scanNum;
	int scanNumHolder;
	int scanNumPasser;
	int scanNumRecive;
	std::thread t1;
	bool ShootFlag;
	bool passFlag;
	void Pass();
	void Shoot();
	void Replay();
	/*void updateFunction();*/
};

