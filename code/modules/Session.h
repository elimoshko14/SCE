void userSession() {
	system("cls");
	printf("\nHello %s welcome to system\n\n", user_ptr->name);
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