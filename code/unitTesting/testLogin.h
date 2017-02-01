bool unitTestLogin() {
	// Every module should be independent as posible
	// that means we need to provide all the data it needs, without counting on any 
	// "state" the program is in	
	// login doent realy need's an input var, we need it for testing
	user_ptr = login(1,"1234");
	if (user_ptr) {
		printf("\n----------- Logged in user -----------\n");
		printUser(user_ptr);
		user_ptr = NULL;
		return true;
	}
	printf("ERROR!\nuser_ptr is NULL!\n");
	return false;
}