bool unitTestGetDbs() {

	printf("\n----------- Project -----------\n\n");
	printProjTree();
	if (!projects_list)
		printf("ERROR!\nprojects_list is NULL!\n");

	printf("\n----------- Categories -----------\n\n");
	printCatTree();
	if (!categories_list)
		printf("ERROR!\ncategories_list is NULL!\n");

	printf("\n----------- Tasks -----------\n\n");
	printTaskTree();
	if (!tasks_list)
		printf("\nERROR!\ntasks_list is NULL!\n");

	printf("\n----------- Comments -----------\n\n");
	printComentTree();
	if (!comments_list)
		printf("ERROR!\ncomments_list is NULL!\n");


	printf("----------- Users -----------\n\n");
	printUserTree();
	if (!users_list)
		printf("ERROR!\nusers_list is NULL!\n");

	return true;
}