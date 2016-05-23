#ifndef SELECT_H
#define SELECT_H

#include<sqlite3.h>

class TableConnecter{

	int whichGen;

	public:
		static sqlite3 *db;
		static int callback(void*, int, char**, char**);
		//TableConnecter(sqlite3 *database);
		static void switchTable(int genId);
		static bool getInfo(int id);
		static bool getInfo(std::string name);
		static bool getList(std::string type1, std::string type2);

};

#endif
