#include <lib.h>

inherit LIB_ROOM;

int readSign() {
    this_player()->more("/domains/ATC/txt/underconst.txt");
    return 1;
}


static void create() {
    object ob;
    room::create();
    SetClimate("sub-arctic");
    SetAmbientLight(30);
    SetShort("Orchard Park");
    SetLong("This is Orchard Park just a ways southeast of the entrance.  "+
        "There are cherry trees and neatly cut grass, and a hideous "+
        "stone wall painted bright green runs from the northwest to the "+
        "southeast.");
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
        ({"wall"}):"There is a hideous stone wall painted bright green that "+
            "runs northwest and southeast of here, marking the end of "+
            "Orchard Park."
      ]));
    SetRead(({"sign","signs"}), (: readSign :) );
    SetExits( ([
        "north":"/domains/ATC/room/orchard3",
        "northwest":"/domains/ATC/room/orchard1",
      ]) );
}