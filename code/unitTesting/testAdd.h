bool unitTestAddProj() {
	printf("----------- Add Project -----------\n\n");
	addProj(); 
	printProjTree();
}

bool unitTestAddUser() {
	printf("----------- Add, delete User -----------\n\n");
	
	//for (int i=2; i<=4; i++) 
	//	addUser(i,"User", "EN", "12.01.2017");
	
	getUsers();
	unSetUser(2);
	printUserTree();
}

bool unitTestAddCat() {
	printf("----------- Add Category -----------\n\n");
	addCat();
	printCatTree();
}

bool unitTestAddTask() {
	printf("----------- Add Task -----------\n\n");
	addTask();
	printTaskTree();
}

bool unitTestAddComment() {
	printf("----------- Add Task -----------\n\n");
	addComment();
	printComentTree();
}

bool unitTestAdd() {
	//unitTestAddProj();
	//unitTestAddCat();
	//unitTestAddTask();
	//unitTestAddComment();
	unitTestAddUser();
}