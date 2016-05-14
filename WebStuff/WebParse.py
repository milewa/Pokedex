import webbrowser, requests
from bs4 import BeautifulSoup

res = requests.get('http://bulbapedia.bulbagarden.net/wiki/List_of_Pok%C3%A9mon_by_National_Pok%C3%A9dex_number')
soup = BeautifulSoup(res.text)


allTables = soup.findAll("table", {"align" : "center"});

row = allTables[0].find_all('tr');

for info in row:
    data = info.find_all('td');
    if not data:
        continue
    pId = data[1].getText()
    name = data[3].find('a').getText().encode("utf8")
    if int(data[4]["colspan"]) == 1:
        type1 = data[4].find('a').getText()
        type2 = data[5].find('a').getText()
        print type1 + " " + type2
    else:
        type1 = data[4].find('a').getText()
        print type1

#for table in allTables:
#   row = table.find_all('tr');
#    data = row.find_all('td')
#    print data[0]

#value = soup.select('tr')

#print value[2];



