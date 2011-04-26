#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("temperate");
    SetAmbientLight(40);
    SetShort("ATC Market");
    SetLong("This is the northeastern corner of the market in Ackian "+
        "Training Camp 07B.  To the east you can see the Imperial Church, "+
        "and there is a small tent here you can enter.  The market extends "+
        "off to the south, southwest, and west.");
    SetItems(([
        ({"here","room","market"}):"This is a length of Cherry Avenue somewhat "+
            "west of its intersection with Ferdinand Street.",
        ({"floor","ground","street","stone","stones","road"}):"The market "+
           "is paved with smooth white stones.",
        ({"cherry avenue"}):"Cherry Avenue is to the northeast of here.",
        ({"tent"}):"Set up here, there is a rigid canvas tent here.  It looks "+
            "about as permanent as a tent can be.",
      ]));
    SetInventory(([
        "/domains/ATC/npc/farmer" : 1,
      ]));
    SetExits(([
        "northeast":"/domains/ATC/room/cherry6",
        "east":"/domains/ATC/room/church",
        "tent":"/domains/ATC/room/tent1",
        "west":"/domains/ATC/room/market2",
        "southwest":"/domains/ATC/room/market3",
        "south":"/domains/ATC/room/market4",
      ]));

}
void init(){
    ::init();
}
