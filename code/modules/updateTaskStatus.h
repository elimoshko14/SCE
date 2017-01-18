void updateTaskStatus() {
	task_node *tL = tasks_list;
	while (tL != NULL) {
		if (tL->ptr->status != 1) {
			//printTask(tL->ptr);
			printf("enter 1 for change status of task\nor else enter 0 to display next task\n");
			int x;
			scanf("%d", &x);
			
			if (x)
				updateTask(tL->ptr->id, 
					tL->ptr->title, 
					tL->ptr->user_id, 
					tL->ptr->category_id, 
					tL->ptr->cost, 1, 
					tL->ptr->tags, 
					tL->ptr->due, 
					tL->ptr->comments);
		}
		tL = tL->next;
	}
}
