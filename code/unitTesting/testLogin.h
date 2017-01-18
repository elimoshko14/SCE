bool unitTestLogin() {
	// Every module should be independent as posible
	// that means we need to provide all the data it needs, without counting on any 
	// "state" the program is in

	// We dont have a db to count on?
	if (!users_list) {
		//
		addUser(1, "Arie Katz", "EN", "String");
		addUser(2, "Eli", "EN", "String");
		addUser(3, "Chen", "EN", "String");
		addUser(4, "Roma", "EN", "String");
	
	}
	// login doent realy need's an input var, we need it for testing
	user_ptr = login(1);
	if (user_ptr) {
		printf("\n----------- Logged in user -----------\n");
		printUser(user_ptr);
		return true;
	}
	printf("ERROR!\nuser_ptr is NULL!\n");
	return false;
}

