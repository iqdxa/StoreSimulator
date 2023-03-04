#include <stdio.h>
#define MAX_COMMODITY_KIND 30

typedef struct commodity
{
	unsigned int commodityID;
	char commodityName[10];
	double commodityPrice;
	int commodityQuantity;		//商品剩余数量

}COMMODITY;

typedef struct effect
{
	char effectName[10];
	int effectQuantity;
}EFFECT;

typedef struct person
{
	char personName[10];
	char personSex;
	float personMoney;
	EFFECT effect;
}PERSON;

void Initialize()
{
	//Commodity initial
	COMMODITY commodity[MAX_COMMODITY_KIND] = {
		{1001,"Apple",5,10},
		{1002,"Cup",10,20}
	};

	//Person initial
	PERSON person = {"Hello",'M',10000,{NULL,0}};

	printf_s("Please input your name:");
	scanf_s("%s", &person.personName,10);
}

void Menu()
{
	//一直循环
	for (;;)
	{
		int choose = 0;
		printf("1.Purchase goods");
		printf("2.View personal information");
		printf("0.Exit");
		printf("Please input a choice:");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:Store(); break;
		case 2:Info(); break;
		default:break;
		}
	}
	
}
int main()
{
	Initialize();
	Menu();
	return 0;
}
