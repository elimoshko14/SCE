void userSession() {
	system("cls");
	printf("\nHello %s welcome to system\n\n", user_ptr->name);
	// print main menu
	mainMenu();

	int choose = getInt();
	mainChoose(choose);
}