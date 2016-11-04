#include<iostream>
#include "sqlite/sqlite3.h"
#include<stdlib.h>
#include<string>

using namespace std;

static int callback(void*, int, char**, char**);

int main(int argc, char* argv[]){
	sqlite3 *db;
	char *zErrMsg = 0;
	int check;
	const char *sql;
	string sql_command;
	int id; 
	string name, type;

	check = sqlite3_open("Pokedex.db", &db);
	if(check){
		cout << "Problem occurred\n";
		exit(0);
	}else{
		cout << "Opened.\n";
	}
	while(cin >> id >> name >> type){
//		cout << id << " " << name << " " << type << endl;
		name += ", ";
		sql_command = "INSERT INTO Pokedex VALUES (";
		sql_command += to_string(id);
		sql_command += ", " + name + type + ")";
		cout << sql_command << endl;
		check = sqlite3_exec(db, sql_command.c_str(), callback, 0, &zErrMsg);
		if(check != SQLITE_OK){
			cout << zErrMsg << endl;
			sqlite3_free(zErrMsg);
			exit(0);
		}else{
			cout << "Inserted\n";
		}	
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
