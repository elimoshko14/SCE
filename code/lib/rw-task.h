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

		for (int dataLine = 0; dataLine < 8; dataLine++) {
			char buffer[256];
			// get id
			fscanf(tasks_file, "%d", &(task_struct->id));
			// end line
			fgets(buffer, 256, tasks_file);
			

			// get title
			fgets(task_struct->title, '256', tasks_file);
			// clear \n
			strtok(task_struct->title, "\n");


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
			fscanf(tasks_file, "%d", &(task_struct->status));
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get tags array (strings)
			fscanf(tasks_file, "%s", task_struct->tags);
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get tags array (strings)
			fscanf(tasks_file, "%s", task_struct->deadLine);
			// drop line
			fgets(buffer, '\n', tasks_file);

			// get tags array (strings)
			fscanf(tasks_file, "%s", task_struct->tags);
			// drop line
			fgets(buffer, '\n', tasks_file);
			
			// get tags array (strings)
			fscanf(tasks_file, "%s", task_struct->tags);
			// drop line
			fgets(buffer, '\n', tasks_file);
			
			// get comments array (strings)
			fscanf(tasks_file, "%s", task_struct->comments);
			// drop line
			fgets(buffer, '\n', tasks_file);


			printf("id %ld\n", task_struct->id);
			printf("title %s\n", task_struct->title);
			printf("user_id %ld\n", task_struct->user_id);
			printf("category_id %d\n", task_struct->category_id);
			printf("cost %d\n", task_struct->cost);
			printf("status %d\n", task_struct->status);
			printf("tags %s\n", task_struct->tags);
			printf("deadLine %s\n", task_struct->deadLine);
			printf("comments %s\n", task_struct->comments);

			system("pause");
		}
	}

	fclose(tasks_file);
}
