from stirling.lib.obj.room import Room

class Cherry(Room):
    def __init__:
        super(Cherry, self).__init__()
        set_name('Cherry Avenue')
        set_long('This is Cherry Avenue, just east of the intersection '
	      'with Ferdinand Street.  To the south you can see the wall '
          'of a large building, with windows displaying merchandise, '
          'and to the north you can see a smaller building that looks '
          'to be a house.  The street continues a bit more to the east '
          'as well as west, and in the far distance to the east you '
          'can make out what looks to be a stone archway to a park.')
        # set_exits({'west':'world.dev.room.cherry1','east':'world.dev.room.cherry4'})
