inherit S_ROOM;

void create(){
    set_name("cafe");
    set_desc("This is a cafe.");
    set_exits(([
        "east":__DIR__+"courtyard",
      ]));
}
