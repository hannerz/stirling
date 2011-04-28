#include <lib.h>
inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Putcri Brothers' storage");
    SetLong("This is the Putcri Brothers' storage room.");
    SetInventory(([
        "/domains/ATC/armor/belt" : 3,
        "/domains/ATC/armor/goldish_ring" : 5,
        "/domains/ATC/armor/guard_bandana" : 5,
        "/domains/ATC/armor/rusty_chainmail_shirt" : 10,
        "/domains/ATC/obj/small_bag" : 20,
        "/domains/ATC/obj/copper_canteen" : 5,
        "/domains/ATC/obj/match" : 25,
        "/domains/ATC/obj/torch" : 10,
        "/domains/ATC/weap/paddle" : 5,
        "/domains/ATC/weap/butcher_knife" : 10,
        "/domains/ATC/weap/dagger" : 20,
        "/domains/ATC/weap/gladius" : 5,
        "/domains/ATC/weap/hand_axe" : 10,
        "/domains/ATC/weap/knife" : 10,
      ]));
    SetNoClean(1);

    SetExits( ([
        "up" : "/domains/ATC/room/putcri_bros",
      ]) );
}
int CanReceive(object sneak) {
    object *living_stack = get_livings(sneak);
    if(!living_stack || !arrayp(living_stack)) living_stack = ({ sneak });
    foreach(object ob in living_stack){
        if(playerp(ob) && !creatorp(ob) && !present("testchar badge",ob) &&
          !member_group(ob,"TEST")) {
            message("info","Putcri Brothers' back room is for authorized personnel only.", ob); 
            return 0;
        }
    }
    return 1;
}
void init(){
    ::init();
}
