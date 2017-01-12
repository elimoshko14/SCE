void unitTestGetDbs() {
	printf("########## TASKS #########\n");
	getTasks();
	printTaskTree();
	printf("########## USERS #########\n");
	getUsers();
	printUserTree();
	printf("########## Categories #########\n");
	getCategories();
	printCatTree();
	printf("########## Project #########\n");
	getProjs();
	printProjTree();
	printf("########## Comments #########\n");
	getComments();
	printComentTree();
}