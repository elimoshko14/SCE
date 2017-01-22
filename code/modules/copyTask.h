void copyTask() {
	int copy_id;
		if (tasks_list) {
			printf("Please enter the ID of the task you wish to copy\n");
			copy_id = getInt();
			task *tmpT = findTaskById(copy_id);
			if (tmpT) {
				addTask(++unique_task_key, tmpT->title, 0, tmpT->category_id, tmpT->cost, tmpT->status, tmpT->tags, tmpT->due, "");
				printf("Task has been copy ID\nTo back press enter");
				getchar(); 
				getchar();
			}
			else
			{
				printf("There is no task with this ID\n");
		}
	}
}
