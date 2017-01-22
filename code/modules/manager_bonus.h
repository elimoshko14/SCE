void manager_bonus(proj* p) {
	task_node* tmp = tasks_list;
	int count = 0,sum=0;
	while (tmp!=NULL)
	{
		user *u = findUserById(tmp->ptr->user_id);
		if (u->porj_id == p->id)
		{
			if ((tmp->ptr->status) == 1)
			{
				if(strstr(tmp->ptr->due, "#")!=NULL)
					count++;
				sum++;
			}
			else
				break;
		}
		tmp=tmp->next;
	}
	user * tmpU;
	if (count >= sum / 2)
	{
		tmpU = findUserById(p->manager_id);
		updateUser(tmpU->id, tmpU->name, tmpU->lang, tmpU->due, tmpU->level, tmpU->porj_id, tmpU->task_id, tmpU->salery*1.5, tmpU->online, tmpU->coments);
	}
}