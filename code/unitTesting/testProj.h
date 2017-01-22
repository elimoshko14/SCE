bool unitTestProj() {
	printf("----------- Add, delete, update Project -----------\n\n");

	for (int i = 2; i <= 4; i++)
		addProj(i,"Proj 1", 1000*i,1500, "12.01.2017");

	getProjs();
	unSetProj(2);
	printProjTree();
	return true;
}