bool unitTestUpdateTask() {
	printf("----------- Test Update Task -----------\n\n");

	
	task * tmp = findTaskById(1);
	if (tmp != NULL) {
		printf("\nTask before update:\n");
		printTask(tmp); 

		updateTask(tmp->id, "Task 2", tmp->user_id, tmp->category_id, 12300, 0, "New tags, New", "12/10/2015", tmp->comments);

		printf("\nTask after update:\n");
		printTask(tmp);

		updateTask(tmp->id, "Simple Task", tmp->user_id, tmp->category_id, 1000, 0, "Test, tags", "10/01/2016", tmp->comments);
	}
	else 
		return false;
	

	return true;
}