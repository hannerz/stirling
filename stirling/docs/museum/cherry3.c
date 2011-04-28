#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("This is Cherry Avenue, just east of the intersection "+
	    "with Ferdinand Street.  To the south you can see the wall "+
        "of a large building, with windows displaying merchandise, "+
        "and to the north you can see a smaller building that looks "+
        "to be a house.  The street continues a bit more to the east "+
        "as well as west, and in the far distance to the east you "+
        "can make out what looks to be a stone archway to a park.");
    SetItems(([
        ({"here","room"}):"This is a length of Cherry Avenue somewhat "+
            "east of its intersection with Ferdinand Street.",
        ({"floor","ground","street","stone","stones","road"}):"The street here is paved with smooth white stones.",
        ({"walls","wall"}):"The walls of the buildings are made with roughly cut gray stone.",
        ({"house","houses"}):"To the north you can see a house.",
        ({"large building","store","shop"}):"The building to the south "+
            "has small slits for windows, through which you can just "+
            "barely make in front, showcasing what it's "+
            "selling.  Hm, guess it must be a store.",
        ({"window,windows"}):"The windows in the building south of here are showing various goodies, from swords to jewelry",
        ({"swords"}):"The swords displayed in the window seem to be the kind you would get if you took a mediocre sword, hammered "+
            "it into a plow, and then turned it back into a sword.",
        ({"jewelry","jewellery"}):"The jewelry on display looks like copper painted yellow.",
        ({"building","buildings"}):"There are three buildings here, which one did you want to look at?",
      ]));
    SetExits(([
        "west":"/domains/ATC/room/cherry1",
		"east":"/domains/ATC/room/cherry4",
      ]));

}
void init(){
    ::init();
}
