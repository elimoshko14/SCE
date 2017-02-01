bool unitTestDue() {
	// create a task for testing 
	addTask(123, "test", 0, 1, 1500, 0, "Important!", "12/2/2017", "1,2,10");
	updateTask(123, "test", 0, 1, 1500, 0, "Important!", "#", "1,2,10");

	printf("Task dued successfully\n");
	return true;
}