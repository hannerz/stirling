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
    SetLong("This is Orchard Park just northeast of the entrance.  There "+
        "isn't too much here.  You can see the grass and more cherry trees, "+
        "and to the northwest is a tall stone wall that marks the boundaries "+
        "of Orchard Park, as well as the boundary of the Training Camp.");
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
        ({"wall","walls"}):"To the northwest and stretching off southwest "+
            "and northeast of here is a white stone wall that has been "+
            "painted a sickeningly bright shade of green."
      ]));
    SetRead(({"sign","signs"}), (: readSign :) );
    
    SetExits( ([
        "southwest" : "/domains/ATC/room/orchard1",
        "south":"/domains/ATC/room/orchard3"
      ]) );
}

