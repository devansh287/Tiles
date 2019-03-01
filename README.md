# Tiles
This program focuses on manipulating a linked list using pointers, implemented as a C++ class. Please do not hesitate to contact me regarding this 
program at my email devansh@stanford.edu.

## Disclaimer
Stanford University's standard C++ libraries have been used to develop the project. I wrote the main implementation files i.e. 
tilelist.cpp and tilelist.h in the Tiles/src folder.

## Detailed description (Taken from assignment instructions)
In this problem you will write the logic for a graphical program that allows the user to click on rectangular "tiles." This program is a bit like the window manager of your operating system. When the program runs, no tiles will be present, but you can click buttons to add random tiles to the window. Some tiles overlap and occupy the same (x, y) pixels. We think of the tiles as having a "z-ordering" where the tile created/added later is "on top" of prior tiles and is able to partially cover them on the screen.
Your job is to write a class TileList that implements the collection of tiles using a linked list. Your class maintains a pointer to the front of your linked list, which represents the "top" tile, and each tile afterward is below it in the z-ordering. Each individual node contains data about a tile as well as a pointer to the next tile (the one below it in the z-ordering). This allows you to traverse your linked list from the front/top node to back/bottom, which will be useful for the various operations we want to implement.

Depending on the user's action, one of several different actions occurs:

1. Highlight: If the user clicks a tile while the "Highlight" radio button is selected, that tile's color is changed to yellow. (To do this, set the color member variable of the tile node to the string "yellow".) Its x/y position and z-ordering do not change.

2. Raise: If the user clicks a tile while the "Raise" radio button is selected, that tile is moved to the very top of the list's z-ordering (the front of the linked list).
If you raise a tile and then hold down the mouse button and move the mouse cursor, you can drag that tile to change its x/y position. (The provided GUI implements the dragging for you by asking your tile list for a pointer to the front tile and then setting that tile's x/y member variables as the mouse moves.) 

3. Lower: If the user clicks a tile while the "Lower" radio button is selected, that tile is moved to the very bottom of the list's z-ordering (the back of the linked list).

4. Remove: If the user clicks a tile while the "Remove" radio button is selected, that tile is removed from the tile list and disappears from the screen.

5. Remove All: If the user clicks an (x, y) pixel while the "Remove All" radio button is selected, all tiles that touch that (x, y) position are removed from the tile list and disappear from the screen.

6. Add to Front/Back: If the user clicks one of the Add buttons, one or more new random tiles are created and added to the front or back of the list.

7. Clear: If the user clicks the Clear button, all tiles are removed from the list and screen.
If the user clicks a pixel that is occupied by more than one tile, the top-most of these tiles should be used. If the user clicks the window at a pixel not occupied by any tiles, nothing should happen.

