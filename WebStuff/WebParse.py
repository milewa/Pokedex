import webbrowser, requests
from bs4 import BeautifulSoup

res = requests.get('http://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_National_Pok%C3%A9dex_number')
soup = BeautifulSoup(res.text)


allTables = soup.findAll("table", {"align" : "center"});

gen = 1;

for table in allTables:
    Gen = "Gen" + str(gen) + ".txt";
    f = open(Gen, 'w')
    row = table.find_all('tr');

    for info in row:
        data = info.find_all('td');
        
        #takes care of the table with no data in it
        if not data:
            continue

        pId = data[1].getText().rstrip().encode("utf8")
        pId = pId[2:]

        name = data[3].find('a').getText().encode("utf8")

        type1 = type2 = ''
        if int(data[4]["colspan"]) == 1:
            type1 = data[4].find('a').getText().encode("utf8")
            type2 = data[5].find('a').getText().encode("utf8")
        else:
            type1 = data[4].find('a').getText().encode("utf8")

        f.write(pId + " '" + name + "' '" + type1 + "/" + type2 + "'\n")

    f.close()
    gen += 1
