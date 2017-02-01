void displayProjects() {
	
	if (projects_list != NULL) {
		printProjTree();
	}
	else {
		printf("%s\n", i18("Projects List is empty"));
	}

	printf("%s",i18("To Back press [0]"));
	int t = getInt();
}