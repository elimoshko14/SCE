bool unitTestUser() {
	printf("----------- Add, delete, update User -----------\n\n");
	
	for (int i=2; i<=4; i++) 
		addUser(i,"User", "EN", "12.01.2017");
	
	getUsers();
	unSetUser(2);
	printUserTree();

	return true;
}