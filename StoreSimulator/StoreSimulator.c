#include <stdio.h>
#define MAX_COMMODITY_KIND 30

typedef struct commodity
{
	unsigned int commodityID;
	char commodityName[10];
	double commodityPrice;
	int commodityNum;		//Remaining quantity of goods

}COMMODITY;

typedef struct effect
{
	int effectID;
	char effectName[10];
	int effectNum;
}EFFECT;

typedef struct person
{
	char personName[10];
	char personSex;
	float personMoney;
	EFFECT effect[MAX_COMMODITY_KIND];
}PERSON;

//Commodity initial
COMMODITY commodity[MAX_COMMODITY_KIND] = {
	{1001,"Apple",5,10},
	{1002,"Cup",10,20}
};

//Person initial
PERSON person = { "Hello",'M',10000,{0,"",0} };


void Initialize()
{
	printf_s("Welcome to the Store Simulator.\n");
	printf_s("Please input your name:");
	//TODO: Check the input;
	scanf_s("%s", &person.personName, 10);
}

void Store()
{
	printf_s("ID   Name   Price   Number\n");
	for (int i = 0; i < MAX_COMMODITY_KIND; i++)
	{
		if (commodity[i].commodityID == 0)
		{
			break;
		}
		printf_s("%d  ", commodity[i].commodityID);
		printf_s("%s  ", commodity[i].commodityName); 
		printf_s("%f  ", commodity[i].commodityPrice);
		printf_s("%d", commodity[i].commodityNum);
		printf_s("\n");
	}
}

void Info()
{
	printf_s("Name:%s\n", person.personName);
	if (person.personSex == 'M')
	{
		printf_s("Sex:Male\n");
	}
	else if (person.personSex == 'F')
	{
		printf_s("Sex:Female\n");
	}
	printf_s("Money:%f\n", person.personMoney);

	printf_s("This list is your effect:\n");
	for (int i = 0; i < MAX_COMMODITY_KIND; i++)
	{
		if (person.effect[i].effectID == 0)
		{
			if (i == 0)
			{
				printf_s("There is nothing.\n");
			}
			break;
		}
		printf_s("ID:%d\n", person.effect[i].effectID);
		printf_s("Name:%s\n", person.effect[i].effectName);
		printf_s("Number:%d\n", person.effect[i].effectNum);
		printf_s("\n");
	}
}

void Menu()
{
	//loop
	for (;;)
	{
		int choose = 0;
		printf_s("1.Purchase goods\n");
		printf_s("2.View personal information\n");
		printf_s("0.Exit\n");
		printf_s("Please input a choice:\n");
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1:Store(); break;
		case 2:Info(); break;
		default:break;
		}
		if (choose)
		{
			break;
		}
	}
	
}
int main()
{
	Initialize();
	Menu();
	return 0;
}
