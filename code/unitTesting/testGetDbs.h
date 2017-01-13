bool unitTestGetDbs() {

	printf("----------- TASKS -----------\n\n");
	getTasks();
	printTaskTree();
	if (!tasks_list) 
		printf("\nERROR!\ntasks_list is NULL!\n");

	printf("----------- USERS -----------\n\n");
	getUsers();
	printUserTree();
	if (!users_list)
		printf("ERROR!\nusers_list is NULL!\n");


	printf("----------- Categories -----------\n\n");
	getCategories();
	printCatTree();
	if (!categories_list)
		printf("ERROR!\ncategories_list is NULL!\n");


	printf("----------- Project -----------\n\n");
	getProjs();
	printProjTree();
	if (!projects_list)
		printf("ERROR!\nprojects_list is NULL!\n");


	printf("----------- Comments -----------\n\n");
	getComments();
	printComentTree();
	if (!comments_list)
		printf("ERROR!\ncomments_list is NULL!\n");

	return true;
}