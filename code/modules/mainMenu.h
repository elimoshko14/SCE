// director menu
void menu_1() {
	int i = 0;
	printf("enter %d for provide tastks of workers:\n", ++i);
	printf("enter %d for management projetcts:\n", ++i);
	printf("enter %d for management tasks:\n", ++i);
	printf("enter %d for management users:\n", ++i);
	printf("enter %d for management comments:\n", ++i);
	printf("enter %d for management categories:\n", ++i);
	printf("enter %d to get projects list:\n", ++i);
	printf("enter %d to get users list:\n", ++i);
	printf("enter %d to get tasks list:\n", ++i);
	printf("enter %d  to get categories list:\n", ++i);
	printf("enter %d to get comments list:\n", ++i);
	printf("enter %d for changeing associate task:\n", ++i);
	printf("enter %d for changeing associate project:\n", ++i);
	printf("enter %d for replication task:\n", ++i);
	printf("enter %d for replication project:\n", ++i);
	printf("enter 16 for changing the interface language to Russian:\n", ++i);
	
	int choose;
	scanf("%d", &choose);
	switch (choose) {
	case 1: { printf("You choose %d, and its right choise... \n", choose); 
		updateTaskStatus();
		break; }
	case 2: { management_projets(); break; }
	
	default: break;
	}
}

// manager menu
void menu_2(){}

// worker menu
void menu_3() {}


void mainMenu()  {
	switch (user_ptr->level) {
	case 1: { menu_1(); break; }
	case 2: { menu_2(); break; }
	case 3: { menu_3(); break; }
	default: break;
	}
}