#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("This is Cherry Avenue, shortly before it reaches a market .  "+
        "Unfortunately, the market looks to be closed.  Probably has "+
        "something to do with the barrier blocking the road.");
    SetItems(([
        ({"here","room"}):"This is a length of Cherry Avenue somewhat "+
            "west of its intersection with Ferdinand Street.",
        ({"floor","ground","street","stone","stones","road"}):"The street "+
            "here is paved with smooth white stones.",
        ({"barrier","fence","blockade"}):"There is a concrete blockade "+
            "completely blocking off the market to the southeast.  Aww.",
        ({"market","bazaar","southwest"}):"There is an empty market to "+
            "the southwest, but it is blocked off by a large concrete "+
            "blockade.",
        ({"cherry avenue"}):"Cherry Avenue opens into the market "+
            "southwest of here and goes to the northeast.",
      ]));
    SetExits(([
        "northeast":"/domains/ATC/room/cherry2",
      ]));

}
void init(){
    ::init();
}
