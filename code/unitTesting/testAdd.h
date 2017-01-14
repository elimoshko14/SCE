bool unitTestAddProj() {
	printf("----------- Add Project -----------\n\n");
	addProj(); 
	printProjTree();
}

bool unitTestAddUser() {
	printf("----------- Add User -----------\n\n");
	addUser();
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
	unitTestAddProj();
	unitTestAddCat();
	unitTestAddTask();
	unitTestAddComment();
	unitTestAddUser();
}