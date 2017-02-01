bool testPrintProjWorker()
{
	user* u= findUserById(1);
	proj* p = findProjById(u->id);
	printProj(p);
}