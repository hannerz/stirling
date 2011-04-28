#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("This is Cherry Avenue, just a little west of its intersection "+
        "with Ferdinand Street.  There is a blank brick wall to the north, "+
        "and an empty, grass-and-weed filled square to the south keeping "+
        "with the town's theme of \"Empty Lots and Shanties\".  The "+
        "street curves to the southwest from here, leading toward what "+
        "looks to be the business district of the town.");
    SetItems(([
        ({"here","room"}):"This is a length of Cherry Avenue somewhat "+
            "west of its intersection with Ferdinand Street.",
        ({"floor","ground","street","stone","stones","road"}):"The street "+
            "here is paved with smooth white stones.",
        ({"building","house","wall","brick wall"}):"There is a brick wall "+
            "north of here.  It looks so new the grout shines.",
        ({"grout","mortar"}):"The grout between the bricks in the north "+
            "wall is so new it is still shiny.",
        ({"lot","square"}):"To the south of here is a large empty square, "+
            "that looks as though at one point it may have been used as "+
            "the main meeting place for the town.",
        ({"grass","weed","weeds","growth"}):"The lot to the south has lots of "+
            "different grasses and weeds in it.  If you were a botanist, "+
            "I'm sure you'd be thrilled.",
        ({"cherry avenue"}):"Cherry Avenue goes southwest and east from "+
            "here.",
        ({"ferdinand street"}):"Ferdinand Street is directly east of here.",
      ]));
    SetAction(3,({
        "A small lost field mouse runs out of the grassy lot, looks "+
        "around in a panic, and darts back into the growth.",
    }));
    SetExits(([
        "east":"/domains/ATC/room/cherry1",
		"southwest":"/domains/ATC/room/cherry6",
      ]));
}
void init(){
    ::init();
}
