/*    /daemon/.c
 *    from the Canland LPC Library
 *    handles NPC's knowledge base
 *    created by tay@CanLAND 080618
 */
#include <lib.h>
#include <save.h>
#include <privs.h>
#include <daemons.h>

inherit LIB_DAEMON;

private string save_file;
/* Knowledge is the mapping of all Knowledge, phrases, and responses in
   the chatter database.
*/
mapping Knowledge = ([]);
/* Rules is the guideline of what needs to be replaced in incoming
   messages to allow the NPCs to easily parse it.
*/
mapping Rules = ([]);
/* This gets set to whatever object is calling this.
*/
object bot;

int AddKnowledge(string key, string message, string *response);
mixed GetKnowledge();
string Analyze(string str);
string Cleanup(string str);
string KnowledgeSearch(string message);

static void create() {
    daemon::create();
    if( !save_file ) save_file = "/save/chatter";
    restore_object( save_file );
    SetNoClean(1);
}
/* Called in /lib/sentient when before you send the message, is used to
   check what level, if any, the object has in various AI types.
*/
void SetCurrentTalker(object ob){
    bot = ob;
}

/* This is the function for adding information to the Keys mapping.
   The syntax is fairly straightforward.  Lets say I wanted to have a
   a way for an NPC to reply to a player asking "Tell me about the CanLAND
   Mud", and have a variety of responses, such as "What do you mean, mud?
   Canland is a planet!" or "It's a small mud running on Dead Souls, and
   is set in a planet shaped like a tin can."  You would type:
       AddKey("canland mud","tell about canland mud",({"What do you mean,
       mud?  Canland is a planet!","It's a small MUD running on Dead Souls,
       and is set on a planet shaped like a tin can."}));
   Now, if an NPC has a SetAI("canland mud",0) they'll say they don't know
   what mud you're talking about when someone asks, tell me about the canland.
   In actuality the order of responses has a  bit more sense to it like that,
   for example, the recommended order for something related to factions is
   0 is objective, 1 is lowranking member who likes it, 2 is lowranking member
   who dislikes it, 3 is midranking member who likes it, and so on.  For a 
   complete guideline to all NPC AI levels and what they mean, view the
   building AI guide on the website.
*/
int AddKnowledge(string key, string message, string *responses){
    key = lower_case(key);
    message = lower_case(message);
    /* We check see what's present of that key, and depending, either
       create it or add to it.
    */
    if(!Knowledge[key] || !Knowledge[key][message]){
    if(!Knowledge[key]){
    	Knowledge[key] =([]);
    }
        Knowledge[key] += ([message: responses ]);
        unguarded( (: save_object(save_file) :) );
        return 1;
    }
    Knowledge[key][message] += responses;
    unguarded( (: save_object(save_file) :) );
    return 1;
}
/* Returns a copy of the Knowledge mapping. */
mixed GetKnowledge(){
    return copy(Knowledge);
}
/* This allows you to add new rules to the chatter's parsing.  You can add
   rules in two forms, one as an array of strings and a string, or as two
   strings.  One use of the Rules is to simply synonyms, such as:
       AddRule(({"police","solider","cop"}),"guard");
   Another use is to simplify common phrases, such as:
       AddRule("tell me all about","tell about");
*/
int AddRule(mixed start, string change){
    /* The following is run if start is an array.
    */
    if(arrayp(start)){
    int length = sizeof(start);
        for(int j = 0; j < length; j++){ 
                if(!Rules[start]){
    	            Rules[start[j]] =([]);
                }
            Rules += ([start[j]:change]);
        }
    }
    /* And this goes if start is just a string.
    */
    if(stringp(start)){
        if(!Rules[start]){
    	    Rules[start] =([]);
        }
        Rules += ([start:change]);
    }
    unguarded( (: save_object(save_file) :) );
    return 1;
}

/* Returns a copy of the Rules mapping.
*/
mixed GetRules(){
    return copy(Knowledge);
}

/* This takes what the NPC heard and returns the reply, if any.
*/
string Analyze(string message) {
    string reply = message;
    /* Sends the message to the Cleanup() function to be turned into
       simpler text - such as changing synonyms to a standard word,
       or simplifying phrases.
    */
    reply = Cleanup(reply);
    /* This takes our newly cleaned up message and turns reply from
       the incoming message to the reply.
    */
    reply = KnowledgeSearch(reply);
    return reply;
}

string Cleanup(string message){
    string *words = keys(Rules);
    int length = sizeof(words);
    /* Simply runs through each of the rules looking for a match, and
       if there is one, changes the message appropriately.
    */
    for(int j = 0; j < length; j++){ 
        if(strsrch(message,words[j]) != -1){
            message = replace_string(message,words[j],Rules[words[j]]);
        }
    }
    return message;
}

/* The guts of the chatter daemon, this is what takes the cleaned up
   message and outputs the response.  There's not much more I can say
   here - there's more detailed comments in the code.
*/
string KnowledgeSearch(string message){
    string *keylist, *phraselist, *replylist, phrase, topic, reply;
    mapping TmpMap = ([]);
    int level, length;
    /* The first step of finding our reply is seeing if the message
       even has a topic that's in the knowledge base. */
    keylist = keys(Knowledge);
    length = sizeof(keylist);
    if(grepp(message,"po:")){
        return "";
    }
    /* This checks each key of the Knowledge mapping to see if the
       message has any of them, and if it hits one, sets the topic
       of the message to that key, and moves on.
    */
    for(int j = 0; j < length; j++){ 
        if(strsrch(message,keylist[j]) != -1){
            topic = keylist[j];
            /* Gets us ready for the next function by setting the
               phrase list to the phrases for that topic. */
            phraselist = keys(Knowledge[topic]);
            break;
        }
    }
    /* If the message didn't have a topic, end the process here by
       returning a blank string.
    */
    if(!topic){
        return " ";
    }
    /* We've determined the topic of our message - now it's time
       to see if we've got any phrases for that topic that match
       the message.
    */
    length = sizeof(phraselist);
    /* Checks the keys of the topic in the Knowledge mapping -
       essentially works the same way as how we found our topic.
    */
    for(int j = 0; j < length; j++){ 
        if(strsrch(message,phraselist[j]) != -1){
            phrase = phraselist[j];
            /* Sets up the reply list for all the replies of this phrase
            */
            replylist = Knowledge[topic][phrase];
            break;
        }
    }
    /* Our message had a topic, but no phrases were hit.  Time to
       stop the searching and return a blank string.
    */
    if(!phrase){
        return " ";
    }
    /* This does the most important part, from a player perspective:
       gives the NPC something to say!  First, it checks to see what
       the NPC's level is in our topic at hand.  Then, checks to make
       sure there is a message for the phrase we've got at that level,
       and if not, the NPC tells the player to bug them.  If there is
       a response though, we write it.
    */
    level = bot->GetAIType(topic);
    if(!Knowledge[topic][phrase][level]){
        return "say I seem to have a bug with my AI - could you "+
            "please bug me, and include what you said to get this"+
            "message?";
    }
    reply = Knowledge[topic][phrase][level];
    return reply;
}
