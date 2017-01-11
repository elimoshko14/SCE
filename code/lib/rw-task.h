void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (tasks_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct task * task_struct = (struct task *)malloc(sizeof(struct task));

		char buffer[256];

		fscanf(tasks_file, "%d", &(task_struct->id));
		fgets(buffer, 256, tasks_file);
		
		fgets(task_struct->title, '256', tasks_file);
		strtok(task_struct->title, "\n");

		fscanf(tasks_file, "%ld", &(task_struct->user_id));
		fgets(buffer, '\n', tasks_file);


		fscanf(tasks_file, "%d", &(task_struct->category_id));
		fgets(buffer, '\n', tasks_file);


		fscanf(tasks_file, "%d", &(task_struct->cost));
		fgets(buffer, '\n', tasks_file);


		fscanf(tasks_file, "%d", &(task_struct->status));
		fgets(buffer, '\n', tasks_file);

		fscanf(tasks_file, "%s", task_struct->tags);
		fgets(buffer, '\n', tasks_file);
			
		fscanf(tasks_file, "%s", task_struct->deadLine);
		fgets(buffer, '\n', tasks_file);
			
		fscanf(tasks_file, "%s", task_struct->comments);
		fgets(buffer, '\n', tasks_file);
		strtok(task_struct->comments, "\n");


		printf("id %ld\n", task_struct->id);
		printf("title %s\n", task_struct->title);
		printf("user_id %ld\n", task_struct->user_id);
		printf("category_id %d\n", task_struct->category_id);
		printf("cost %d\n", task_struct->cost);
		printf("status %d\n", task_struct->status);
		printf("tags %s\n", task_struct->tags);
		printf("deadLine %s\n", task_struct->deadLine);
		printf("comments %s\n", task_struct->comments);
		printf("-------------\n");

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(tasks_file);
		ungetc(ch, tasks_file);

	} while (!feof(tasks_file) && ch != EOF);

	fclose(tasks_file);
}
