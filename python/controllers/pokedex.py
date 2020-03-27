from flask import *
import sqlite3
import os
import sys

DATABASE = "database/Pokedex.db" 
pokedex = Blueprint("pokedex", __name__, template_folder='views')

def connect_db():
    db = getattr(g, '_database', None)
    if db is None:
        db = g._database = sqlite3.connect(DATABASE)

    return db

@pokedex.route('/Pokedex')
def dex_route():
    return render_template("Pokedex.html")

@pokedex.route('/Pokedex/selectGen', methods=['POST'])
def select_gen():
    gen = request.form['Gen']
    database = connect_db()
    return render_template("Pokedex.html")    

@pokedex.route('/Pokedex/selectMon', methods=['POST'])
def select_mon():
    idNum = request.form['PokeID']
    print >>sys.stderr, idNum
    database = connect_db()
    connection = database.cursor()
    connection.execute("SELECT * FROM POKEDEX WHERE ID = ?", idNum)
    return render_template("Pokedex.html")    
