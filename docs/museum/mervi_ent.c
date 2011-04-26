#include <lib.h>

inherit LIB_ROOM;

static void create() {
    room::create();
    SetTown("Ackian Training Camp 07B");
    SetClimate("indoors");
    SetAmbientLight(40);
    SetShort("A house");
    SetLong("This is a small house in the northern part of Ackian Training Camp 07B.  This is the kitchen area "+
        "as well as where most time is spent - it features everything from a stove to a small bookshelf.  What's "+
        "really quite odd is just how tidy everything is.  Dishes are stacked from largest to biggest, the stove "+
        "has a total of zero grease spots, and the dining room table doesn't have so much as a speck of dust on it."+
        "There are no windows, but since there is no door in the doorway to the east, you can't imagine needing one.  "+
        "In addition to the stove and bookshelf, there are also some cabinets, a kitchen table, and a painting "+
        "that hangs lopsided on the south wall.  There is a door in the north wall.");
    SetItems(([
        ({"floor","ground",}):"The floor of the house are wide wooden planks, spaced far enough apart "+
            "to be able to see the dirt underneath.",
        ({"walls","wall"}):"The walls of the houses are made with roughly cut gray stone.",
        ({"house","houses","buildings"}):"The houses are long and single story.  The entrance to both of them lies just to the south.",
        ({"doorway","door"}):"The doorway is empty, which is odd since the Wastelands are usually fairly cold.",
        ({"painting","picture"}):"The painting on the south wall is tilted slightly.  Normally, this wouldn't be unusual, but "+
            "in a house as clean as this one it strikes you as odd.",
        ({"cabinet","cabinets","wooden cabinet","wooden cabinets"}):"The wooden cabinets are full of the usual household items: "+
            "dishes, flatware, roundware, and some small hand towels.",
        ({"dishes","dish"}):"The dishes in the cabinets are plain, but oddly not a single one seems to have a chip in it.",
        ({"flatware","forks","spoons","knives","fork","spoon","knife"}):"There is various flatware in the cabinets.  It doesn't seem "+
            "that smart to put sharp knives up above one's head, but perhaps the owner is exceptionally tall, or brave.",
        ({"roundware"}):"Yes, it's roundware.  Do you have a problem with that?",
        ({"towels","small towels","hand towels","small hand towels","small towel","towel","hand towel","small hand towel"}): "There are "+
             "around half a dozen small hand towels in the cabinet next to the dishes.",
        ({"counter"}):"There is a large wooden counter here with knife scores on it, showing it doubles as a cutting board.  Embedded in "+
            "the counter is a basin sink.",
        ({"sink","basin sink"}):"The large sink seems to be made of a thin layer of metal covering the inside of a hole carved into the "+
            "counter.  There is no faucet, or drain, but that isn't that unusual for a small town like this.",
        ({"stove","fireplace"}):"The stove is moreso just a fireplace with a grate above it.  What's odd is that there is no fireplace or "+
            "window, leading you to wonder how smoke escapes.",
        ({"bookshelf","shelf"}):"The bookshelf has no books on it.  In theme with the general tidyness of the home, perhaps it's because the "+
            "owner decided that having books would be too messy.",
        ({"table","kitchen table"}):"The kitchen table has no chairs around it, and is very small.",
        ({"door","north","north wall"}):"There appears to be a door in the north wall, but on closer examination, it is actually just "+
            "painting on.  How strange.",
    ]));
    SetExits(([
        "east":"/domains/ATC/room/ferdinand2",
    ]));

}
void init(){
    ::init();
    add_action("anal","adjust");
    add_action("anal","level");
    add_action("anal","nudge");
    add_action("anal","straighten");
    add_action("anal","move");
}


int anal(string str){
    if(str=="painting" || str=="picture" || str=="picture on the wall" ||
        str=="painting on the wall"){
        if(!this_player()->GetQuest("Picture Leveling")){
            this_player()->AddQuest("the Anal", "Picture Leveling");
            if(this_player()->GetActiveQuest("Picture Leveling")){
                this_player()->CompleteQuest("the Anal", "Picture Leveling");
            }
            write("You tweak the painting, adjusting it so it is level.\n\n");
            write("Congratulations, you have completed the \"Picture Leveler\" quest!\n\n");
            write("For it, you receive three quest points and some experience.  Don't you feel special?\n");
            write("But, let's put that picture back the way it was for the next person.\n");
            say(this_player()->GetCapName()+" pushes on the painting on the south wall carefully, leveling it.\n");
            say("After "+this_player()->GetCapName()+" adjusts the painting, "+
                 "it tilts itself again.");
            this_player()->AddExperiencePoints(2500);
            this_player()->AddQuestPoints(3);
         }
    else write("Hey, you already finished this quest.  Go away.");
    return 1;
    }
    else write("What do you want to move?");
}

