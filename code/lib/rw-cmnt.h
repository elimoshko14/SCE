void getComments() {

	FILE * coments_file;
	char filename[] = "../db/comments.txt";
	coments_file = fopen(filename, "r");

	if (coments_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct comment * coment_struct = (struct comment *)malloc(sizeof(struct comment));

		char buffer[256];
		// get id
		fscanf(coments_file, "%ld", &(coment_struct->id));
		// drop line
		fgets(buffer, 256, coments_file);

		// get title
		fgets(coment_struct->title, '256', coments_file);
		// clear \n
		strtok(coment_struct->title, "\n");

		// get body
		fgets(coment_struct->body, '256', coments_file);
		// clear \n
		strtok(coment_struct->body, "\n");

		// get proj id
		fscanf(coments_file, "%d", &(coment_struct->porj_id));
		// drop line
		fgets(buffer, 256, coments_file);

		// get task id
		fscanf(coments_file, "%d", &(coment_struct->task_id));
		// drop line
		fgets(buffer, 256, coments_file);

		// get user id
		fscanf(coments_file, "%d", &(coment_struct->user_id));
		// drop line
		fgets(buffer, 256, coments_file);



		printf("id %ld\n", coment_struct->id);
		printf("title %s\n", coment_struct->title);
		printf("body %s\n", coment_struct->body);
		printf("project_id %d\n", coment_struct->porj_id);
		printf("task_id %d\n", coment_struct->task_id);
		printf("user_id %d\n", coment_struct->user_id);
		printf("-------------\n");

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(coments_file);
		ungetc(ch, coments_file);

	} while (!feof(coments_file) && ch != EOF);

	fclose(coments_file);
}

