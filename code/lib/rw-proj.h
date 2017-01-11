void getProjs() {

	FILE * proj_file;
	char filename[] = "../db/projects.txt";
	proj_file = fopen(filename, "r");

	if (proj_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct proj * proj_struct = (struct proj *)malloc(sizeof(struct proj));

		char buffer[256];
		// get user arr
		fscanf(proj_file, "%s", (proj_struct->users_arr));
		// end line
		fgets(buffer, 256, proj_file);
		// get tasks_arr
		fscanf(proj_file, "%s", proj_struct->tasks_arr);
		// end line
		fgets(buffer, 256, proj_file);
		// get cats_arr
		fscanf(proj_file, "%s", proj_struct->cats_arr);
		// drop line
		fgets(buffer, 256, proj_file);
		// get manager_id
		fscanf(proj_file, "%d", &(proj_struct->manager_id));
		// drop line
		fgets(buffer, 256, proj_file);
		// get finish_date
		fscanf(proj_file, "%s", proj_struct->due);
		// drop line
		fgets(buffer, 256, proj_file);
		// get status
		fscanf(proj_file, "%d", &(proj_struct->status));
		// drop line
		fgets(buffer, 256, proj_file);
		// get cost
		fscanf(proj_file, "%d", &(proj_struct->cost));
		// drop line
		fgets(buffer, 256, proj_file);
		

		printf("Users Array:\t%s\n", proj_struct->users_arr);
		printf("Tasks Array:\t%s\n", proj_struct->tasks_arr);
		printf("Categories Array:\t%s\n", proj_struct->cats_arr);
		printf("Manager ID:\t%d\n", proj_struct->manager_id);
		printf("Due:\t%s\n", proj_struct->due);
		printf("Status\t%d\n", proj_struct->status);
		printf("Cost:\t%d\n", proj_struct->cost);
		printf("-------------\n");

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(proj_file);
		ungetc(ch, proj_file);

	} while (!feof(proj_file) && ch != EOF);

	fclose(proj_file);
}
