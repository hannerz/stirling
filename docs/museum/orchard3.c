#include <lib.h>

inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/underconst.txt");
    return 1;
}


static void create() {
    room::create();
    SetClimate("sub-arctic");
    SetAmbientLight(30);
    SetShort("Orchard Park");
    SetLong("This is Orchard Park just east of the entrance.  There "+
        "isn't too much here.  You can see the grass and more cherry trees, "+
        "and there is a small path heading east, marking the way forward "+
        "into the park.");
    SetItems( ([
        ({"park","orchard","garden","orchard park","here","room"}):"This is "+
            "slightly northeast of the entrance to Orchard Park.",
        ({"grass","floor","ground"}):"The grass is amazingly tidy, it even "+
            "gives the impression that all the blades are facing the same "+
            "direction and are in bed by eight, sharp.",
        ({"trees","tree","cherry trees"}):"These are tall, old, gnarly cherry trees.  "+
            "Instead of having cherries from the boughs, there are dozens "+
            "of clustered little signs.",
        ({"sign","signs","cherries","clusters","cluster"}):"There are small "+
            " groups of very tiny signs hanging from the trees where the cherries should be.",
        ({"path","road","lane"}):"There is a small dirt path heading east "+
            "from here."
      ]));
    SetRead(({"sign","signs"}), (: readSign :) );
    SetExits( ([
        "west" : "/domains/ATC/room/orchard1",
        "north":"/domains/ATC/room/orchard2",
        "south":"/domains/ATC/room/orchard4",
      ]) );

}