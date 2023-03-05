#include <stdio.h>
#define MAX_COMMODITY_KIND 30
#define MAX_NAME_LENGTH 10

//TODO Add commodities by users
//TODO save trade history

typedef struct commodity
{
	unsigned int commodityID;
	char commodityName[MAX_NAME_LENGTH];
	double commodityPrice;
	int commodityNum;		//Remaining quantity of goods
}COMMODITY;

typedef struct effect
{
	int effectID;
	char effectName[MAX_NAME_LENGTH];
	int effectNum;
}EFFECT;

typedef struct person
{
	char personName[MAX_NAME_LENGTH];
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
PERSON person = { "Hello",'M',10000,{0," ",0} };


void Initialize()
{
	printf_s("Welcome to the Store Simulator.\n");
	printf_s("Please input your name:");
	//TODO: Check the input;
	scanf_s("%s", &person.personName, 10);
}

int Settle(int order,int num)
{
	int total_price = order * num;
	if (total_price > person.personMoney)
	{
		//ErrorCode:1.
		//The user don`t have enough money.
		return 1;
	}
	else
	{
		person.personMoney -= total_price;
		//Looking for the user`s effect.
		for (int i = 0; i < MAX_COMMODITY_KIND; i++)
		{
			//The user`s effect have the same commodity.
			if (person.effect[i].effectID == commodity[order].commodityID)
			{
				person.effect[i].effectNum += num;
				break;
			}
			//The user`s effect don`t have the same commodity.
			if (person.effect[i].effectID == 0)
			{
				person.effect[i].effectID = commodity[order].commodityID;
				//Transfer the commodity`s name.
				for (int j = 0; j < MAX_NAME_LENGTH; j++)
				{
					if (commodity[order].commodityName[j] == NULL)break;
					person.effect[i].effectName[j] = commodity[order].commodityName[j];
				}
				person.effect[i].effectNum = num;
				break;
			}
		}
		//Trade successfully.
		return 0;
	}
}

void Store()
{
	int choose = 0,order=0;
	int  num= 0;
	int result = 0;
	printf_s("Welcome to the store.\n");
	printf_s("You can buy what you want and what you can.\n");
	printf_s("\n");
	printf_s("Order  ID   Name    Price   Number\n");
	for (int i = 0; i < MAX_COMMODITY_KIND; i++)
	{
		if (commodity[i].commodityID == 0)break;
		printf_s("%d", i+1);
		printf_s("%d  ", commodity[i].commodityID);
		printf_s("%s   ", commodity[i].commodityName); 
		printf_s("%f  ", commodity[i].commodityPrice);
		printf_s("%d", commodity[i].commodityNum);
		printf_s("\n");
	}
	printf_s("If you want to buy something please the order, otherwise please input 0 and exit the store:\n");
	if (choose != 0)
	{
		printf_s("Please input the number:\n");
		scanf_s("%d", &num);		order = choose - 1;
		//TODO: Check the input		
		result=Settle(order, num);
		switch (result)
		{
		case 0:printf_s("Successful!\n"); break;
		case 1:printf_s("Failed, you don`t have enough money.\n"); break;
		}
	}
	else if (choose == 0)
	{
		printd_s("Looking forward to your next visit.");
	}
}

void Info()
{
	printf_s("Name:%s\n", person.personName);
	//TODO: Using switch()
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
