bool unitTestGetDbs() {

	printf("----------- TASKS -----------\n");
	getTasks();
	printTaskTree();
	if (!tasks_list) 
		printf("\nERROR!\ntasks_list is NULL!\n");

	printf("----------- USERS -----------\n");
	getUsers();
	printUserTree();
	if (!users_list)
		printf("ERROR!\nusers_list is NULL!\n");


	printf("----------- Categories -----------\n");
	getCategories();
	printCatTree();
	if (!categories_list)
		printf("ERROR!\ncategories_list is NULL!\n");


	printf("----------- Project -----------\n");
	getProjs();
	printProjTree();
	if (!projects_list)
		printf("ERROR!\nprojects_list is NULL!\n");


	printf("----------- Comments -----------\n");
	getComments();
	printComentTree();
	if (!comments_list)
		printf("ERROR!\ncomments_list is NULL!\n");

	return true;
}