#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Ferdinand Street");
    SetLong("This is a Ferdinand, a fairly narrow street that leads north into the northern train terminal of "+
            "Ackian Training Camp 07B.  To either side of the street are the facades of two stone houses.  "+
            "The street itself is made up of flat stones that look like some sort of white slate.  To "+
            "the south, Ferdinand continues until it intersects with a larger street.");
    SetItems(([
        ({"here","room"}):"This is the northern end of Ferdinand Street in Ackian Training Camp 07B.",
        ({"floor","ground","street","stone","stones","road","slate"}):"The street here is paved with smooth white stones.",
        ({"walls","wall"}):"The walls of the houses are made with roughly cut gray stone.",
        ({"house","houses"}):"The houses are long and single story.  The entrance to both of them lies just to the south.  "+
                             "Aside from the door, you can not see any other opening in the houses, not even windows or a chimney.",
        ({"terminal"}):"The train terminal is directly north of here, with the annexed barracks rising higher than any "+
                       "surrounding building.",
        ({"building","buildings"}):"There are three buildings here, which one did you want to look at?",
        ({"facade","facades"}):"There two buildings facing the street "+
            "here, but the entrances are a bit further south.",
        ({"ferdinand street"}):"Ferdinand Street continues south of here.",
      ]));
    SetExits(([
        "north":"/domains/ATC/room/north_terminal",
        "south":"/domains/ATC/room/ferdinand2",
      ]));
    SetAction(3,({
        "A few people exit the building to the north, looking dazed "+
            "and confused.",
    }));
}
void init(){
    ::init();
}
