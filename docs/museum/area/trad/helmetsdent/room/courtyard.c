inherit S_ROOM;

void create(){
    set_name("small courtyard");
    set_desc("This is a small courtyard, enclosed by a gray stone wall about "
      "three meters high.");
    set_exits(([
        "west":__DIR__+"cafe",
      ]));
}
