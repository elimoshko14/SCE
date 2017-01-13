bool unitTestLogin() {
	// Every module should be independent as posible
	// that means we need to provide all the data it needs, without counting on any 
	// "state" the program is in

	// We dont have a db to count on?
	if (!users_list) {
		// create a user list
		// add a user

		// create 2 users (1 is not enought to use the findUserById func
		// ---------------
		// copy pase to create a user
		struct user * tmp_user = (struct user *)malloc(sizeof(struct user));
		// copy past only the fields we actually need
		tmp_user->id = 1;
		// http://stackoverflow.com/questions/16645583/how-to-copy-char-array-to-another-char-array-in-c
		strcpy(tmp_user->name,"Arie Katz");
		tmp_user->level = 1;
		strcpy(tmp_user->lang, "EN");
		// not online, yet
		tmp_user->online = 0;


		// add it to the list
		pushUser(tmp_user);

		// copy pase to create a user
		tmp_user = (struct user *)malloc(sizeof(struct user));
		// copy past only the fields we actually need
		tmp_user->id = 2;
		// http://stackoverflow.com/questions/16645583/how-to-copy-char-array-to-another-char-array-in-c
		strcpy(tmp_user->name,"Roma");
		tmp_user->level = 3;
		strcpy(tmp_user->lang, "RU");
		tmp_user->online = 0;


		// add it to the list
		pushUser(tmp_user);
		// ---------------

		// all the data is here! the rest is done by the login function!
	}
	// login doent realy need's an input var, we need it for testing
	user_ptr = login(123456789);
	if (user_ptr) {
		printf("\n----------- Logged in user -----------\n");
		printUser(user_ptr);
		return true;
	}
	printf("ERROR!\nuser_ptr is NULL!\n");
	return false;
}

