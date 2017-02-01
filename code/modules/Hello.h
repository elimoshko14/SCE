void startMode() {
	printf("%s\n=========================\n",i18("PROJECTS MANAGMENT SYSTEM"));
	printf("To start working with system please input your id:");
	int identificator = getInt();
	char c;
	while ((c = getchar()) != '\n' && c != EOF) {}
	printf("Please enter your password:");
	char pass[256];
	gets_s(pass, 256);

	user *auth = login(identificator, pass);

	if (auth == NULL) {
		
		printf("%s\n", i18("User not found!"));
	}
	else { 
		user_ptr = auth;
		changeLang();
	}
}