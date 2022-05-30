# Simple_Maze

## Free - Yam Engine
(Currently resizing is an issue, please keep at default: 800 x 600)

### Bot:
- [x] User can manipulate Entity called **Bot**
- [x] Bot moves with **arrow keys**
- [x] Bot state changes with keys: **A, S, or D**
- [x] Bot cannot move above the top of the game window
- [x] Bot cannot move below the bottom of the game window
- [x] Moving Bot past the left or right boundaries of the game window will loop the bot to other side
- [x] Bot cannot move past walls (stopped when collides)
- [x] Bot cannot change state if it results in collision with walls
  
### Maze:
- [x] Game has a start screen with simple animation
- [x] Press spacebar to start the game
- [x] Maze built with a vector of Entities
- [x] Infinitely moving Entity called **Sweeper**
- [x] Bot resets when it collides with the Sweeper
- [x] Game progressed when goal (green line) is reached
- [x] Stage 2 clones the Sweeper Entity
- [x] After stage 2 is the end credits
- [x] End credits has a short animation before exit(0) is called

## Demo:
![](Free_Demo.gif)

## CMake Configuration:
![image](CMake_Config.PNG)
