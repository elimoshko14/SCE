// the login function will check if a provided id is
// in the system (user_list)

user * login(int user_id, char * pass) {
	// if not testing, we need to get input from user
	if (user_id == -1) {
		// get input from user
	}
	else {
		// user_id is a test value
		// lets try to find it
		user * tmp_user_node = findUserById(user_id);
		// if we did not find it, we can show error, but no way to know if func is broken
		// or the user is not in system
		if (!tmp_user_node) {
			printf("ID not found\n");
			system("pause");
			return NULL;
		}


		printf("%s\n", tmp_user_node->password);

		if (strcmp(tmp_user_node->password, pass) == 0){
			tmp_user_node->online = true;
			// return it
			return tmp_user_node;
		}
		printf("ERROR\n");
		system("pause"); 
		return NULL;
	}

	return NULL;
}