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
    SetLong("This is the entrance to Orchard Park in Ackian Training Camp "+
        "07B.  There is a gate leading west of here, to Cherry Avenue.  "+
        "The grass here is immaculately cut and quite dense, broken "+
        "only by the trees here.  Toward the entrance they seem to be cherry "+
        "trees.");
    SetItems( ([
        ({"entrance","gate"}):"The gate to the west of here is made out of "+
            "some type of wood, tacked together and whitewashed.  It has"+
            "warped and sagged, making it impossible to close.",
        ({"park","orchard","garden","orchard park","here","room"}):"This is the entrance "+
            "to Orchard Park, the small park in Ackian Training Camp 07B.  ",
        ({"grass","floor","ground"}):"The grass is amazingly tidy, it even "+
            "gives the impression that all the blades are facing the same "+
            "direction and are in bed by eight, sharp.",
        ({"trees","tree","cherry trees"}):"These are tall, old, gnarly cherry trees.  "+
            "Instead of having cherries from the boughs, there are dozens "+
            "of clustered little signs.",
        ({"sign","signs","cherries","clusters","cluster"}):"There are small "+
            " groups of very tiny signs hanging from the trees where the cherries should be.",

      ]));
    SetRead(({"sign","signs"}), (: readSign :) );
    SetInventory(([
        "/domains/ATC/npc/bird" : 3,
      ]));
    SetExits( ([
        "northeast":"/domains/ATC/room/orchard2",
        "east":"/domains/ATC/room/orchard3",
        "southeast":"/domains/ATC/room/orchard4",
        "west":"/domains/ATC/room/cherry5",
      ]) );
      set_heart_beat(300);
}

 /* int CanReceive(object ob) {
    if(living(ob) && !creatorp(ob) && !present("pt pass",ob) && interactive(ob)) {
    	message("info","Creators and playtesting staff only, sorry.", ob);
    	return 0;
     }
    return room::CanReceive(ob);
} */

void init(){
    ::init();
    add_action("determined","close");
    add_action("determined","shut");
}

int determined(string str){
    if(str=="gate" || str=="gates" || str=="whitewashed gate"){
        write("You try pulling the west gate closed and then try pushing "+
            "it but all you end up doing is looking like a jackass who "+
            "can't close doors.\n");
            
        say(this_player()->GetCapName()+" pushes and pulls on the "+
            "gate to the west but can't get it to budge.\n");
         }
    else write("You stretch your arms out to close the " + str + " but "+
        "end up just looking foolish.");
}

void heart_beat(){
    if (sizeof(filter(objects(), (: base_name($1) == "/domains/ATC/npc/bird" :))) <= 5){
        new("/domains/ATC/npc/bird")->eventMove(this_object());
    }
}
