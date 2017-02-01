bool unitTestSerch() {
	printf("-----------Serch test!!!! -----------\n\n");
	
	printf("\n----------- Serch Categories -----------\n\n");
	if (findCatById(1))
		printf("category has been found");
    if (!findCatById(99999))
	 printf("\nERROR!\n Categories not found!\n");

	printf("\n-----------Serch Tasks -----------\n\n");
	if (findTaskById(1))
		printf("Task has been found");
	if (!findTaskById(99999))
		printf("\nERROR!\n Task not found!\n");

	printf("-----------Serch Users -----------\n\n");
	if(findUserById(1))
		printf("user has been found");
	if (!findUserById(99999))
		printf("\nERROR!\n User not found!\n");

	printf("\n-----------Serch Projects -----------\n\n");
	if(findCatById(1))
		printf("Project has been found");
	if (!findCatById(99999))
		printf("\nERROR!\n Project not found!\n");

	printf("\n-----------Serch Comments -----------\n\n");
	if(findcomentById(1))
		printf("Comment has been found");
	if (!findcomentById(99999))
		printf("\nERROR!\n Comment not found!\n");


	return true;
}