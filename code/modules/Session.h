void userSession() {
	
	printf("\n %s %s\n %s\n",i18("Hello"),  user_ptr->name, i18("welcome to system"));
	// print main menu
	mainMenu();

	int choose = getInt();
	switch (user_ptr->level) {
	case 1: { directorChoose(choose); break; }
	case 2: { managerChoose(choose); break; }
	case 3: { workerChoose(choose); break; }
	default: break;
	}
}