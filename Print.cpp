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
		printf("�N���{�[���������Ă܂����H\n");
		scanf_s("%d", &scanNumHolder);
		
	}
	printf("�V���[�g���܂����H�p�X���܂����H�@�p�X�Ȃ�1���V���[�g�Ȃ�2��\n");
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
	printf("\n�p�X�̎󂯎����I��ł�������\n");
	scanf_s("%d", &scanNumRecive);
	printf("\n%d�Ԃ̃p�X��%d�Ԃɓn����\n", scanNumHolder, scanNumRecive);
	passFlag = true;
}

void Print::Shoot()
{
	
	if (scanNumHolder == 0) {
		printf("�N���V���[�g���܂����H\n");
		scanf_s("%d", &scanNumHolder);
		
	}
	ShootFlag = true;
	printf("\n%d�Ԃ̃V���[�g\n", scanNumHolder);
	
}

void Print::Replay()
{
	auto updateFunction = [&]() {

		if (ShootFlag==true) {
			
			printf("���v���C�I");
			if (passFlag == true) {
				printf("\n%d�Ԃ̃p�X��%d�Ԃɓn����\n", scanNumPasser, scanNumRecive);
			}
			else {
				scanNumRecive = scanNumHolder;
			}	printf("\n%d�Ԃ̃V���[�g\n", scanNumRecive);
			
			ShootFlag = false;
		}
		}; 
	t1 = std::thread(updateFunction);
	
}
