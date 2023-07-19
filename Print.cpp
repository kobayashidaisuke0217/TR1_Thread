#include "Print.h"
#include <stdio.h>
void Print::Initialize()
{
	scanNumHolder = 0;
	ShootFlag = false;
	passFlag = false;
}

void Print::Update()
{
	
	if (scanNumHolder == 0) {
		printf("誰がボールを持ってますか？\n");
		scanf_s("%d", &scanNumHolder);
		
	}
	printf("シュートしますか？パスしますか？　パスなら1をシュートなら2を\n");
	scanf_s("%d", &scanNum);
	Replay();
	
	
	if (scanNum ==1 ) {
		Pass();
		
	}
	else if(scanNum==2){
		Shoot();
		
	}
	
	t1.join();
      
		

	
	scanNumHolder = scanNumRecive;
	
}

void Print::Draw()
{
	
}

void Print::Pass()
{


	scanNumPasser = scanNumHolder;
	printf("\nパスの受け取り手を選んでください\n");
	scanf_s("%d", &scanNumRecive);
	printf("\n%d番のパスが%d番に渡った\n", scanNumHolder, scanNumRecive);
	passFlag = true;
}

void Print::Shoot()
{
	
	if (scanNumHolder == 0) {
		printf("誰がシュートしますか？\n");
		scanf_s("%d", &scanNumHolder);
		
	}
	ShootFlag = true;
	printf("\n%d番のシュート\n", scanNumHolder);
	
}

void Print::Replay()
{
	auto updateFunction = [&]() {

		if (ShootFlag==true) {
			
			printf("リプレイ！");
			if (passFlag == true) {
				printf("\n%d番のパスが%d番に渡った\n", scanNumPasser, scanNumRecive);
			}
			else {
				scanNumRecive = scanNumHolder;
			}	printf("\n%d番のシュート\n", scanNumRecive);
			
			ShootFlag = false;
		}
		}; 
	t1 = std::thread(updateFunction);
	
}
