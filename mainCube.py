import cube
import random

# region functions
#stages definieren
kreuz = 1
#(Face,Field,Color)

constants = cube.CubeConstants()

stage_dic = {0: [(constants.FACE_WHITE,1,constants.COLOR_WHITE),(constants.FACE_WHITE,3,constants.COLOT_WHITE),
                 (constants.FACE_WHITE,5,constants.COLOR_WHITE),(constants.FACE_WHITE,7,constants.COLOR_WHITE),
                 (constats.FACE_RED,7,constants.COLOR_RED),(constants.FACE_ORANGE,7,constants.COLOR_ORANGE),
                 (constants.FACE_GREEN,1,constants.COLOR_GREEN),(constants.COLOR_BLUE,7,constants.COLOR_BLUE)]}

def check(my_cube, my_stage):
    check_list = stage_dic[my_stage] 
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

# endregion

defaultCube = Cube()
way = []
stepCube = scramble(defaultCube)

for stage in range(1):
    turns = 0
    print ("Running Stage %.", stage)
    while not rekFunk(0,stepCube,[]):
        turns+=1

print('love everywhere')
