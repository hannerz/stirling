#include <lib.h>
inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/doge_sign.txt");
    return 1;
}
static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("Around halfway down the eastern half of Cherry Avenue "+
      "in Ackian Training Camp 07B.  There is a park some ways to "+
      "the east, and to the west is the intersection with Ferdinand "+
      "Street.  To the south is a grassy lot, and to the north is a "+
      "window-less building with a heavy oak door.  There is a sign "+
      "above the door.");
    SetItems( ([ ({"here","room"}):"Cherry Avenue south of the Doge and Biscuit.",
        ({"floor","ground","street","stone","stones","road"}):"The street here is paved with smooth white stones.",
        ({"sign"}):"There is a large sign nailed above the northern doorway.",
        ({"building","buildings","pub","bar","tavern"}):"To the north is the Doge and Biscuit, the local watering hole.",
        ({"windows","window"}):"There aren't any windows on the building north of here.",
        ({"door","heavy door","oak door","heavy oak door","doorway"}):"The door on the building to the north is made of "+
            "several slabs of oak bonded together with iron bands.",
        ({"bands","iron bands","metal bands"}):"There are bands holding the northern door together.",
        ({"lot","lots"}):"To the south of here is a vacant lot filled with tall grass.",
      ]) );
    SetExits( ([
        "west" : "/domains/ATC/room/cherry3",
        "east" : "/domains/ATC/room/cherry5",
        "north" : "/domains/ATC/room/doge_and_biscuit.c",
      ]) );
    SetAction(5, ({
        "An Ackian Guard walks in from the east, picks up a scrap "+
        "of litter, and continues westward.",
      }));
    SetRead("sign", (: readSign :) );
}
void init(){
    ::init();
}
