void management_projets() {
	printf("emter 1 for Add project:\n");
	printf("enter 2 for Update project:\n");
	printf("enter 3 for Delete project:\n");
	int x;
	scanf("%d", &x);
	if (x == 1)
	{
		int id, manId, cost;
		char due[256];
		printf("enter id project, manager id, cost of project:\n");
		scanf("%d%d%d", &id, &manId, &cost);
		printf("enter deadline of project\n");
		scanf("%s", due);
		if (findProjById(id) == NULL)
			if ((findUserById(manId) != NULL) && (findUserById(manId)->level == 2))
				addProj(id, manId, cost, due);
			else {
				printf("Error: User not exist or this is user is not manager\n");
			}
		else {
			printf("Error: Project with this id is allready exist\n");
		}
	}

	else if (x == 2)
	{

	}
	else {//need fixt it
		int id;
		proj *tP;
		printProjTree();
		printf("enter id of proj that you want to change:\n ");
		scanf("%d", &id);
		tP = findProjById(id);
		if (tP != NULL)
		{

		}
	}
}