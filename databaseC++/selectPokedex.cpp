#include<iostream>
#include<stdlib.h>
#include<string>
#include "selectPokedex.h"

using namespace std;

static int callback(void*, int, char**, char**);
static bool getInfo(int id){
	
}

int main(int argc, char* argv[]){
	sqlite3 *db;
	char *zErrMsg = 0;
	int check;
	const char *sql;
	const char *data;
	string sql_command;
	int id; 
	string name, type;

	check = sqlite3_open("Pokedex.db", &db);
	if(check){
		cout << "Problem occurred\n";
		exit(0);
	}else
		cout << "Opened.\n";
	sql = "SELECT Name FROM Pokedex ";
	check = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	 
	if(check != SQLITE_OK){
		cout << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		exit(0);
	}

	cout << "Which Pokemon would you like to learn more about? Or exit to leave.\n";
	string whichOne, command;
	string suffix = "';";
	while(cin >> whichOne){
		if(whichOne == "exit")
			break;
		command = "SELECT * FROM Pokedex WHERE Name = '";
		command.append(whichOne);
		command.append(suffix);

		check = sqlite3_exec(db, command.c_str(), callback, (void*)data, &zErrMsg);
	 
		if(check != SQLITE_OK){
			cout << zErrMsg << endl;
			sqlite3_free(zErrMsg);
			exit(0);
		}
		cout << "Which Pokemon would you like to learn more about? Or exit to leave.\n";
	}	

	sqlite3_close(db);
	cout << "Closed\n";
	return 0;
}
static int callback(void* NotUsed, int argc, char**argv, char**szColName){
	for(int i = 0; i < argc; i++){
		cout << szColName[i] << " = " << argv[i] << endl;
	}
	cout << '\n';
	return 0;
} 
