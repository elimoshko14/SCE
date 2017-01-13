bool unitTestAddProj() {
	printf("----------- Add Project -----------\n\n");
	
	
	struct proj * proj_struct = (struct proj *)malloc(sizeof(struct proj));

	printf("Enter id: ");
	scanf("%d", &(proj_struct->id));
	while (findProjById(proj_struct->id) != NULL) {
		printf("Error details, try again/n");
		scanf("%d", &(proj_struct->id));
	}
	

	/*printf("Enter: manager id: /n");
	scanf("%d", &proj_struct->manager_id);
	user *tmp = findUserById(proj_struct->manager_id);
	while (true) {
	if ((tmp != NULL) && (tmp->level == 2))
	break;
	else {
	printf("Error manager id incorrect/n");
	scanf("%d", &proj_struct->manager_id);
	tmp = findUserById(proj_struct->manager_id);
	}
	}*/
	printf("Enter deadline and cost of project:/n");
	scanf("%s%d", proj_struct->due, &(proj_struct->cost));
	

	//just for test
	proj_struct->manager_id = 305327223;
	// project information is empty for  new project
	strcpy(proj_struct->users_arr, "-1");
	strcpy(proj_struct->tasks_arr, "-1");
	strcpy(proj_struct->cats_arr, "-1");
	proj_struct->status = 0;

	//printProj(proj_struct);
	pushProj(proj_struct);
	setProjs(proj_struct);
	
	printProjTree();
	if (!projects_list)
		printf("ERROR!\nprojects_list is NULL!\n");
}

