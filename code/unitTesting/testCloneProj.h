bool unittestCloneProj() {
	printf("----------- Test Clone project -----------\n\n");
	if (projects_list) {
		printf("1. All projects  in list\n");
		printProjTree();

		proj * tmpP = findProjById(1);
		addProj(++unique_project_key, tmpP->name, tmpP->manager_id, tmpP->cost, tmpP->due);

		printf("2. All projects  in list\n");
		printProjTree();

	}
	else
		return false;
	return true;
}