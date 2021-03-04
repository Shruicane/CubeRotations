import Cube
import random

# region functions

def scramble(cube):
    moves = random.randint(10,20)
    for i in range(moves):
        cube = cube.rotate(random.randint(0,11))
    return cube

def rekFunk(turn,cube,funcWay):
    if turn == turns:
        if cube.check(stage):
            global stepCube
            for i in funcWay:
                way.append(i)
            stepCube = cube
            return True
        return False
    else:
        for i in range(12):
            funcWay.append(i)
            newCube = cube.rotate(i)
            if rekFunk(turn+1, newCube, funcWay):
                return True
        return False

# endregion

defaultCube = Cube()
way = []
stepCube = scrumble(defaultCube)

for stage in range(10):
    turns = 0
    print ("Running Stage %.", stage)
    while not rekFunk(0,stepCube,[]):
        turns+=1
