#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_DOORS 3
#define NUM_RUNS 100
#define GOAT 0
#define CAR 1

void initializeDoors(int *);
int revealDoor(int, int *);
int swapDoors(int, int, int *);
void report(int, int, int *);

int main(void)
{
  int x, chosenDoor, revealedDoor, nonSwapCount = 0, swapCount = 0;
  int doors[NUM_DOORS];
  unsigned int iseed = (unsigned int)time(NULL);

  /* Initialize the random number generator */
  srand(iseed);

  printf("Non-Swap Results\n");

  /* Determine percentage without swapping doors */
  for (x = 0; x < NUM_RUNS; x++)
  {
    initializeDoors(doors);

    chosenDoor = rand() % NUM_DOORS;
    revealedDoor = revealDoor(chosenDoor, doors);

    if (doors[chosenDoor] == CAR)
    {
      ++nonSwapCount;
    }

    report(chosenDoor, revealedDoor, doors);
  }

  printf("-----------------------------------------\n");
  printf("Swap Results\n");

  /* Determine percentage after swapping doors */
  for (x = 0; x < NUM_RUNS; x++)
  {
    initializeDoors(doors);

    chosenDoor = rand() % NUM_DOORS;
    revealedDoor = revealDoor(chosenDoor, doors);
    chosenDoor = swapDoors(chosenDoor, revealedDoor, doors);

    if (doors[chosenDoor] == CAR)
    {
      ++swapCount;
    }

    report(chosenDoor, revealedDoor, doors);
  }

   printf("Swap Win Average - %.0f%%\n", ((double)swapCount / NUM_RUNS) * 100);
   printf("Non-Swap Win Average - %.0f%%\n", ((double)nonSwapCount / NUM_RUNS) * 100);

  return 0;
}

void initializeDoors(int *doors)
{
  int x;

  for (x = 0; x < NUM_DOORS; x++)
  {
    doors[x] = GOAT;
  }

  /* Assign a car to one of the doors */
  doors[rand() % NUM_DOORS] = CAR;
}

int revealDoor(int chosenDoor, int *doors)
{
  int revealedDoor;

  do
  {
    revealedDoor = rand() % NUM_DOORS;
  } while (revealedDoor == chosenDoor || doors[revealedDoor] == CAR);

  return revealedDoor;
}

int swapDoors(int chosenDoor, int revealedDoor, int *doors)
{
  int newDoor = -1;

  do
  {
    ++newDoor;
  } while (newDoor == chosenDoor || newDoor == revealedDoor);

  return newDoor;
}

void report(int chosenDoor, int revealedDoor, int *doors)
{
  int winner = -1;

  do
  {
    winner++;
  } while (doors[winner] != CAR);

  printf("Chose: %d\tRevealed: %d\tWinning Door: %d%s\n",
    chosenDoor,
    revealedDoor,
    winner,
    winner == chosenDoor ? " Winner!" : "");
}

