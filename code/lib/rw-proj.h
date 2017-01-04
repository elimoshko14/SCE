void setProjFromLine(struct task ** node, char * line) {
	char ch;
	// get ID
	do {
		ch = getch(line);

	} while (ch != '|');

	// move over the next |
	getch(line);

	// get title
}

void getProjects() {
	FILE * proj_file;
	char filename[] = "db/projects.txt";
	proj_file = fopen(filename, "r");

	if (proj_file == NULL) {
		perror("Error");
		return;
	}

	while (!feof(proj_file)) {
		struct task * task_node = (struct task *)malloc(sizeof(task));
		const size_t line_size = 300;
		char* line = malloc(line_size);
		fgets(line, line_size, proj_file);
		setProjFromLine(&task_node, line);
		free(line);
	}
	fclose(proj_file);
}