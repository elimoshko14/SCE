bool unitTestAddProj() {
	printf("----------- Add Project -----------\n\n");
	
	addProjs();

	printProjTree();
	if (!projects_list)
		printf("ERROR!\nprojects_list is NULL!\n");
}

