
void getProjects() {
	FILE * proj_ptr;
	char filename[] = "db/projects.txt";
	proj_ptr = fopen(filename, "r");
	if (proj_ptr == NULL) {
		perror("Error");
		return ;
	}
	while (!feof(proj_ptr)) {
		struct proj * proj_node = (struct proj *)malloc(sizeof(proj));
		
		
	}
	fclose(proj_ptr);
}