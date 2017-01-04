void setNodeFromLine(struct task ** node, char * line) {
	char ch;
	// get ID
	do {
		ch = getch(line);

	} while (ch != '|');

	// move over the next |
	getc(line);

	// get title
}

void getTasks() {

	FILE * tasks_file;
	char filename[] = "db/tasks.txt";
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
		setNodeFromLine(&task_node, line);
		free(line);
	}
}
