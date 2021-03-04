import cube
import random

# region functions
#stages definieren
kreuz = 1
#(Face,Field,Color)

constants = cube.CubeConstants()

stage_dic = {
  
  #Kreuz
            0: [(constants.FACE_WHITE,1,constants.COLOR_WHITE),(constants.FACE_WHITE,3,constants.COLOR_WHITE),
                 (constants.FACE_WHITE,5,constants.COLOR_WHITE),(constants.FACE_WHITE,7,constants.COLOR_WHITE),
                 (constants.FACE_RED,7,constants.COLOR_RED),(constants.FACE_ORANGE,7,constants.COLOR_ORANGE),
                 (constants.FACE_GREEN,1,constants.COLOR_GREEN),(constants.COLOR_BLUE,7,constants.COLOR_BLUE)],
  #Ecken
            1: [(constants.FACE_WHITE,2,constants.COLOR_WHITE),(constants.FACE_RED,6,constants.COLOR_RED)],
            2: [(constants.FACE_WHITE,8,constants.COLOR_WHITE),(constants.FACE_RED,8,constants.COLOR_RED)],
            3: [(constants.FACE_WHITE,6,constants.COLOR_WHITE),(constants.FACE_ORANGE,6,constants.COLOR_ORANGE)],
            4: [(constants.FACE_WHITE,0,constants.COLOR_WHITE),(constants.FACE_ORANGE,8,constants.COLOR_ORANGE)],
  #Kanten
            5: [(constants.FACE_BLUE,5,constants.COLOR_BLUE),(constants.FACE_RED,3,constants.COLOR_RED)],
            6: [(constants.FACE_RED,5,constants.COLOR_RED),(constants.FACE_GREEN,5,constants.COLOR_GREEN)],
            7: [(constants.FACE_GREEN,3,constants.COLOR_GREEN),(constants.FACE_ORANGE,3,constants.COLOR_ORANGE)],
            8: [(constants.FACE_ORANGE,5,constants.COLOR_ORANGE),(constants.FACE_BLUE,3,constants.COLOR_BLUE)],
  #YELLOW CROSS
            9: [(constants.FACE_YELLOW,1,constants.COLOR_YELLOW),(constants.FACE_YELLOW,3,constants.COLOR_YELLOW),
                (constants.FACE_YELLOW,5,constants.COLOR_YELLOW),(constants.FACE_YELLOW,7,constants.COLOR_YELLOW)],
  #Yellow edges
            10: [(constants.FACE_BLUE,1,constants.COLOR_BLUE)],
            11: [(constants.FACE_RED,1,constants.COLOR_RED)],
            12: [(constants.FACE_GREEN,7,constants.COLOR_GREEN)],
            13: [(constants.FACE_ORANGE,1,constants.COLOR_ORANGE)],
  
  #Ab hier stimmt es nicht mehr mit eigentlichem Algorithmus überein
  #Yellow corners
            14: [(constants.FACE_BLUE,2,constants.COLOR_BLUE)],
            15: [(constants.FACE_RED,2,constants.COLOR_RED)],
            16: [(constants.FACE_GREEN,6,constants.COLOR_GREEN)],
            17: [(constants.FACE_ORANGE,2,constants.COLOR_ORANGE)],  
                 }

def check(my_cube, my_stage):
    for i in range(my_stage+1):
        check_list = stage_dic[i] 
        for condition in check_list:
            if my_cube.getsequence(condition[1],my_cube.getFace(condition[0])) == condition[2]:
                pass
            else:
                return False
    return True
       
       
def scramble(my_cube):
    moves = random.randint(10,20)
    for i in range(moves):
        my_cube = my_cube.rotate(random.randint(0,11))
    return my_cube

def rekFunk(turn,my_cube,funcWay):
    if turn == turns:
        if check(my_cube,stage):
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

# endregionpuff


defaultCube = cube.Cube()
way = []
stepCube = scramble(defaultCube)

for stage in range(18):
    turns = 0
    print ("Running Stage %.", stage)
    while not rekFunk(0,stepCube,[]):
        turns+=1


