#include <lib.h>


inherit LIB_ROOM;


static void create() {
    room::create();
    SetTown("Tayopopolous");
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("An office");
    SetLong("This is the main office for the northern train terminal "+
          "in Ackian Training Camp 07B.  It has a few cliche posters about "+
          "staying motivated tacked against the wall.  There's a fairly large "+
        "desk in the middle of the room, with paperworking forming a mountain "+
        "range on top. There's also a window, which lets you see outside.");

    SetExits( ([
        "east":"/domains/ATC/room/north_terminal",
      ]) );
    SetItems( ([ ({"here","room","office"}):"This is a pretty simple office, and makes it difficult to tell that "+
                         "just a few rooms away is a full barracks.",
                 ({"floor","ground"}):"The floor is red and white tile, but there seems to be more grout than tile.",
                 ({"walls"}):"The walls are painted with horizontal red and white stripes.",
                 ({"ceiling"}):"The ceiling has been painted with red and white squares, matching the pattern on the walls.",
                 ({"desk"}):"The desk has probably seem better days.  What it lacks in, well, grace, or design, or quality, "+
                            "or any other positive trait, it more than makes up for in nicks and scratches.",
                 ({"door","doors","doorway"}):"The door here is nonexistant - it's just a doorway, complete with hinges for the day"+
                                              "when someone decides to bring a door in.",
                 ({"papers","paperwork"}):"The paperwork is mounded on top of each other.  In one place two stacks even meet, "+
                                          "creating an arching helix Escher would be proud of.",
                 ({"arch","helix","arching helix"}):"Two stacks of paper have defied all physics and come together in a twisting arch.",
                 ({"mountain","mountain range","mountains"}):"Although actually paperwork, you're sure that from far off the mounds "+
                                                             "might be mistaken for snowcapped mountains.",
                 ({"window"}):"There is a window here, that lets you see out into the grasslands outside of town if you look "+
                             "out of it.",
                 ({"grasslands"}):"Outside the window you can see the tall grasses of the Wasteland, stretching on as far as you can see",
                 ({"posters","poster"}):"There are several motivational "+
                     "posters here, encouraging you to never give up and "+
                     "give impossible percentages.",
    ]) );
    SetAction(3, ({
        "A slight breeze comes in through the drafty window, threatening to send the paperwork flying.",
        "An officer dressed in heavy armor comes in through the door, "+
            "adds a few slips of paper to one of the stacks, before "+
            "carefully walking out again.",
    }));
    SetProperty("no attack", 1);
}
void init(){
    ::init();
}

