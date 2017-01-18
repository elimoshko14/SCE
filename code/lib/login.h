// the login function will check if a provided id is
// in the system (user_list)

user * login(int user_id) {
	// if not testing, we need to get input from user
	if (user_id == -1) {
		long id;

		printf("Welcome!\n");
		printf("Please enter Your ID: \n");
		scanf("%ld", &id);
		while (!isdigit(id)) {
			printf("Invalid input, please try again\n");
			scanf("%ld", &id);
		}
	}
	else {
		// user_id is a test value
		// lets try to find it
		user * tmp_user_node = findUserById(user_id);
		// if we did not find it, we can show error, but no way to know if func is broken
		// or the user is not in system
		if (!tmp_user_node) {
			// show error
		}
		else {
			tmp_user_node->online = true;
			// return it
			return tmp_user_node;
		}
	}

	return NULL;
}