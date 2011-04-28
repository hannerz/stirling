#include <lib.h>

inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/underconst2.txt");
    return 1;
}
static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Ferdinand Street");
    SetLong("This is Ferdinand Street, just north of an intersection with a much larger street.  "+
        "On both sides of the road are two houses.  To the west is a doorway with no door, and hanging next "+
        "to the boarded-up eastern door is a sign.");
    SetItems(([
        ({"here","room"}):"This is the near the northern end of Ferdinand Street in Ackian Training Camp 07B.  To the south is"+
            "Cherry Avenue.",
        ({"floor","ground","street","stone","stones","road"}):"The street here is paved with smooth white stones.",
        ({"walls","wall"}):"The walls of the houses are made with roughly cut gray stone.",
        ({"house","houses","buildings","stone house","stone houses"}):"The "+
            "houses are long and single story.  Their entrance is here.",
        ({"doors","doorways",}):"The west door has no door, just a frame, "+
            "and the east door is boarded up.",
        ({"east","east door","east doorway","eastern door","eastern doorway"}):"There is a sign next to the this doorway.",
        ({"sign"}):"There is a sign hanging next to the eastern door.  Perhaps you can read it?",
        ({"intersection"}):"To the south is an intersection with Cherry Avenue.",
        ({"cherry avenue"}):"To the south, Ferdinand Street meets with "+
            "Cherry Avenue.",
        ({"ferdinand street"}):"Ferdinand Street goes north and south "+
            "from here.",
      ]));
    SetExits( ([
        "south" : "/domains/ATC//room/cherry1",
        "north" : "/domains/ATC/room/ferdinand1",
        "west" : "/domains/ATC/room/mervi_ent",
      ]) );
    SetRead("sign", (: readSign :) );
    SetAction(3, ({
        "You think you hear someone moving around in the eastern "+
             "house.",
        "A sudden bang comes from the house to the east.",
    }));
}
void init(){
    ::init();
}
