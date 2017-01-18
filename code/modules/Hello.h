void startMode() {
	printf("PROJECTS MANAGMENT SYSTEM\n=========================\n");

	printf("To start working with system please input your id: ");
	

	int identificator = getInt();

	user *auth=NULL;
	auth = login(identificator);

	if (auth == NULL) {
		system("cls");
		printf("ERROR: user with id [%d] is not register in system\n", identificator);
	}
	else { user_ptr = auth;  }
}