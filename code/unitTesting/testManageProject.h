bool unitTestManageProject() {
	printf("----------- Test Manage Project -----------\n\n");

	printf("1. All projects:\n");
	printProjTree();

	printf("2. Add new project\n");
	addProj(++unique_project_key, "Test project", 0, 10000, "12/12/2012");
	printProjTree();
	
	printf("3. Update project\n");
	updateProj(unique_project_key, "UTest project", 0, "19/10/2014", 0, 15000);
	printProjTree();

	printf("4. Delete project\n");
	unSetProj(unique_project_key);
	printProjTree();

	return true;
}