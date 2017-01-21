void project_info() {
	proj *tmpP = findProjById(user_ptr->porj_id);
	printProj(tmpP);
	printf("Press Enter to continue");
	getchar();
	getchar();

}
void myTask() {
	task *tmpT = findTaskById(user_ptr->task_id);
	if (tmpT) {
		printTask(tmpT);
		printf("Back to menu Press Enter");
		getchar();
		getchar();
	}
	else {
		printf("Now you don't have a task to do");
		printf("\nBack to menu Press Enter");
		getchar();
		getchar();

	}
}
void completeTask() {
	task *tmpT = findTaskById(user_ptr->task_id);
	if (tmpT) {
		if (tmpT->status == 1) {
			printf("Your task is completed\nBack to menu Press Enter");
			getchar();
			getchar();
		}
		else {
			updateTask(tmpT->id, tmpT->title, user_ptr->id, tmpT->category_id, tmpT->cost, 1, tmpT->tags, "#22/01/2017", tmpT->comments);
			printf("Very nice manager will check your task and give you another\nBack to menu Press Enter");
			getchar();
			getchar();
		}
	}
	else {
		printf("Now you don't have a task to do");
		printf("\nBack to menu Press Enter");
		getchar();
		getchar();

	}
}