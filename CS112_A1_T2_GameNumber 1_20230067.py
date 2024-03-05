# File: CS112_A1_T2_GameNumber 1_20230067
# Purpose: Two players start from 0 and alternatively add a number from 1 to 10 to the sum. The player who reaches 100 wins.
# Author: emil ehab mosaad / اميل ايهاب مسعد
# ID: 20230067


# message to explain how to play 100 game to user.
message = """=======================
  welcome to 100 game
=======================
  explanation
===============
Two players start from 0 and alternatively add a number from 1 to 10 to the sum. The player who reaches 100 wins.
"""

# Funcion to read a valid interger from the user within the range 1 to 10.
def read_vaild_number_from_user():
  try: 
    num = int(input("enter a number from 1 to 10: "))
    while not ((num >= 1) and (num <= 10)):
      num = int(input("invalid number, try again, enter a number from 1 to 10: "))
    return num
  except:
    return read_vaild_number_from_user()

# Funcion inplementing the logic of the 100 game. 
def game_logic():
  print(message)
  main_num = 0
  while True:
    print("first player plays")
    choise1 = read_vaild_number_from_user()
    main_num += choise1
    print("main number is: ", main_num)
    if main_num >= 100:
      print("first player is winner")
      break
    else: 
      print("second player plays")
      choise2 = read_vaild_number_from_user()
      main_num += choise2
      print("main number is: ", main_num)
      if main_num >= 100:
        print("second player is winner")
        break

game_logic()