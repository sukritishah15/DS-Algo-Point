import random
PERIOD = 1000
circle_coords = 0
square_coords = 0

# Count of Random number generated will be in [0,xVal * yVal]
for i in range(PERIOD**2):
   rand_x = random.uniform(-1,1)
   rand_y = random.uniform(-1,1)
   dist = rand_x**2 + rand_y**2
   # Check if x & y inside the circle
   if dist <= 1:
      circle_coords += 1
   square_coords += 1
   pi = 4* circle_coords/square_coords

print('Estimated Value of Pi using Monte Carlo is',pi)
"""
Final Estimation of Pi - 3.140484
Time Complexity - O(PERIOD* 2^PERIOD)
Space Complexity - O(1)
"""