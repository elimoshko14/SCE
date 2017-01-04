void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (tasks_file == NULL) {
		perror("Error");
		return;
	}

	while (!feof(tasks_file)) {
		struct tasks * task_node = (struct tasks *)malloc(sizeof(struct tasks));
		fscanf(tasks_file, "%ld|%[a-zA-Z0-9 ]*|$", &(task_node->id), task_node->title);
		printf("%ld, %s", task_node->id, task_node->title);
	}

	fclose(tasks_file);
}
