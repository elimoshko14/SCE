// director menu
void menu_1() {
	int i = 0;
	printf("[%d] Manage projects:\n", ++i);
	printf("[%d] Display all projects:\n", ++i);
	printf("[%d] Manage category:\n", ++i);
	printf("[%d] Display all categorys by specific project:\n", ++i);
	printf("[%d] Manage tasks:\n", ++i);
	printf("[%d] Display all completed tasks by specific project:\n", ++i);
	printf("[%d] Display all uncompleted tasks by specific project:\n", ++i);
	printf("[%d] Manage comments:\n", ++i);
	printf("[%d] Display all comments by specific task:\n", ++i);
	printf("[%d] Display all comments by specific user:\n", ++i);
	printf("[%d] Manage users:\n", ++i);
	printf("[%d] Display all users by specific project:\n", ++i);
	printf("[%d] Display all workers:\n", ++i);
	printf("[%d] Display all managers:\n", ++i);

	printf("[%d] Copy Specific Task\n", ++i);
	printf("[%d] Switch language to Russian:\n", ++i);
	printf("[%d] Exit", ++i);
	
	printf("\n\n Please make your choise: ");
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