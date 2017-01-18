bool unitTestLogin() {
	// Every module should be independent as posible
	// that means we need to provide all the data it needs, without counting on any 
	// "state" the program is in

	// We dont have a db to count on?
	if (!users_list) {
		//
		addUser(1, "Bendjamin ", "EN", "String", 1,1,1,10000,1,"-1");
		addUser(2, "Ruzvelt", "EN", "String", 2, 1, 1, 10000, 1, "-1");
		addUser(3, "Stalone", "EN", "String", 2, 1, 1, 10000, 1, "-1");
		addUser(4, "Dikaprio", "EN", "String", 3, 1, 1, 10000, 1, "-1");
	
	}
	// login doent realy need's an input var, we need it for testing
	user_ptr = login(1);
	if (user_ptr) {
		printf("\n----------- Logged in user -----------\n");
		printUser(user_ptr);

		// temp test
		mainMenu();
		getTasks();
		// end test

		return true;
	}
	printf("ERROR!\nuser_ptr is NULL!\n");
	return false;
}

