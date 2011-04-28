#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("This is the eastern most end of Cherry Avenue.  To the "+
        "north and south are vacant lots with many weeds growing "+
        "in them.  To the east is the main part of town, and immediately "+
        "to the west is Orchard Park, a lovely little park in the "+
        "Ackian Training Camp.");
    SetItems( ([ ({"here","room"}):"Cherry Avenue, just west of Orchard Park.",
        ({"floor","ground","street","stone","stones","road"}):"The street here is paved with smooth white stones.",
        ({"park","orchard","garden","orchard park","orchard garden"}):"To "+
            "the east is Orchard Park, a lovely grassy park with lots of "+
            "large fruit trees, all neatly lined up.",
        ({"lot","lots"}):"To both the north and south are vacant lots, "+
            "roughly house-sized.  Makes you wonder what might be going "+
            "there.",
      ]) );
    SetExits( ([
        "west" : "/domains/ATC/room/cherry4",
        "east" : "/domains/ATC/room/orchard1",
      ]) );
    SetAction(5, ({
        "You hear the pleasant twitter of birds.",
      }));
}
int CanReceive(object ob) {
    if(living(ob) && !interactive(ob)){
        message("info","Offlimit for NPCs, sorry.", ob);
        return 0;
    }
    return room::CanReceive(ob);
}
void init(){
    ::init();
}
