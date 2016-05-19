CFLAGS = -std=c++11

all: create fill select

create: Pokedex.cpp
	g++ $(CFLAGS) -o create Pokedex.cpp -l sqlite3

fill: fillPokedex.cpp
	g++ $(CFLAGS) -o fill fillPokedex.cpp -l sqlite3

select: selectPokedex.cpp
	g++ $(CFLAGS) -o select selectPokedex.cpp -l sqlite3

clean:
	rm -f *db create fill select
