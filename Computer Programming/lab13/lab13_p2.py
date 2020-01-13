from globals import FOODMAX,  STEPMAX, WIDTH, HEIGHT, X_MAX, Y_MAX, MS_TO_QUIT
from globals import FOOD as food, GHOSTS as ghosts
# Import our own constants:

from characters import pacman

import turtle

class auto_pacman(pacman):

  """ Class auto_pacman, the automatically navigating pacman.

      The auto_pacman class is a subclass of the pacman class. It inherits all
      data attributes and methods from the pacman class. It overrides the
      move() method of the pacman class to automatically navigate pacman
      across the screen.

      Attributes:
         ... please describe your attributes here
  """

  def move(self):
    # Don't move out of the screen.
    if self.dir == 'east'  and self.ttl.xcor() > X_MAX:
      return
    if self.dir == 'west'  and self.ttl.xcor() < -X_MAX:
      return
    if self.dir == 'north' and self.ttl.ycor() > Y_MAX:
      return
    if self.dir == 'south' and self.ttl.ycor() < -Y_MAX:
      return

    # Move
    self.ttl.forward(10)

    # Get the food and pacman, ghost position
    food_x, food_y = food[0].getPosition()
    pacman_x, pacman_y = self.getPosition()
    ghost_ax, ghost_ay = ghosts[0].getPosition()
    ghost_bx, ghost_by = ghosts[1].getPosition()

    # When food is 3 left.
    if len(food) == 3:
      food_ax, food_ay = food[1].getPosition()
      if (abs(food_ax - pacman_x) < 10) and (food_ay < pacman_y):
        self.turnSouth()
      if (abs(food_ax - pacman_x) >= 10) and (food_ax < pacman_x):
        self.turnWest()

    # When food is 2 left.
    if len(food) == 2:
      if (abs(food_y - pacman_y) >= 10) and (food_y > pacman_y):
        self.turnNorth()

      # Change the head
      if abs(food_y - pacman_y) < 10 and food_x < pacman_x:
        self.turnWest()
      if abs(food_y - pacman_y) < 10 and food_x > pacman_x:
        self.turnEast()

      # When pacman go near the ghost, stop
      if (pacman_x <= -220 and ghost_ax >= 220 and abs(pacman_y - ghost_ay) <= 50 and pacman_y < ghost_ay) or (pacman_x <= -220 and ghost_bx >= 220 and abs(pacman_y - ghost_by) <= 50 and pacman_y < ghost_by):
        self.ttl.backward(10)
      if (abs(ghost_ax - pacman_x) <= 50 and abs(ghost_ay - pacman_y) <= 50 and pacman_y < ghost_ay) or (abs(ghost_bx - pacman_x) <= 50 and abs(ghost_by - pacman_y) <= 50 and pacman_y < ghost_by):
        self.ttl.backward(10)


    # When food is one left.
    if len(food) == 1:

      if (abs(food_y - pacman_y) > 10) and (food_y < pacman_y):
        self.turnSouth()
      if (abs(food_y - pacman_y) > 10) and (food_y > pacman_y):
        self.turnNorth()
      if (abs(food_y - pacman_y) <= 10) and (food_x > pacman_x):
        self.turnEast()
      if (abs(food_y - pacman_y) <= 10) and (food_x < pacman_x):
        self.turnWest()
      
    #
    # Uncomment to dump positions in the IDLE shell:
    #
    # print(ghosts[0], ghosts[1])
    # print(food[0], food[1], food[2])
    
