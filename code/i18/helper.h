#define LEN 1000

char MANAGE_PROJECT[LEN];
char MANAGE_USERS[LEN];


void changeLang() {

	if (!user_ptr) {
		strcpy(MANAGE_PROJECT, "Manage projects");
	}
	else {
		char i18_ru[] = "../i18/RU.txt";
		char i18_en[] = "../i18/EN.txt";
		FILE * file_ptr;
		if (strcmp(user_ptr->lang, "EN") == 0)
			file_ptr = fopen(i18_en, "r");
		else file_ptr = fopen(i18_ru, "r");
		if (isEmptyFile(file_ptr)) return;

		// GET DATA FROM FILE //
		char ch; // See end of loop
		do {
			char key[LEN], value[LEN];
			fgets(key, LEN, file_ptr);
			strtok(key, "\n");

			if (strcmp(key, "MANAGE_PROJECT") == 0) {
				fgets(value, LEN, file_ptr);
				strtok(value, "\n");
				strcpy(MANAGE_PROJECT, value);
			}
			else if (strcmp(key, "MANAGE_USERS") == 0) {
				fgets(value, LEN, file_ptr);
				strtok(value, "\n");
				strcpy(MANAGE_USERS, value);
			}
			else {}
			
			ch = fgetc(file_ptr);
			ungetc(ch, file_ptr);
		} while (!feof(file_ptr) && ch != EOF);

		fclose(file_ptr);
	}
}