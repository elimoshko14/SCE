bool unittestPrintProj() {
	printf("----------- Test print Project -----------\n\n");
	
	if (projects_list)
		printProjTree();

	else
		return false;

	return true;
}