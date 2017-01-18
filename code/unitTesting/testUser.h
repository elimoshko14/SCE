bool unitTestUser() {
	printf("----------- Add, delete, update User -----------\n\n");
	
	for (int i=2; i<=4; i++) 
		addUser(i, "Dikaprio", "EN", "String", 3, 1, 1, 10000, 1, "-1");
	
	getUsers();
	unSetUser(2);
	printUserTree();

	return true;
}