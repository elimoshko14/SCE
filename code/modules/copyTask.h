void copyTask() {
	int copy_id;
		if (tasks_list) {
			printf("%s\n", i18("Please enter the ID of the task you wish to copy"));
			copy_id = getInt();
			task *tmpT = findTaskById(copy_id);
			if (tmpT) {
				addTask(++unique_task_key, tmpT->title, 0, tmpT->category_id, tmpT->cost, tmpT->status, tmpT->tags, tmpT->due, "");
				printf("%s",i18("Task has been copy ID To back press enter"));
				getchar(); 
				getchar();
			}
			else
			{
				printf("%s\n",i18("There is no task with this ID"));
		}
	}
}
