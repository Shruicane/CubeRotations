import cube
import random

# region functions


constants = cube.CubeConstants()

stage_dic = {

  #(Face,Field,Color)

  #Kreuz
            0: [(constants.FACE_WHITE,constants.UNSIGNED_1,constants.COLOR_WHITE),(constants.FACE_WHITE,constants.UNSIGNED_3,constants.COLOR_WHITE),
                 (constants.FACE_WHITE,constants.UNSIGNED_5,constants.COLOR_WHITE),(constants.FACE_WHITE,constants.UNSIGNED_7,constants.COLOR_WHITE),
                 (constants.FACE_RED,constants.UNSIGNED_7,constants.COLOR_RED),(constants.FACE_ORANGE,constants.UNSIGNED_7,constants.COLOR_ORANGE),
                 (constants.FACE_GREEN,constants.UNSIGNED_1,constants.COLOR_GREEN),(constants.COLOR_BLUE,constants.UNSIGNED_7,constants.COLOR_BLUE)],
  #Ecken
            1: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_6,constants.COLOR_RED)],
            2: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_8,constants.COLOR_RED)],
            3: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_6,constants.COLOR_ORANGE)],
            4: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_8,constants.COLOR_ORANGE)],
  #Kanten
            5: [(constants.FACE_BLUE,constants.UNSIGNED_5,constants.COLOR_BLUE),(constants.FACE_RED,constants.UNSIGNED_3,constants.COLOR_RED)],
            6: [(constants.FACE_RED,constants.UNSIGNED_5,constants.COLOR_RED),(constants.FACE_GREEN,constants.UNSIGNED_5,constants.COLOR_GREEN)],
            7: [(constants.FACE_GREEN,constants.UNSIGNED_3,constants.COLOR_GREEN),(constants.FACE_ORANGE,constants.UNSIGNED_3,constants.COLOR_ORANGE)],
            8: [(constants.FACE_ORANGE,constants.UNSIGNED_5,constants.COLOR_ORANGE),(constants.FACE_BLUE,constants.UNSIGNED_3,constants.COLOR_BLUE)],
  #YELLOW CROSS
            9: [(constants.FACE_YELLOW,constants.UNSIGNED_1,constants.COLOR_YELLOW),(constants.FACE_YELLOW,constants.UNSIGNED_3,constants.COLOR_YELLOW),
                (constants.FACE_YELLOW,constants.UNSIGNED_5,constants.COLOR_YELLOW),(constants.FACE_YELLOW,constants.UNSIGNED_7,constants.COLOR_YELLOW)],
  #Yellow edges
            10: [(constants.FACE_BLUE,constants.UNSIGNED_1,constants.COLOR_BLUE)],
            11: [(constants.FACE_RED,constants.UNSIGNED_1,constants.COLOR_RED)],
            12: [(constants.FACE_GREEN,constants.UNSIGNED_7,constants.COLOR_GREEN)],
            13: [(constants.FACE_ORANGE,constants.UNSIGNED_1,constants.COLOR_ORANGE)],

  #Ab hier stimmt es nicht mehr mit eigentlichem Algorithmus überein
  #Yellow corners
            14: [(constants.FACE_BLUE,constants.UNSIGNED_2,constants.COLOR_BLUE),
                (constants.FACE_RED,constants.UNSIGNED_0,constants.COLOR_RED)],
            15: [(constants.FACE_RED,constants.UNSIGNED_2,constants.COLOR_RED),
                (constants.FACE_GREEN,constants.UNSIGNED_8,constants.COLOR_GREEN)],
            16: [(constants.FACE_GREEN,constants.UNSIGNED_6,constants.COLOR_GREEN),
                (constants.FACE_ORANGE,constants.UNSIGNED_0,constants.COLOR_ORANGE)],
            17: [(constants.FACE_ORANGE,constants.UNSIGNED_2,constants.COLOR_ORANGE),
                (constants.FACE_BLUE,constants.UNSIGNED_0,constants.COLOR_BLUE)]
  }


G1_dic = {

  #(Face,Field,Color)
  #Jede genannte Bedingung bringt einen Punkt für G1, hat man das Maximum von 20 Punkten, ist G1 erfüllt.

  #Weiße Ecksteine richtig gedreht

          0: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE)],
          1: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE)],
          2: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE)],
          3: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE)],

  #Gelbe Ecksteine richtig gedreht

          4: [(constants.FACE_YELLOW,constants.UNSIGNED_8,constants.COLOR_YELLOW)],
          5: [(constants.FACE_YELLOW,constants.UNSIGNED_2,constants.COLOR_YELLOW)],
          6: [(constants.FACE_YELLOW,constants.UNSIGNED_0,constants.COLOR_YELLOW)],
          7: [(constants.FACE_YELLOW,constants.UNSIGNED_6,constants.COLOR_YELLOW)],

 # zweite Ebene ( vier Kantensteine)

          8:  [(constants.FACE_BLUE,constants.UNSIGNED_5,constants.COLOR_BLUE),(constants.FACE_RED,constants.UNSIGNED_3,constants.COLOR_RED)],
          9:  [(constants.FACE_RED,constants.UNSIGNED_5,constants.COLOR_RED),(constants.FACE_GREEN,constants.UNSIGNED_5,constants.COLOR_GREEN)],
          10:  [(constants.FACE_GREEN,constants.UNSIGNED_3,constants.COLOR_GREEN),(constants.FACE_ORANGE,constants.UNSIGNED_3,constants.COLOR_ORANGE)],
          11:  [(constants.FACE_ORANGE,constants.UNSIGNED_5,constants.COLOR_ORANGE),(constants.FACE_BLUE,constants.UNSIGNED_3,constants.COLOR_BLUE)],

  #untere Kantensteine

          12:  [(constants.FACE_WHITE,constants.UNSIGNED_5,constants.COLOR_WHITE)],
          13:  [(constants.FACE_WHITE,constants.UNSIGNED_7,constants.COLOR_WHITE)],
          14:  [(constants.FACE_WHITE,constants.UNSIGNED_3,constants.COLOR_WHITE)],
          15:  [(constants.FACE_WHITE,constants.UNSIGNED_1,constants.COLOR_WHITE)],

  #obere Kantensteine

          16:  [(constants.FACE_YELLOW,constants.UNSIGNED_5,constants.COLOR_YELLOW)],
          17:  [(constants.FACE_YELLOW,constants.UNSIGNED_1,constants.COLOR_YELLOW)],
          18:  [(constants.FACE_YELLOW,constants.UNSIGNED_3,constants.COLOR_YELLOW)],
          19:  [(constants.FACE_YELLOW,constants.UNSIGNED_7,constants.COLOR_YELLOW)]

          }


            '''0: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE),(constants.FACE_BLUE,constants.UNSIGNED_8,constants.COLOR_BLUE),
                (constants.FACE_RED,constants.UNSIGNED_6,constants.COLOR_RED)],
            1: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_8,constants.COLOR_BLUE),
                (constants.FACE_GREEN,constants.UNSIGNED_2,constants.COLOR_RED)],
            2: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE),(constants.FACE_GREEN,constants.UNSIGNED_0,constants.COLOR_BLUE),
                (constants.FACE_ORANGE,constants.UNSIGNED_6,constants.COLOR_RED)],
            3: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_8,constants.COLOR_BLUE),
                (constants.FACE_BLUE,constants.UNSIGNED_6,constants.COLOR_RED)],

    #Zweite Eckstein (weiß, rot , grün)
            4: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE),(constants.FACE_BLUE,constants.UNSIGNED_8,constants.COLOR_RED),
                (constants.FACE_RED,constants.UNSIGNED_6,constants.COLOR_GREEN)],
            5: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_8,constants.COLOR_RED),
                (constants.FACE_GREEN,constants.UNSIGNED_2,constants.COLOR_GREEN)],
            6: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE),(constants.FACE_GREEN,constants.UNSIGNED_0,constants.COLOR_RED),
                (constants.FACE_ORANGE,constants.UNSIGNED_6,constants.COLOR_GREEN)],
            7: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_8,constants.COLOR_RED),
                (constants.FACE_BLUE,constants.UNSIGNED_6,constants.COLOR_GREEN)],

    #Dritter Eckstein (weiß, grün , orange)
            8: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE),(constants.FACE_BLUE,constants.UNSIGNED_8,constants.COLOR_GREEN),
                (constants.FACE_RED,constants.UNSIGNED_6,constants.COLOR_ORANGE)],
            9: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_8,constants.COLOR_GREEN),
                (constants.FACE_GREEN,constants.UNSIGNED_2,constants.COLOR_ORANGE)],
            10: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE),(constants.FACE_GREEN,constants.UNSIGNED_0,constants.COLOR_GREEN),
                (constants.FACE_ORANGE,constants.UNSIGNED_6,constants.COLOR_ORANGE)],
            11: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_8,constants.COLOR_GREEN),
                (constants.FACE_BLUE,constants.UNSIGNED_6,constants.COLOR_ORANGE)],


    #Vierter Eckstein (weiß, orange , blau)
            12: [(constants.FACE_WHITE,constants.UNSIGNED_2,constants.COLOR_WHITE),(constants.FACE_BLUE,constants.UNSIGNED_8,constants.COLOR_ORANGE),
                (constants.FACE_RED,constants.UNSIGNED_6,constants.COLOR_BLUE)],
            13: [(constants.FACE_WHITE,constants.UNSIGNED_8,constants.COLOR_WHITE),(constants.FACE_RED,constants.UNSIGNED_8,constants.COLOR_ORANGE),
                (constants.FACE_GREEN,constants.UNSIGNED_2,constants.COLOR_BLUE)],
            14: [(constants.FACE_WHITE,constants.UNSIGNED_6,constants.COLOR_WHITE),(constants.FACE_GREEN,constants.UNSIGNED_0,constants.COLOR_ORANGE),
                (constants.FACE_ORANGE,constants.UNSIGNED_6,constants.COLOR_BLUE)],
            15: [(constants.FACE_WHITE,constants.UNSIGNED_0,constants.COLOR_WHITE),(constants.FACE_ORANGE,constants.UNSIGNED_8,constants.COLOR_ORANGE),
                (constants.FACE_BLUE,constants.UNSIGNED_6,constants.COLOR_BLUE)],

    #fünfter Eckstein (gelb, blau, rot)
            16: [(constants.FACE_YELLOW,constants.UNSIGNED_8,constants.COLOR_YELLOW),(constants.FACE_BLUE,constants.UNSIGNED_2,constants.COLOR_BLUE),
                (constants.FACE_RED,constants.UNSIGNED_0,constants.COLOR_RED)],
            17: [(constants.FACE_YELLOW,constants.UNSIGNED_2,constants.COLOR_YELLOW),(constants.FACE_RED,constants.UNSIGNED_2,constants.COLOR_BLUE),
                (constants.FACE_GREEN,constants.UNSIGNED_8,constants.COLOR_RED)],
            18: [(constants.FACE_YELLOW,constants.UNSIGNED_0,constants.COLOR_YELLOW),(constants.FACE_GREEN,constants.UNSIGNED_6,constants.COLOR_BLUE),
                (constants.FACE_ORANGE,constants.UNSIGNED_0,constants.COLOR_RED)],
            19: [(constants.FACE_YELLOW,constants.UNSIGNED_6,constants.COLOR_YELLOW),(constants.FACE_ORANGE,constants.UNSIGNED_2,constants.COLOR_BLUE),
                (constants.FACE_BLUE,constants.UNSIGNED_0,constants.COLOR_RED)],

    #sechter Eckstein (gelb, rot, grün)
            20: [(constants.FACE_YELLOW,constants.UNSIGNED_8,constants.COLOR_YELLOW),(constants.FACE_BLUE,constants.UNSIGNED_2,constants.COLOR_RED),
                (constants.FACE_RED,constants.UNSIGNED_0,constants.COLOR_GREEN)],
            21: [(constants.FACE_YELLOW,constants.UNSIGNED_2,constants.COLOR_YELLOW),(constants.FACE_RED,constants.UNSIGNED_2,constants.COLOR_RED),
                (constants.FACE_GREEN,constants.UNSIGNED_8,constants.COLOR_GREEN)],
            22: [(constants.FACE_YELLOW,constants.UNSIGNED_0,constants.COLOR_YELLOW),(constants.FACE_GREEN,constants.UNSIGNED_6,constants.COLOR_RED),
                (constants.FACE_ORANGE,constants.UNSIGNED_0,constants.COLOR_GREEN)],
            23: [(constants.FACE_YELLOW,constants.UNSIGNED_6,constants.COLOR_YELLOW),(constants.FACE_ORANGE,constants.UNSIGNED_2,constants.COLOR_RED),
                (constants.FACE_BLUE,constants.UNSIGNED_0,constants.COLOR_GREEN)],

    #siebenter Eckstein ( gelb, grün, orange)
            24: [(constants.FACE_YELLOW,constants.UNSIGNED_8,constants.COLOR_YELLOW),(constants.FACE_BLUE,constants.UNSIGNED_2,constants.COLOR_GREEN),
                (constants.FACE_RED,constants.UNSIGNED_0,constants.COLOR_ORANGE)],
            25: [(constants.FACE_YELLOW,constants.UNSIGNED_2,constants.COLOR_YELLOW),(constants.FACE_RED,constants.UNSIGNED_2,constants.COLOR_GREEN),
                (constants.FACE_GREEN,constants.UNSIGNED_8,constants.COLOR_ORANGE)],
            26: [(constants.FACE_YELLOW,constants.UNSIGNED_0,constants.COLOR_YELLOW),(constants.FACE_GREEN,constants.UNSIGNED_6,constants.COLOR_GREEN),
                (constants.FACE_ORANGE,constants.UNSIGNED_0,constants.COLOR_ORANGE)],
            27: [(constants.FACE_YELLOW,constants.UNSIGNED_6,constants.COLOR_YELLOW),(constants.FACE_ORANGE,constants.UNSIGNED_2,constants.COLOR_GREEN),
                (constants.FACE_BLUE,constants.UNSIGNED_0,constants.COLOR_ORANGE)],

    #achter Eckstein (gelb, orange, blau)
            28: [(constants.FACE_YELLOW,constants.UNSIGNED_8,constants.COLOR_YELLOW),(constants.FACE_BLUE,constants.UNSIGNED_2,constants.COLOR_ORANGE),
                (constants.FACE_RED,constants.UNSIGNED_0,constants.COLOR_BLUE)],
            29: [(constants.FACE_YELLOW,constants.UNSIGNED_2,constants.COLOR_YELLOW),(constants.FACE_RED,constants.UNSIGNED_2,constants.COLOR_ORANGE),
                (constants.FACE_GREEN,constants.UNSIGNED_8,constants.COLOR_BLUE)],
            30: [(constants.FACE_YELLOW,constants.UNSIGNED_0,constants.COLOR_YELLOW),(constants.FACE_GREEN,constants.UNSIGNED_6,constants.COLOR_ORANGE),
                (constants.FACE_ORANGE,constants.UNSIGNED_0,constants.COLOR_BLUE)],
            31: [(constants.FACE_YELLOW,constants.UNSIGNED_6,constants.COLOR_YELLOW),(constants.FACE_ORANGE,constants.UNSIGNED_2,constants.COLOR_ORANGE),
                (constants.FACE_BLUE,constants.UNSIGNED_0,constants.COLOR_BLUE)],
'''

def checkStage(my_cube, my_stage):
    for i in range(my_stage+1):
        check_list = stage_dic[i]
        for condition in check_list:
            if my_cube.getSequence(condition[1],my_cube.getFace(condition[0])) == condition[2]:
                pass
            else:
                return False
    return True


def checkG1score(my_cube):
    checkScore = 0
    for i in range(len(G1_dic)):
        check_list = G1_dic[i]
        add = 1
        for condition in check_list:
            if my_cube.getSequence(condition[1],my_cube.getFace(condition[0])) == condition[2]:
                pass
            else:
                add = 0
        checkScore += add
    return checkScore

def scramble(my_cube):
    moves = random.randint(10,20)
    for i in range(moves):
        my_cube = my_cube.rotate(random.randint(0,11))
    return my_cube


def rekVerbesserung(turn,my_cube,funcWay):
    if turn == turns:
        score = checkG1score(my_cube)

        if score > score_way_tuple[0]:
            score_way_tuple[0] = score
            score_way_tuple[1] = funcWay

        else:
            pass
    else:
        for i in range(12):
            funcWay.append(i)
            newCube = my_cube.rotate(i)
            rekFunk(turn+1, newCube, funcWay)


def rekFunk(turn,my_cube,funcWay):
    if turn == turns:
        if checkStage(my_cube,stage):
            global stepCube
            for i in funcWay:
                way.append(i)
            stepCube = my_cube
            return True
        return False
    else:
        for i in range(12):
            funcWay.append(i)
            newCube = my_cube.rotate(i)
            if rekFunk(turn+1, newCube, funcWay):
                return True
        return False




# endregion

defaultCube = cube.Cube()
way = []
stepCube = scramble(defaultCube)


#Verbesserung nach score


turns = 6
cubeScore = 0

score_way_tuple = [0,[]]
rekVerbesserung(0,stepCube,[])

while score_way_tuple[0] > cubeScore:
    cubeScore = score_way_tuple[0]
    way.append(score_way_tuple[1])

    score_way_tuple = [0,[]]
    rekVerbesserung(0,stepCube,[])
#es wurde mit sechs schritten verbessert, bis es einmal keine echte verbesserung gab. dies könnte z.b. dreimal wiederholt werden und dann nochmal mit 7 oder so ähnlich.
# oder sogar so lange bis G1 geknackt ist.    

#Fertigstellung nach Stages

#die reihenfolge der stages kann verändert werden und es kann sich auf die 6 hauptzüge  beschränkt werden
for stage in range(18):
    turns = 0
    print ("Running Stage %.", stage)
    while not rekFunk(0,stepCube,[]):
        print("Running Turn %.", turns)
        turns+=1
