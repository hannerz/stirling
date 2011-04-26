'''
/world/dev/room/house.py
emsenn@Stirling
260411

Part of the test suite, this is an example house.
'''

from stirling.lib.obj.room import Room

class House(Room):
    def __init__(self):
        super(House, self).__init__()
        self.set_name('quaint house')
        self.set_desc('This is a small wooden ranch house.  A door leads east '
          'to the street.')
#       self.set_exits(['east':'stirling.world.dev.room.street'])
