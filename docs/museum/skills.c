/* /lib/skills.c ~ 1.0
 * Canland LPC Library
 *    This handles skills, stats, and bonuses that commands and skillchecks
 *    go through.
 * ~~~~~~~~~~~~~~~
 * History
 *     080529 emsenn@Canland: Created
 */

/*
      Emsenn. Enough with the sarcastic commenting.
        ~Percussor
 */
#include <lib.h>
#include <daemons.h>
#include "include/skills.h"

inherit LIB_LEVEL;
/* Declares the two mappings we'll be working with here, one for skills, 
   one for stats.  Think you can figure out which is which?  (Hint: the
   one for skills starts with a 's'. */
mapping Skills = ([]);
mapping Stats = ([]);
int counter = 0;
/* Returns the Skills mapping in its entirety.  Why you would want to 
   look at that beast is beyond me, but hell, it's there if you want it. */
mixed GetSkillsMap(){
    return Skills;
}
string array GetSkills() {
    return keys(Skills);
}
/* Returns the mapping of a single skill.  For example, GetSkillMap("long")
   would return (["level" : 9, "points" : 23, "bonus" : 320, "statbase" :
   (["dexterity" : 3, "strength" : 4, "coordination" : 3])]) */
mixed GetSkillMap(string skill){
    if(!Skills[skill]){
        return -1;
    }
    return Skills[skill];
}
/* Simple enough, returns the level of a skill. */
int GetSkillLevel(string skill){
    if(!Skills[skill]){
        return -1;
    }
    return Skills[skill]["level"];
}
/* Another function I'm not sure why you'd need, but hey, it's here. */
mixed GetSkillStatBase(string skill){
    if(!Skills[skill]){
        return -1;
    }
    return Skills[skill]["statbase"];
}
/* Hey, a function that doesn't just return a variable without
   manipulation!  Finally!   Manages diminishing returns  for
   skills, it does.*/
int GetSkillBonus(string skill){
    float bonus;
    int stattotal;
    string *statkeys;
    mapping mp = ([]);
    mp = GetSkillStatBase(skill);
    statkeys = keys(GetSkillStatBase(skill));
    foreach(string frog in statkeys){
        stattotal = stattotal + (GetStat(frog)*Skills[skill]["statbase"][frog]);
    }
    bonus = (((sqrt(10*(Skills[skill]["level"]*to_float(stattotal))+1))/2)-1);
    Skills[skill]["bonus"] = to_int(bonus);
    return bonus;
}

/* This one simply returns how many points the skill has - points are
   trained naturally through use, and represent a fraction of a level. */
int GetSkillPoints(string skill){
    if(!Skills[skill]){
        return -1;
    }
    return Skills[skill]["points"];
}


int AddSkill(string skill, string type,  mapping statbase){
    Skills[skill] = (["type": type, "statbase" : statbase, "level" : 0, "bonus" : 0]);
    return Skills[skill];
}

/* This function adds level(s) to the skill.  Simple enough. */
int AddSkillLevel(string skill, int amt){
    if(!Skills[skill]){
        return -1;
    }
    Skills[skill]["level"] = amt;
    return Skills[skill]["level"];
}

int GetMaxSkillPoints(string skill){
    return ((((sqrt(3.0 * Skills[skill]["level"]/to_float(500) + 1.0) - 1.0) / 2.0)*Skills[skill]["level"])*500);
}
/* This adds point(s) to the skill.  Also checks to see if the points
   pass a certain threshold, and if so, resets them and adds a level
   to that skill instead. */
int AddSkillPoints(string skill, int x) {
    if(!Skills[skill]) {
        return 0;
    }
    Skills[skill]["points"] += x;
    while( Skills[skill]["points"] < 0 ) { /* lost skills! */
        if( Skills[skill]["level"] == 1 ) {
            Skills[skill]["points"] = 0;
        }
        else {
            int tmp;

            tmp = --Skills[skill]["level"];
            Skills[skill]["points"] = 0;
        }
    }
    if(Skills[skill]["points"] >= GetMaxSkillPoints(skill)){
        write("%^YELLOW%^You are a bit more adept at using " +
            skill + ".%^RESET%^");
        Skills[skill]["level"]++;
        Skills[skill]["points"] = 0;
    }
    return Skills[skill]["points"];
}

int SetSkillLevel(string skill, int level){
    if(!Skills[skill]) {
        return 0;
    }
    Skills[skill]["level"] = level;
    return Skills[skill]["level"];
}

int SetSkillPoints(string skill, int points){
    if(!Skills[skill]) {
        return 0;
    }
    Skills[skill]["points"] = points;
    return Skills[skill]["points"];
}
/* Returns the entire Stats mapping.  Again, I don't see a need for it,
   but it's there. */
mixed GetStatMap(){
    return Stats;
}

/* Returns the value of a stat.  Can't say much more about this one. */
int GetStat(string stat){
    if(!Stats[stat]){
        return 0;
    }
    return Stats[stat];
}

/* Adds value to the stat, or creates it if it doesn't exist. */
int AddStat(string stat, int amt){
    if(!Stats[stat]){
        Stats[stat] += amt;
        return Stats[stat];
    }
    Stats[stat] += amt;
    if(Stats[stat] < 0){
        Stats[stat] = 0;
    }
    return Stats[stat];
}

/* Sets an already existing stat to a value, or creates the stat and sets
   it to that value. */
varargs int SetStat(string stat, int level, string clas){
    Stats[stat] = level;
    return Stats[stat];
}

mixed eventTrainSkill(string skill, int bonusdiff){
    if(bonusdiff < -75){
        AddSkillPoints(skill, 3);
        return 1;
    }
    if(bonusdiff >= -75 && bonusdiff < -25){
        AddSkillPoints(skill, 2);
        return 1;
    }
    if(bonusdiff >= -25){
        AddSkillPoints(skill, 1);
        return 1;
    }
}

static void create() {
}
