void displayProjects() {
	system("cls");
	if (projects_list != NULL) {
		printProjTree();
	}
	else {
		printf("%s\n", errors[0][2]);
	}

	printf("To Back press [0]");
	int t = getInt();
}