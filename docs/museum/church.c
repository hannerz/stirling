#include <lib.h>
inherit LIB_ROOM;

int ReadSign(){
    write(
        "%^MAGENTA%^"+
        "                     THE IMPERIAL CHURCH                    "+
        "%^RESET%^\n\n"+
        "    The Imperial Church is the governing body of the Empire,\n"+
        "as well as being the state religion.  There are two main gods\n"+
        "to the religion: Ayearess, the Goddess of Taxes, and Efflare,\n"+
        "God of Death.  If you choose to join the Imperial Church when\n"+
        "you leave the Training Camp, you can expect to learn many of\n"+
        "the social skills necessary for spreading the message of the\n"+
        "church, as well as the arcane skills necessary to take full\n"+
        "advantage of the rituals and rites granted to you by the gods.\n"
    );
    return 1;
}

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("The Imperial Church, Ackian Training Camp 07B");
    SetLong("This is the Imperial Church in town.  It is a fairly "+
        "simple affair, yet shows that the Church obviously pays "+
        "careful attention to each building they erect.  There are "+
        "smooth white plaster columns supporting a crisply white ceiling.  "+
        "The walls are painted with pastel murals of the various forms of "+
        "tax supported by the Church.  There is a sign here that explains "+
        "about the Imperial Church.");
    SetItems(([
        ({"paintings","painting","mural","murals","art","emblem"}):"The "+
            "eidetic emblems explicate the excises the Empire exercises on "+
            "its enfranchised entities.  That is, they're pretty pictures "+
            "of different kinds of taxes: sales, income, tariff, "+
            "transfer, and property.  You can \"look\" at "+
            "each type of tax.",
        ({"sales","sales tax"}):"The emblem for sales tax depicts someone "+
            "who looks to be an employee of the Gemini Mining Company "+
            "standing at a store counter, attempting to buy a pair of "+
            "boots, but being stopped as he has to count out a few extra "+
            "coppers to cover the 6.35% sales tax the Church enforces.",
        ({"sign"}): "There is a sign hanging from the east wall.  It "+
            "seems like reading it would be a good idea.",
      ]) );
    SetRead( ({"sign"}) , (: ReadSign :) );
    SetExits( ([
        "west" : "/domains/ATC/room/market1",
      ]) );
    SetInventory( ([
      ]) );
}

void init(){
    ::init();
}
