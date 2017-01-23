// director menu
void menu_1() {
	int i = 0;
	printf("[%d] %s\n", ++i, i18("Manage projects:"));
	printf("[%d] %s\n", ++i, i18("Manage users:"));
	printf("[%d] %s\n", ++i, i18("Manage category:"));
	printf("[%d] %s\n", ++i, i18("Manage tasks:"));
	printf("[%d] %s\n", ++i, i18("Manage comments:"));
	printf("[%d] %s\n", ++i, i18("Display all projects:"));
	printf("[%d] %s\n", ++i, i18("Display all workers:"));
	printf("[%d] %s\n", ++i, i18("Display all managers:"));
	printf("[%d] %s\n", ++i, i18("Display all categorys by specific project:"));
	printf("[%d] %s\n", ++i, i18("Display all tasks by specific project:"));
	printf("[%d] %s\n", ++i, i18("Display all completed tasks by specific project:"));
	printf("[%d] %s\n", ++i, i18("Display all uncompleted tasks by specific project:"));
	printf("[%d] %s\n", ++i, i18("Display all comments by specific task:"));
	printf("[%d] %s\n", ++i, i18("Display all comments by specific user:"));
	printf("[%d] %s\n", ++i, i18("Display all users by specific project:"));
	printf("[%d] %s\n", ++i, i18("Copy Specific Task"));
	printf("[%d] %s\n", ++i, i18("Copy Specific project"));
	printf("[%d] %s\n", ++i, i18("Switch language to Russian:"));
	printf("[%d] %s", ++i, i18("Exit"));
	
	printf("\n\n Please make your choise: ");
}

// manager menu
void menu_2(){
	// check if this manager has project
	if (user_ptr->porj_id == 0 || findProjById(user_ptr->porj_id) == NULL) {
		printf("%s\n", errors[4][4]);
		exit(0);
	}

	else {
		int i = 0;
		printf("[%d] %s\n", ++i, i18("Manage users:"));
		printf("[%d] %s\n", ++i, i18("Manage tasks:"));
		printf("[%d] %s\n", ++i, i18("Manage category:"));
		printf("[%d] %s\n", ++i, i18("Manage comments:"));

		printf("[%d] %s\n", ++i, i18("Display all categorys"));

		printf("[%d] %s\n", ++i, i18("Display all tasks:"));
		printf("[%d] %s\n", ++i, i18("Display all completed tasks:"));
		printf("[%d] %s\n", ++i, i18("Display all uncompleted tasks:"));
		
		
		printf("[%d] %s\n", ++i, i18("Display all comments by specific task:"));
		printf("[%d] %s\n", ++i, i18("Display all comments by specific user:"));
		
		printf("[%d] %s\n", ++i, i18("Display all users:"));
		printf("[%d] %s\n", ++i, i18("Copy Specific Task"));
		printf("[%d] %s\n", ++i, i18("Switch language to Russian:"));
		printf("[%d] %s", ++i, i18("Exit"));

		printf("\n\n Please make your choise: ");
	}
}

// worker menu
void menu_3() {
	// check if this manager has project
	if (user_ptr->porj_id == 0 || findProjById(user_ptr->porj_id) == NULL) {
		printf("%s\n", errors[4][4]);
		exit(0);
	}
	else {
		int i = 0;
		printf("[%d] Project info:\n", ++i);
		printf("[%d] My Task:\n", ++i);
		printf("[%d] Complete a Task:\n", ++i);
		printf("[%d] Manage comments:\n", ++i);
		printf("[%d] Display all comments:\n", ++i);
		printf("[%d] Display all workers:\n", ++i);
		printf("[%d] Overdue of task:\n", ++i);
		printf("[%d] Switch language to Russian:\n", ++i);
		printf("[%d] Exit", ++i);

		printf("\n\n Please make your choise: ");
	}
}


void mainMenu()  {
	switch (user_ptr->level) {
	case 1: { menu_1(); break; }
	case 2: { menu_2(); break; }
	case 3: { menu_3(); break; }
	default: break;
	}
}