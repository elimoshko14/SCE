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

void worker_bonus(user *Un)
{
	if(strstr(Un->due,"#")==NULL)
		updateUser(Un->id, Un->name, Un->lang, Un->due, Un->level, Un->porj_id, Un->task_id, Un->salery*1.1, Un->online, Un->coments);
}

void rejectTask() {
	task *tmpT = findTaskById(user_ptr->task_id);
	updateTask(tmpT->id, tmpT->title, tmpT->user_id, tmpT->category_id, tmpT->cost, tmpT->status, tmpT->tags, "#", tmpT->comments);
	printf("Your request to reject  task has been send to manager\nPress Enter to back");
	getchar();
	getchar();
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
			updateTask(tmpT->id, tmpT->title, user_ptr->id, tmpT->category_id, tmpT->cost, 1, tmpT->tags, "*22/01/2017", tmpT->comments);
			manager_bonus(findProjById(user_ptr->porj_id));
			worker_bonus(findUserById(tmpT->user_id));
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