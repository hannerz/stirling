#include <lib.h>

inherit LIB_ROOM;

int readWall() {
    this_player()->more("/domains/ATC/txt/graffiti.txt");
    return 1;
}

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Ferdinand Street");
    SetLong("This is Ferdinand Street, just south of its intersection "+
        "with Cherry Avenue.  To the east and south you can see a blank brick "+
        "wall with several things written on it, and to the west is "+
        "a lovely looking building.");
    SetItems(([
        ({"room","here"}) : "Ferdinand Street, just south of the intersection with Cherry Avenue.",
        ({"wall","brick wall","walls","blank wall","blank brick wall",
            "east","south"}):"The "+
            "brick wall that is east and south of here has several things "+
            "written on it in messy paint.",
        ({"street","floor","ground"}):"The street here is made of smooth white stone.",
        ({"building","bank","west"}):"There is a large building to the "+
            "west of here.  It looks very new and very fancy.",
        ({"ferdinand street"}):"Ferdinand Street comes to an abrupt end "+
            "here, blocked by a brick wall.  However, it continues "+
            "northward.",
        ({"cherry avenue"}):"Directly north of here is the intersection "+
            "with Cherry Avenue.",
        ({"paint","grafitti","writing","words","things"}):"There are several "+
            "slogans and rants scribbled on the walls.  Very few of "+
            "them are legible, though.",
        ({"slogans","rants"}):"The things some people will write on walls...  "+
            "If you want, you could try to \"read wall\".",
      ]));
    SetRead(({"wall","walls","graffiti","slogans","rants","writing"}), (: readWall :) );
    SetExits(([
        "north" : "/domains/ATC/room/cherry1",
        "west":"/domains/ATC/room/imperial_bank",
      ]));
    SetAction(3,({
        "A few weary looking adventurers enter the building to the west "+
            "carrying large bags, emerging a short time later carrying "+
            "a few silver coins.",
    }));

}
void init(){
    ::init();
}
