from flask import *

pokedex = Blueprint("pokedex", __name__, template_folder='views')

@pokedex.route('/Pokedex')
def dex_route():
    return render_template("Pokedex.html")

@pokedex.route('/Pokedex/selectGen', methods=['GET', 'POST'])
def select_gen():
    return render_template("teams.html")    

