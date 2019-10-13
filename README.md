### zombie
- default ist one zombie
- default ist waiting 500 millisecons between zombie creation

- call "zombie n" for n zombies
- call "zombie n m" for n zombies waiting m milliseconds between creation

### build
- g++ -Wall -fexceptions -g  -c zombie.cpp -o zombie.o
- g++ -o zombie zombie.o  -static

### background
- testing zombie reaping in docker
