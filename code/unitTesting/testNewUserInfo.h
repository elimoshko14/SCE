bool unitTestNewUserInfo() {
	printf("----------- Test New User -----------\n\n");

	int id = ++unique_user_key;
	addUser(id, "Test User", "EN", "1234", 3, 1, 0, 10000, 0, "-1");
	user *tmpU = findUserById(id);
	if (tmpU) {
		printf("\nNew user info:\n");
		printUser(tmpU);
		printf("\nUsers List:\n");
		printUserTree(users_list);
		unSetUser(id);
	}
	else
		return false;

	return true;
}