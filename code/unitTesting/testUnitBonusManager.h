bool unitTestBonusManager() {
	proj* p = (proj*)malloc(sizeof(proj*));
	strcpy(p->cats_arr ,"-1");
	p->cost = 1234;
	strcpy(p->due ,"1234567890");
	p->id = 1;
	p->manager_id = 1;
	strcpy(p->name, "chen");
	p->status = 1;
	strcpy(p->tasks_arr, "-1");
	strcpy(p->users_arr, "-1");
	
	manager_bonus(p);
	printProj(p);

	return true;
}