
void CopyProj() {
	int copy_id;
	if (projects_list) {
		printf("%s\n",i18("Please enter the ID of the Proj you wish to copy"));
		copy_id = getInt();
		proj *tmpT = findProjById(copy_id);
		if (tmpT) {
			addProj(++unique_project_key, tmpT->name, tmpT->manager_id, tmpT->cost, tmpT->due);
			category_node * tmp_c = categories_list;
			task_node * tmp_t = tasks_list;
			comment_node *tmp_comm = comments_list;
			while (tmp_c != NULL) {
				if (tmp_c->ptr->proj_id == copy_id) {
					addCat(++unique_category_key, tmp_c->ptr->name, unique_project_key, tmp_c->ptr->comment_arr);
					while (tmp_t != NULL) {
						if (tmp_t->ptr->category_id == tmp_c->ptr->id) {
							addTask(++unique_task_key, tmp_t->ptr->title, 0, unique_category_key, tmp_t->ptr->cost, tmp_t->ptr->status, tmp_t->ptr->tags, tmp_t->ptr->due, tmp_t->ptr->comments);

							while (tmp_comm != NULL) {
								if (tmp_comm->ptr->task_id == tmp_t->ptr->id) {
									addComment(++unique_comment_key, tmp_comm->ptr->title, tmp_comm->ptr->body, unique_project_key, unique_task_key, 0);
								}
								tmp_comm = tmp_comm->next;
							}
						}
						tmp_t = tmp_t->next;
					}
				}
				tmp_c = tmp_c->next;
			}

		}
		else
		{
			printf("%s\n", i18("There is no Proj with this ID\n"));
		}
	}
}
