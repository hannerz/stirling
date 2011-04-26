#include <lib.h>
inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/terminal.txt");
    return 1;
}
static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("North Terminal");
    SetLong("This is the main room of the northern terminal in Ackian "+
      "Training Camp 07B.  There is a door to the east and west, while "+
      "north of here there are two sets of train tracks passing through "+
      "The middle of the building.  You see no way to get to the other "+
      "side of the tracks.  To the south is a large doorway that leads "+
      "outside.  There is a sign hanging from the ceiling, perhaps you "+
      "can read it?  A few Ackian Guards are milling about, giving you "+
      "the impression that this is perhaps a military barracks as well "+
      "as a train station.");
    SetItems( ([ ({"here","room","terminal","station","barracks",
        "train station"}):"This is a fairly bare-bones train station, it looks to have been assembled in a hurry.",
        ({"floor","ground","tile","grout"}):"The floor is red and white "+
            "tile, but there seems to be more grout than tile.",
        ({"sign"}):"There is a large sign suspended from the ceiling by chains.",
        ({"walls","wall"}):"The walls are painted with horizontal red and white stripes.",
        ({"ceiling"}):"The ceiling has been painted with red and white squares, matching the pattern on the walls.",
        ({"doors","door"}):"There are three doors here, which would you like to look at?",
        ({"east door","west door"}):"The east and west door are actually "+
            "just the frames - either the doors were never there, or they "+
            "have been removed.",
        ({"hinge","hinges"}):"The hinges on the doors here are made of "+
            "patinaed brass, showing they never had doors installed.",
        ({"frame","frames"}):"The door frames are made of a light "+
            "cheap looking wood and are empty except for the hinges.",
        ({"south door"}):"The southern door is perhaps the nicest part of the terminal.  Made of oak or somesuch, they "+
        "are around three meters tall, and are intricately carved with Ackian symbols.",
        ({"symbols","pickaxes","mines","mine tunnels","foundry","foundries"}):"There are symbols on the southern door, "+
        "and the predominate theme seems to be metal "+
        "crafting: pickaxes, mine tunnels, and foundries "+
        "are etched into the wood.",
        ({"tracks","train track","train tracks"}):"The train tracks are fairly new looking, but are blocked off by a wooden gate.",
        ({"gate","wooden gate"}):"There's a small wooden gate keeping you from walking down to the train tracks.  There's also a "+
        "very large and sturdy looking lock on the gate.",
        ({"lock","sturdy lock","large lock","large sturdy lock","sturdy large lock"}):"This is a very large lock that shuts the gate "+
        "leading onto the train tracks.",
        ({"guards"}):"There are a few guards walking around, all looking very important.",
        ({"chain","chains"}):"There are heavy iron chains, which are "+
            "necessary to hold up the heavy wooden sign.",
      ]) );
    SetInventory(([
        "/domains/ATC/npc/newbie_officer" : 1,
      ]));
    SetExits( ([
        "west" : "/domains/ATC/room/north_office",
        "south" : "/domains/ATC/room/ferdinand1",
        "east" : "/domains/ATC/room/north_barracks.c",
      ]) );
    SetAction(3, ({
        "A few soldiers walk from the room to the east to the room to the west with stacks of paper in their hands.",
        "Some soldiers walk from the west room to the room to the east with stacks of paper in their hands.",
        "You hear a few voices from outside the terminal.",
      }));
    SetRead("sign", (: readSign :) );
    SetProperty("no attack", 1);
}
void init(){
    ::init();
}
