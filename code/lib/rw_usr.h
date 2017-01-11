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

		// get deadLine
		fscanf(users_file, "%s[10]", user_struct->deadLine);
		// drop line
		fgets(buffer, 256, users_file);



		printf("id %ld\n", user_struct->id);
		printf("name %s\n", user_struct->name);
		printf("level %d\n", user_struct->level);
		printf("project_id %d\n", user_struct->porj_id);
		printf("task_id %d\n", user_struct->task_id);
		printf("lengauge %s\n", user_struct->lang);
		printf("salary %d\n", user_struct->salery);
		printf("online %d\n", user_struct->online);
		printf("comments %s\n", user_struct->coments);
		printf("deadLine %s\n", user_struct->deadLine);		
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

