#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("North Barracks");
    SetLong("This is a small barracks.  In fact, it might not even be a barracks.  Seems to be much more like a bedroom, "+
            "just happens to have a few extra beds laying around.  Oh, and of course the weapon racks aren't in many "+
            "bedrooms, at least not inside the Empire.");
    SetItems(([
        ({"floor", "ground"}):"The floor is red and white tile, but there seems to be more grout than tile.",
        ({ "walls", "wall"}):"The walls are painted with horizontal red and white stripes.",
        ({ "sign" }) : "There is a large sign suspended from the ceiling by chains.",
        ({"door","doors","doorway"}):"The door here is nonexistant - it's just a doorway, complete with hinges for the day"+
            "when someone decides to bring a door in.",
        ({"here","room","barracks"}):"This is a fairly bare barracks.  Cots and weapon racks, and not much else.",
        ({"ceiling"}):"The ceiling has been painted with red and white squares, matching the pattern on the walls.",
        ({"beds","bed","cot","cots"}):"A few cots are scattered about the room.  They look like they have all been freshly rearranged.",
        ({"rack","racks","weapon rack","weapon racks"}):"There are a few weapon racks around, but they looked picked clean of any weapons. "+
            "Probably a side effect of not having a door in the doorway.",
      ]));
    SetProperties(([
        "no attack" : 1,
      ]));
    SetAction(3, ({
        "A soldier walks in, looks to make sure that the weapon racks "+
            "are still empty, nods approvingly, and walks out.",
      }));
    SetExits(([
        "west":"/domains/ATC/room/north_terminal",
      ]));

}
void init(){
    ::init();
}
