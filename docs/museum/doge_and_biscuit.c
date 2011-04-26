#include <lib.h>
inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/doge_sign.txt");
    return 1;
}
static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("indoors");
    SetAmbientLight(25);
    SetShort("Doge and Biscuit");
    SetLong("This is a small dark bar in Ackian Training Camp 07B, fondly called the Doge and Biscuit.  It is here mainly to take newcomer's money and perhaps their sanity.  There are lots of candles, and oddly, no windows anyway.  An unventilated alcohol-serving building with lots of open flames.  Hmm.");
    SetItems(([
        ({ "building", "bar", "tavern", "pub", "here", "room" }) : "This is the Doge and Biscuit, a small pub off Cherry Avenue in Ackian Training Camp 07B.",
      ]));
    SetSmell(([
        ({ "here", "room", "bar", "tavern", "pub" }) : "It smells like brined eggs.",
      ]));
    SetExits(([
        "south" : "/domains/ATC/room/cherry4",
      ]));
    SetInventory(([
        "/domains/ATC/npc/gumpy" : 1,
      ]));
    SetRead("sign", (: readSign :) );
}
void init(){
    ::init();
}
