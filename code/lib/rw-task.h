void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (tasks_file == NULL) {
		perror("Error");
		return;
	}


	/*******************************/
	/// GET DATA FROM FILE //
	while (!feof(tasks_file)) {
		struct task * task_struct = (struct task *)malloc(sizeof(struct task));

		for (int dataLine = 0; dataLine < 5; dataLine++) {
			char buffer[256];
			// get id
			fscanf(tasks_file, "%d", &(task_struct->id));
			// end line
			fgets(buffer, '\n', tasks_file);

			// get title
			fgets(task_struct->title, '\n', tasks_file);

			// get user id
			fscanf(tasks_file, "%ld", &(task_struct->user_id));
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get cat id
			fscanf(tasks_file, "%d", &(task_struct->category_id));
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get cost
			fscanf(tasks_file, "%d", &(task_struct->cost));
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get status
			fgets(task_struct->status, '\n', tasks_file);

			// get tags array (strings)
			fscanf(tasks_file, "%s", task_struct->tags);
			// drop line
			fgets(buffer, '\n', tasks_file);

			

			printf("%d\n", task_struct->id);
			printf("%s\n", task_struct->title);
			system("pause");
		}
	}

	fclose(tasks_file);
}
