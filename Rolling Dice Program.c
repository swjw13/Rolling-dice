#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void drawDice(int _i, int _number);

int main()
{
	int pers_win = 0, comp_win = 0;  
	int ch;
	int pers1, pers2, pers3;
	int betting;
	int com1, com2, com3, com_total;
	int numgigi;
	int coin = 100000;
	int win = 0;
	int lose = 0;
	int choice;
	int check;

start:                              //���� ����
	system("cls");
	printf("1. My state\n");
	printf("2. Dice Rolling Game\n");
	printf("3. End\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	while (choice != 1 && choice != 2 && choice != 3)     //�Է��� 1,2,3 �̿��� ���̸� �ٽ� �Է��� ��
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
	}

	switch (choice)
	{
	case 1:
		goto My_state;
		break;
	case 3:
		return 1;
	case 2:
		goto Play_game;
		break;
	default:
		printf("Enter your choice: ");
		scanf("%d", &choice);
	}

My_state:                 // My state �� ��
	system("cls");
	printf("Current cash: %d\n", coin);
	printf("Wins: %d\n", win);
	printf("Loses: %d\n", lose);

	printf("Type any key to go main menu....");
	ch = getch();
	if (ch != NULL)				//�ƹ� �Է��� �ϸ� ����ȭ������ ���ư�.
		goto start;

Play_game:                     //���� ����
	system("cls");
	printf("Current cash : %d\n", coin);
	printf("\n");

	srand(time(NULL));
	com1 = rand() % 6 + 1;
	com2 = rand() % 6 + 1;
	com3 = rand() % 6 + 1;

	com_total = com1 + com2 + com3;	

	printf("Sum of computer's dices : %d\n", com_total);
	printf("Input your betting : ");
	scanf("%d", &betting);

	while (betting < 0)						//������ 0���� ������ ������ �ٽ� ��.
	{
		printf("You cannot bet under 0\n");
		printf("Input your betting : ");
		scanf("%d", &betting);
	}

	while (betting > coin)					//������ �ڽ��� ���� ������ ������ �ٽ� ������ ��.
	{
		printf("Betting  money is larger than your total money\n");
		printf("Input your betting : ");
		scanf("%d", &betting);
	}

	goto Ready_Bet;

Ready_Bet:                       // �ڽ��� �ֻ����� ���� ����
	system("cls");
	pers1 = rand() % 6 + 1;
	pers2 = rand() % 6 + 1;

	while (pers1 + pers2 >= com_total || pers1 + pers2 < com_total - 6)				//������� ���ڸ� ��ǻ���� ���ڿ� ����
	{
		pers1 = rand() % 6 + 1;
		pers2 = rand() % 6 + 1;
	}

	pers3 = com_total - (pers1 + pers2);
	comp_win = 0;
	pers_win = 0;

	printf("Computer's dice total is %d\n", com_total);
	
	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, 0);
		drawDice(i, 0);
		drawDice(i, 0);
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, pers1);
		drawDice(i, pers2);
		drawDice(i, pers3);
		printf("\n");
	}

	printf("Type ESC to start game\n");
	printf("Type s to surrender\n");
	printf("Any key. Rolling dice again\n");

	ch = getch();
	switch (ch)
	{
	case 's':
		coin -= 5000;
		lose += 1;
		goto Play_game;
	case 27:
		goto Bet;
	default:
		goto Ready_Bet;
	}

Bet:                                    // ���� ����
	system("cls");

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, com1);
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, pers1);
		printf("\n");
	}

	if (com1 >= pers1)
	{
		printf("Computer wins\n");
		comp_win += 1;
	}
	else
	{
		printf("You Win\n");
		pers_win += 1;
	}

	Sleep(2000);

	system("cls");

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, com1);
		drawDice(i, com2);
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, pers1);
		drawDice(i, pers2);
		printf("\n");
	}

	if (com2 >= pers2)
	{
		printf("Computer wins\n");
		comp_win += 1;
	}
	else
	{
		printf("You Win\n");
		pers_win += 1;
	}

	Sleep(2000);

	system("cls");

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, com1);
		drawDice(i, com2);
		drawDice(i, com3);
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, pers1);
		drawDice(i, pers2);
		drawDice(i, pers3);
		printf("\n");
	}

	if (com3 >= pers3)
	{
		printf("Computer wins\n");
		comp_win += 1;
	}
	else
	{
		printf("You Win\n");
		pers_win += 1;
	}
	printf("\n");

	goto Show_score;

Show_score:                  //��� �����ֱ�: ����, ��� ���� ����
	system("cls");
	printf("Computer's dice total is %d\n", com_total);

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, com1);
		drawDice(i, com2);
		drawDice(i, com3);
		printf("\n");
	}

	for (int i = 1; i <= 5; i++)
	{
		drawDice(i, pers1);
		drawDice(i, pers2);
		drawDice(i, pers3);
		printf("\n");
	}

	if (comp_win > pers_win)
	{
		printf("Final winner : Computer!!\n");
		coin -= betting;
		lose += 1;
	}
	else
	{
		printf("Final winner : you!!\n");
		coin += betting * 2;
		win += 1;
	}

	if (coin <= 0)				//�ڽ��� ���� 0���� �۰ų� �������� game over.
	{
		printf("Game Over....\n");
		return 1;
	}

	printf("1. Retry\n");
	printf("2. Back to main menu\n");
	printf("Enter your choice: ");
	scanf("%d", &check);
	while (check != 1 && check != 2)
	{
		printf("Enter your choice: ");
		scanf("%d", &check);
	}

	if (check == 1)
		goto Play_game;
	else
		goto start;
}

void drawDice(int _i, int _number)
{
	switch (_i)
	{
	case 1:
		printf("����������");
		break;
	case 2:
		switch (_number)
		{
		case 0:
			printf("��      ��");
			break;
		case 1:
		case 2:
			printf("��      ��");
			break;
		case 3:
			printf("��    �ܦ�");
			break;
		case 4:
		case 5:
		case 6:
			printf("����  �ܦ�");
			break;
		}
		break;
	case 3:
		switch (_number)
		{
		case 0:
			printf("��      ��");
			break;
		case 1:
		case 3:
		case 5:
			printf("��  ��  ��");
			break;
		case 2:
		case 6:
			printf("����  �ܦ�");
			break;
		case 4:
			printf("��      ��");
			break;
		}
		break;
	case 4:
		switch (_number)
		{
		case 0:
			printf("��      ��");
			break;
		case 1:
		case 2:
			printf("��      ��");
			break;
		case 3:
			printf("����    ��");
			break;
		case 4:
		case 5:
		case 6:
			printf("����  �ܦ�");
			break;
		}
		break;
	case 5:
		printf("����������");
		break;
	}
}