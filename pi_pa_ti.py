
import random
opciones = [ "piedra", "papel", "tijera" ]
veces = int(input("¿Cuántas veces quieres jugar? "))

victorias = 0
derrotas = 0
empates = 0

for i in range(veces):

    usuario = input("\nElige piedra, papel o tijera: ").lower()
    computadora = random.choice(opciones)

    print(f"La computadora eligió: {computadora}")

    if computadora == usuario:
        print("You and the computer are soul mates")
        empates += 1
        print(f"Empates: {empates}")

    elif ( usuario == "piedra" and computadora == "tijera" ) or \
        ( usuario == "papel" and computadora == "piedra" ) or \
        ( usuario == "tijera" and computadora == "papel" ):
        print("You won")
        victorias += 1
        print(f"Victorias: {victorias}")
    else:
        print("you are a loser")
        derrotas += 1
        print(f"Derrotas: {derrotas}")
    
    
    
