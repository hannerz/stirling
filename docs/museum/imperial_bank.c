#include <lib.h>
inherit LIB_BANK;

int ReadSign();
static void create() {
    bank::create();
    SetClimate("indoors");
    SetTown("Ackian Training Camp 07B");
    SetAmbientLight(30);
    SetShort("Imperial Bank");
    SetLong("You are standing in one of several branches of the Imperial "+
        "Bank.  This one is in Ackian Training Camp 07B, and looks to be "+ 
        "the only well constructed building in the entire town.  It has "+
        "lovely white, blue-veined marble flooring.  There is a very "+
        "nice red carpet leading from the entrance to the main counter.  "+
        "Standing behind the counter, safely behind metal bars, is "+
        "Zoe, the bank teller.\n"
        "%^GREEN%^There is a sign hanging here.%^RESET%^");
    SetInventory( ([
        "/domains/ATC/npc/zoe" : 1
      ]) );
    SetItems( ([
        ({"sign"}):"A sign you can read.",
        ({"bank","imperial bank","here","room"}):"The primary financial "
        "institution in town, and indeed, the Empire.",
        ({"floor","floors","marble floor","marble floors","ground",
            "flooring"}):"The floor is lusterous, clean, and "+
            "beautiful.",
        ({"carpet","red carpet"}) : "A thick, fine red carpet "
        "leads from the bank entrance to the main counter.",
        "entrance" : "The entrace of the bank.",
        ({"counter","main counter"}) : "An elaborate affair crafted "+
            "from fine grained cherry, this counter is what separates "+
            "you from other people's money.",
      ]) );
    SetExits( ([ 
        "east" : "/domains/ATC/room/ferdinand3",
      ]) );
    SetRead( ({"sign","sign hanging here"}) , (: ReadSign :) );
    SetProperty("no attack", 1);
    SetAction(3,({
        "Standing here, you can just feel your pockets getting "+
            "lighter.",
    }));
}
int ReadSign(){
    write( @EndText
    - This bank requires a minimum balance to open an account.
      To use any of the bank's services, you must first open an
      account (see below as to how).

    - This bank charges for certain transactions, such as
      currency exchange.

      To conduct business here:

      request account from TELLER
      request balance from TELLER
      ask TELLER to deposit AMOUNT CURRENCY
      ask TELLER to withdraw AMOUNT CURRENCY
      ask TELLER to exchange AMOUNT CURRENCY for CURRENCY

      examples:

      %^GREEN%^request account from zoe%^RESET%^
      %^CYAN%^>
      You request account from Zoe.
      You deposit 5 copper and open an account with Imperial Bank.%^RESET%^

      %^GREEN%^request balance from zoe%^RESET%^
      %^CYAN%^You request balance from Zoe.
      Your account with Imperial Bank was opened Sun May 18 19:15:25 2008.
      This location's default currency is copper.

      copper               : 5
                             ----------
      Total in copper        5%^RESET%^

      %^GREEN%^ask zoe to deposit 100 copper%^RESET
      %^CYAN%^You deposit 100 copper into your account.%^RESET%^

      %^GREEN%^ask zoe to withdraw 10 silver%^RESET%^


      ask zoe to exchange 10 gold for silver

EndText
    );
    return 1;
}

void init(){
    ::init();
}
