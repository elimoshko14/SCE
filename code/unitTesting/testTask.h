bool unitTestTask() {
	printf("----------- Add, delete, update Task -----------\n\n");
	addTask(1, "Tets Task", 1, 1, 100, 1, "Tags Tags", "20.01.2017", "-1");
	printTaskTree();
	return true;
}