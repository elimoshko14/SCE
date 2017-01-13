bool unitTestUserUpdate() {
	printf("----------- Update User -----------\n\n");
	
	UpdateUser(305327223);
	printUserTree();
	if (!users_list)
		printf("ERROR!\nusers_list is NULL!\n");
	
}

