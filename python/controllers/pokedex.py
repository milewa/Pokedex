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
    database = connect_db()
    connection = database.cursor()
    cur = connection.execute("SELECT * FROM POKEDEX WHERE ID = ?", idNum)
    data = cur.fetchall()
    typing = data[0][2]
    if typing[len(typing) - 1] is '/':
        typing = typing[:-1]
    return render_template("Pokedex.html", name = data[0][1], pokemonType = typing)
