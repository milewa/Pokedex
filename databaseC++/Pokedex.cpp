#include<iostream>
#include<sqlite3.h>
#include<stdlib.h>
using namespace std;

static int callback(void*, int, char**, char**);
 
int main(int argc, char* argv[]){
	sqlite3 *db;
	char *zErrMsg = 0;
	int check;
	const char *sql;

	check = sqlite3_open("Pokedex.db", &db);
	if(check){
		cout << "Problem occurred\n";
		exit(0);
	}else
		cout << "Opened.\n";
	
	sql = "CREATE TABLE POKEDEX(ID int, Name text, Type text)";
	/*sql = "CREATE TABLE POKEDEX(" \
	      "ID   INT PRIMARY KEY   NOT NULL," \
	      "Name 		TEXT  NOT NULL," \
	      "Type 		TEXT  NOT NULL);";*/
	check = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(check != SQLITE_OK){
		cout << "Table not created: " << zErrMsg << endl;;
		sqlite3_free(zErrMsg);
	}else{
		cout << "Table created\n";
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
