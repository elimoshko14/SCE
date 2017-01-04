void setTaskFromLine(struct task ** node, char * line) {
	
	// get ID
	for (unsigned int ch = 0; line[ch] != '|' && line[ch + 1] != '|' && ch < strlen(line); ch++) {
		printf("%c", line[ch]);
	}

	// get title
}

void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (tasks_file == NULL) {
		perror("Error");
		return;
	}

	while (!feof(tasks_file)) {
		struct task * task_node = (struct task *)malloc(sizeof(task));
	
		const size_t line_size = 300;
		char* line = malloc(line_size);
		fgets(line, line_size, tasks_file);
		setTaskFromLine(&task_node, line);
		free(line);
	}

	fclose(tasks_file);
}
