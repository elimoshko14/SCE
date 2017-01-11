void getUsers() {

	FILE * users_file;
	char filename[] = "../db/users.txt";
	users_file = fopen(filename, "r");

	if (users_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct user * user_struct = (struct user *)malloc(sizeof(struct user));

		char buffer[256];
		// get id
		fscanf(users_file, "%ld", &(user_struct->id));
		// drop line
		fgets(buffer, 256, users_file);

		// get name
		fgets(user_struct->name, '256', users_file);
		// clear \n
		strtok(user_struct->name, "\n");

		// get level
		fscanf(users_file, "%d", &(user_struct->level));
		// end line
		fgets(buffer, 256, users_file);
		
		// get proj id
		fscanf(users_file, "%d", &(user_struct->porj_id));
		// drop line
		fgets(buffer, 256, users_file);

		// get task id
		fscanf(users_file, "%d", &(user_struct->task_id));
		// drop line
		fgets(buffer, 256, users_file);

		// get lang
		fgets(user_struct->lang, '256', users_file);
		// clear \n
		strtok(user_struct->lang, "\n");

		// get salaty
		fscanf(users_file, "%d", &(user_struct->salery));
		// drop line
		fgets(buffer, 256, users_file);

		// get onlilne
		fscanf(users_file, "%d", &(user_struct->online));
		// drop line
		fgets(buffer, 256, users_file);

		// get coments array (strings)
		fscanf(users_file, "%s", user_struct->coments);
		// drop line
		fgets(buffer, 256, users_file);


		// get tags array (strings)
		fscanf(users_file, "%s[10]", user_struct->due);
		// drop line
		fgets(buffer, 256, users_file);



		printf("ID:\t%ld\n", user_struct->id);
		printf("Name:\t%s\n", user_struct->name);
		printf("Level:\t%d\n", user_struct->level);
		printf("Project ID:\t%d\n", user_struct->porj_id);
		printf("Task ID:\t%d\n", user_struct->task_id);
		printf("Language:\t%s\n", user_struct->lang);
		printf("Salary:\t%d\n", user_struct->salery);
		printf("Online:\t%d\n", user_struct->online);
		printf("Comments:\t%s\n", user_struct->coments);
		printf("Due:\t%s\n", user_struct->due);		
		printf("-------------\n");

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(users_file);
		ungetc(ch, users_file);

	} while (!feof(users_file) && ch != EOF);

	fclose(users_file);
}

