#include<iostream>
#include<sqlite3.h>
#include<stdlib.h>
#include<string>

using namespace std;

static int callback(void*, int, char**, char**);

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

	sql = "SELECT * FROM Pokedex";
	check = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
	 
	if(check != SQLITE_OK){
		cout << zErrMsg << endl;
		sqlite3_free(zErrMsg);
		exit(0);
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
