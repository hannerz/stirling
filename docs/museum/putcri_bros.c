#include <lib.h>
inherit LIB_SHOP;

int read_sign();
static void create() {
    ::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Putcri Brothers' Emporium");
    SetLong("This is the infamous Putcri Brothers' Emporium.  Well.  It's not "+
        "really famous, or much of anything.  There is a counter against "+
        "the south wall, and several tables scattered around.  There also "+
        "appears to be trap door in the floor near the counter, which "+
        "probably leads to the store room.\n"+
        "%^GREEN%^There is a sign on one of the tables.%^RESET%^");
    SetItems(([
        ({"store","shop","place","here","room","emporium",}):"This is Putcri "+
            "Brothers' Emporium, the general store near the train "+
            "station in Ackian Training Camp 07B",
        ({"sign","sign on table","sign on the table"}): "A sign on the "+
            "wall, meant for reading.",
        ({"table","tables"}):"There are lots of tables around, which were "+
            "probably meant to display the wares on.  Sitting on one of "+
            "the tables is a sign.",
        ({"counter"}):"There is a wooden counter against the south wall.  "+
            "Sam is standing in front of it.",
        ({"trap door"}):"There is a trap door in the floor in front of "+
            "the counter.",
    ]));
    SetInventory(([
        "/domains/ATC/obj/rbin" : 1,
        "/domains/ATC/npc/sam_putcri" : 1,
      ]));
    SetRead("sign", (: read_sign :) );
    SetExits( ([
        "northwest" : "/domains/ATC/room/cherry1",
        "down" : "/domains/ATC/room/putcri_bros_base",
      ]) );
}

int read_sign(){
    write("HOW TO CONDUCT BUSINESS HERE\n");
    write("list : Get a list of all the items Sam has for sale");
    write("appraise <item> : Ask Sam to tell you how much he would pay you for your item");
    write("price <item> : Ask Sam the price of his item");
    write("show <item> : Ask Sam for a closer look at his item\n");
    write("\nbuy <item> from sam\nsell <item> to sam\n");
    write("Cash only!");
    return 1;
}
void init(){
    ::init();
}
