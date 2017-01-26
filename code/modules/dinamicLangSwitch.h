void dinamicLangSwitch() {
	system("cls");
	if (strcmp(user_ptr->lang, "EN") == 0) {
		strcpy(user_ptr->lang, "RU");
	}
	else {
		strcpy(user_ptr->lang, "EN");
	}
}