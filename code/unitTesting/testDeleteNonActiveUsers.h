bool testDeleteNonActiveUsers() {
	printf("----------- Test Delete Non Active Users -----------\n\n");

	printf("1. All users in system\n");

	addUser(++unique_user_key, "Test User", "EN", "1234", 3, 1, 0, 1000, 0, "-1");
	addUser(++unique_user_key, "Test User 2", "EN", "1234", 3, 1, 0, 1000, 0, "-1");
	printUserTree();

	printf("2. Remove all non active users\n");
	user_node *t = users_list;
	user_node *tmp = users_list;
	while (t) {
		t = t->next;
		if (tmp->ptr->task_id == 0) {
			unSetUser(tmp->ptr->id);
		}
		tmp = t;
	}
	printUserTree();

	return true;
}