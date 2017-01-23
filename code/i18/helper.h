#define LEN 1000

char MANAG_PROJECT[LEN];
char MANAG_USERS[LEN];





void changeLang() {

	if (!user_ptr) {
		strcpy(MANAG_PROJECT, "Manage projects");
	}
	else {
		if (strcmp(user_ptr->lang, "EN")== 0){
			strcpy(MANAG_PROJECT,"Manage projects");
			strcpy(MANAG_USERS, "Manage users");
		}
		else {
			strcpy(MANAG_PROJECT, "פûגפצגû ןפûגא פן ןגאûפאûג");
			strcpy(MANAG_USERS, "פכûהאנרהûנןהûכאגנה");
		}
	}
}