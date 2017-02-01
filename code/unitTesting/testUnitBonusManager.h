bool unitTestBonusManager() {
	addProj(1000, "Test Proj", 1, 150000, "2/10/2020");
	proj * p = findProjById(1000);
	if (p == NULL) {
		printf("ERROR\n");
		return false;
	}
	printUser(findUserById(p->manager_id));
	manager_bonus(p);
	printUser(findUserById(p->manager_id));
	unSetProj(p->id);
	return true;
}