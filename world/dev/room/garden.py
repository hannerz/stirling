'''
/world/dev/room/garden.py
emsenn@Stirling
250411

Part of the test suite, this is an example garden.  At the moment it simply 
demonstrates available room functions, nothing special.
'''

from stirling.obj.room import Room

class Garden(Room):
    def __init__(self):
        super(Garden, self).__init__()
        self.set_name('peaceful garden')
        self.set_desc('Enclosed by a tall wooden fence, this small grassy '
          'garden seems very private.  There is a small stone bench nestled up '
          'against the trunk of a blossoming cherry tree, short dense grass '
          'filling the rest of the area.  There is a door leading into the '
          'house to the south.')
#       self.set_exits(['south':'stirling.world.dev.room.house'])
