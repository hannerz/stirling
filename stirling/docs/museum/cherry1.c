#include <lib.h>

inherit LIB_ROOM;

int readSign(){
    write( @EndText
%^BLUE%^Putcri Brothers' Emporium%^RESET%^
Home of all your shopping needs!

EndText
    );
    return 1;
}

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("sub-arctic");
    SetAmbientLight(40);
    SetShort("Cherry Avenue");
    SetLong("This is Cherry Avenue, a wide street that runs through the middle of the Training Camp.  To the "+
      "north and south is Ferdinand Street, which, on the north end, features the northern train terminal.  "+
      "The street is paved with white stone.  To the southeast is a larger building with a sign out from. "+
      "A little bit south of here, Ferdinand Street abruptly ends.");
    SetItems(([
        ({"here","room"}):"This is the intersection of Ferdinand Avenue running from the north and south with Cherry "+
        "Avenue, heading east and west.",
        ({"floor","ground","street","stone","stones","road"}):"The street here is paved with smooth white stones.",
        ({"walls","wall"}):"The walls of the buildings. are made with roughly cut gray stone.",
        ({"house","houses"}):"To the north you can see two houses on either side of the street.",
        ({"large building","store","shop"}):"The building to the southeast has large windows in front, showcasing what it's "+
        "selling.  Hm, guess it must be a store.",
        ({"window,windows"}):"The windows in the store southeast of here are showing various goodies, from swords to jewelry",
        ({"swords"}):"The swords displayed in the window seem to be the kind you would get if you took a mediocre sword, hammered "+
        "it into a plow, and then turned it back into a sword.",
        ({"jewelry","jewellery"}):"The jewelry on display looks like copper painted yellow.",
        ({"building","buildings"}):"There are three buildings here, which one did you want to look at?",
        ({"terminal","station","train station"}):"In the distance to the "+
            "north you can make out a small train station.",
        ({"cherry avenue"}):"Cherry Avenue continues east and west from here",
        ({"ferdinand street"}):"Ferdinand Street continues north from here "+
            "to a train station, and south where it abruptly ends.",
        ({"sign"}):"There is a large wooden sign with something written "+
            "on it.  Chances are good you can \"read sign\".",
      ]));
    SetExits( ([
        "west" : "/domains/ATC/room/cherry2",
        "east" : "/domains/ATC/room/cherry3",
        "north" : "/domains/ATC/room/ferdinand2",
        "southeast" : "/domains/ATC/room/putcri_bros",
        "south" : "/domains/ATC/room/ferdinand3.c",
      ]) );
    SetRead("sign", (: readSign :) );
    SetAction(3,({
        "A cat crawls by covertly."
    }));
}


void init(){
    ::init();
}
