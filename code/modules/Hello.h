void startMode() {
	printf("%s\n=========================\n",i18("PROJECTS MANAGMENT SYSTEM"));

	printf("%s",i18("To start working with system please input your id: "));
	int identificator = getInt();
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("%s ",i18("Please enter your password:"));
	char pass[256];
	gets_s(pass, 256);

	user *auth = login(identificator, pass);

	if (auth == NULL) {
		system("cls");
		printf("%s\n", errors[4][0]);
	}
	else { 
		user_ptr = auth;
		changeLang();
	}
}