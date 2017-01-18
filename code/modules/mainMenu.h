void menu_3()
{

}

void menu_2()
{

}

/*void ChangeUserName(user * node) {
char new_name[256];
printf("please enter name for user\n");
scanf("%s", &new_name);
*(node->name) = new_name;
}

void ChangeUserSalary(user * node) {
int new_salary;
printf("please enter salary for user\n");
scanf("%d", &new_salary);
node->salery = new_salary;
}

void ChangeUserDue(user * node) {
char new_due[256];
printf("please enter new dead line for user\n");
scanf("%s", &new_due);
*(node->due) = new_due;
}

void UpdateUser(long id) {
user *node = findUserById(id);
if (node != NULL) {
printf("User has been find!\n");
int choice;
do
{
printf("Menu\n\n");
printf("1. change user ID\n");
printf("2. change user name\n");
printf("3. change user salary\n");
printf("4. change user dead line\n");
printf("5. Exit\n");
scanf("%d", &choice);

switch (choice)
{
case 1: ChangeUserId(node);
break;
case 2: ChangeUserName(node);
break;
case 3: ChangeUserSalary(node);
break;
case 4: ChangeUserDue(node);
break;
case 5: printf("exit from menu,bye!\n");
break;
default: printf("Invalid choice!\n");
break;
}

} while (choice != 5);

}
else
{
printf("user has not been find,please try again!\n");
}
FILE * users_file;
char filename[] = "../db/users.txt";
users_file = fopen(filename, "w");
if (users_file == NULL) {
perror("Error");
return;
}
fclose(users_file);

user_node * u = users_list;
while (u) {
SetUser(u->ptr);
u = u->next;
}
}*/

void management_projetcts()
{
	printf("emter 1 for add project:\n");
	printf("enter 2 for delete project:\n");
	printf("enter 3 for upDate project:\n");
	int x;
	scanf("%d", &x);
	if (x == 1)
	{
		int id, manId, cost;
		char due[256];
		printf("enter id project, manager id, cost of project:\n");
		scanf("%d%d%d", &id, &manId, &cost);
		printf("enter deadline of project\n");
		scanf("%s", due);
		if (findProjById(id) == NULL)
			if ((findUserById(manId) != NULL) && (findUserById(manId)->level == 2))
				addProj(id, manId, cost, due);
	}
	else if (x == 2)
	{

	}
	else
	{//need fixt it
		int id;
		proj *tP;
		printProjTree();
		printf("enter id of proj that you want to change:\n ");
		scanf("%d", &id);
		tP = findProjById(id);
		if (tP != NULL)
		{

		}
	}
}

void provide_tasks()
{
	task_node *tL = tasks_list;
	while (tL != NULL)
	{
		if (tL->ptr->status != 1)
		{
			printTask(tL->ptr);
			printf("enter 1 for provide else enter 0:\n");
			int x;
			scanf("%d", &x);
			if (x)
				updateTask(tL->ptr->id, tL->ptr->title, tL->ptr->user_id, tL->ptr->category_id, tL->ptr->cost, 1, tL->ptr->tags, tL->ptr->due, tL->ptr->comments);
		}
		tL = tL->next;
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
		provide_tasks();
		break;
	}
	case 2:
	{
		management_projetcts();
		break;
	}
	default:
		break;
	}
}

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













