/*    /secure/daemon/kinetics
 *    from the CanLAND LPC Library
 *    manage faction and town stats
 *    created by tay@CanLAND 080613
 *    Version: @(#) combat.c 1.40@(#)
 *    Last modified: 08/06/13
 */
#include <lib.h>
#include <save.h>
#include <privs.h>
#include <daemons.h>

inherit LIB_DAEMON;

private mapping FactionStats = ([]);
private mapping TownStats = ([]);
private string path;
static string save_file;

mixed GetFactionStat(string org, string type);
int SetFactionStat(string org, string type, int x);
int AddFactionStat(string org, string type, int x);
mixed GetTownStat(string org, string type);
int SetTownStat(string org, string type, int x);
int AddTownStat(string org, string type, int x);
string FindOwner(string town);
mixed eventChangeOwner(string town);
void reloadthisob(string ob);
void eventDaily();


static void create() {
    daemon::create();
    if( !save_file ) save_file = "secure/save/kinetics";
    restore_object( save_file );
    SetNoClean(1);
}

/* Returns the value of org's score in type. */
mixed GetFactionStat(string org, string type){
    return FactionStats[org][type];
}

/* Sets a faction's stat to x.  If 0 > x < 100000, sets it to whichever  limit it exceeded. */ 
int SetFactionStat(string org, string type, int x){
    org = lower_case(org);
    type = lower_case(type);
    if(!FactionStats[org]){
        FactionStats[org] = (["gold":1]);
    }
    if(x < 0){
        x = 0;
    }
    if(x > 10000000){
        x = 10000000;
    }
    FactionStats[org] += ([type: x ]);
    unguarded( (: save_object(save_file) :) );
    return FactionStats[org][type];
}

/* Adds to a town's stat in x.  Again, if 0 > x < 100000, sets it to
   the exceeded limit. */
int AddFactionStat(string org, string type, int x){
    if(x > 10000000){
        x = 10000000;
    }
    if(!FactionStats[org] || !FactionStats[org][type]){
        SetFactionStat(org, type, x);
        return FactionStats[org][type];
    }
    FactionStats[org][type] += x;
    if(FactionStats[org][type] < 0){
        FactionStats[org][type] = 0;
    }
    unguarded( (: save_object(save_file) :) );
    return FactionStats[org][type];
}

/* Returns the value of org's score in type. */
mixed GetTownStat(string org, string type){
    return TownStats[org][type];
}

/* Sets a faction's stat to x.  If 0 > x < 100000, sets it to whichever
   limit it exceeded. */ 
int SetTownStat(string org, string type, int x){
    org = lower_case(org);
    type = lower_case(type);
    if(!TownStats[org]){
        TownStats[org] = (["gold":1]);
    }
    if(x < 0){
        x = 0;
    }
    if(x > 10000000){
        x = 10000000;
    }
    TownStats[org] += ([type: x ]);
    unguarded( (: save_object(save_file) :) );
    return TownStats[org][type];
}

/* Adds to a faction's stat in x.  Again, if 0 > x < 100000, sets it to
   the exceeded limit. */
int AddTownStat(string org, string type, int x){
    if(x > 10000000){
        x = 10000000;
    }
    if(!TownStats[org] || !TownStats[org][type]){
        SetTownStat(org, type, x);
        return TownStats[org][type];
    }
    TownStats[org][type] += x;
    if(TownStats[org][type] < 0){
        TownStats[org][type] = 0;
    }
    unguarded( (: save_object(save_file) :) );
    return TownStats[org][type];
}


/* Okay, this next function is pretty ugly.  What it does, is check to see who
   owns a town, if anyone. */
string FindOwner(string town){
    /* Declare your variables. */
    string *factions = keys(FactionStats), owner;
    int *scores, *unsortedscores, x, *y, i, length;
    mapping TmpStats = ([]);
    /* Checks the level of each faction's stats, then adds them up, then
       adds in their score for the town. */
    foreach(string fact in factions){
        y = values(FactionStats[fact]);
        for(i=0; i<sizeof(y); i++ ){
            x=x+y[i];
        }
        TmpStats[fact] = x+(GetFactionStat(fact,town)*5);
    }
    /* Gives some of our earlier declared variables some meaning. */
    factions = keys(TmpStats);
    scores = sort_array(values(TmpStats),-1);
    unsortedscores = values(TmpStats);
    length = sizeof(scores);
    /* Checks to see which faction has the highest score.  Whoever does, sets
       them to be the owner of the town. */
    for(int j = 0; j < length; j++){ 
        if(scores[0]== unsortedscores[j]){ 
            owner = factions[j];
            break;
        }
    }
    /* But wait, what if they just barely are more powerful?  Well, this
       checks, and if no one has a clean lead, sets the town owner to riot. */
    if(scores[0]-scores[1] <= 5000){
        owner = "riot";
    }
    if(GetTownStat(town,"owner") != owner){
        TownStats[town]["owner"] = owner;
        eventChangeOwner(town);
    }
    return owner;
}
/* Simply reloads the loaded portions of a town if it's owner changes. */
void eventChangeOwner(string domain){
    path = "/domains/"+domain+"/";
    foreach(object ob in objects()){
        if(strsrch(base_name(ob),path) != -1){
            reload(base_name(ob),0,1);
        }
    }
    unguarded( (: save_object(save_file) :) );
}
