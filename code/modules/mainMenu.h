void mainMenu(user *u) 
{
	switch (u->level)
	{
	case 1:
	{
		menu_1();
		break;
	}
	case 2:
	{
		manu_2();
		break;
	}
	case 3:
	{
		manu_3();
		break;
	}
	default:
		break;
	}
}

void menu_1() 
{
	printf("enter 1 for provide tastks of workers:\n");
	printf("enter 2 for management projetcts:\n");
	printf("enter 3 for management tasks:\n");
	printf("enter 4 for management users:\n");
	printf("enter 5 for management comments:\n");
	printf("enter 6 for management categories:\n");
	printf("enter 7 to get projects list:\n");
	printf("enter 8 to get users list:\n");
	printf("enter 9 to get tasks list:\n");
	printf("enter 10  to get categories list:\n");
	printf("enter 11 to get comments list:\n");
	printf("enter 12 for changeing associate task:\n");
	printf("enter 13 for changeing associate project:\n");
	printf("enter 14 for replication task:\n");
	printf("enter 15 for replication project:\n");
	printf("enter 16 for changing the interface language to Russian:\n");
	int choose;
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
	{
		break;
	}
	default:
		break;
	}
}

void menu_2()
{

}

void menu_3()
{

}
