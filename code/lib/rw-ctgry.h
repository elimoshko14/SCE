void getCategories() {

	FILE * categorys_file;
	char filename[] = "../db/categorys.txt";
	categorys_file = fopen(filename, "r");

	if (categorys_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct category * category_struct = (struct category *)malloc(sizeof(struct category));

		char buffer[256];
		// get id
		fscanf(categorys_file, "%ld", &(category_struct->id));
		// drop line
		fgets(buffer, 256, categorys_file);

		// get name
		fgets(category_struct->name, '256', categorys_file);
		// clear \n
		strtok(category_struct->name, "\n");
		// get proj id
		fscanf(categorys_file, "%d", &(category_struct->proj_id));
		// drop line
		fgets(buffer, 256, categorys_file);

		// get coments array (strings)
		fscanf(categorys_file, "%s", category_struct->comment_arr);
		// drop line
		fgets(buffer, 256, categorys_file);
		// clear \n
		strtok(category_struct->comment_arr, "\n");


		printf("ID:\t%ld\n", category_struct->id);
		printf("Name:\t%s\n", category_struct->name);
		printf("Project ID:\t%d\n", category_struct->proj_id);
		printf("Comments:\t%s\n", category_struct->comment_arr);
		printf("-------------\n");

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(categorys_file);
		ungetc(ch, categorys_file);

	} while (!feof(categorys_file) && ch != EOF);

	fclose(categorys_file);
}

