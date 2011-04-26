'''
/world/dev/room/street.py
emsenn@Stirling
260411

Part of the test suite, this is an example house.
'''

from stirling.lib.obj.room import Room

class Street(Room):
    def __init__(self):
        super(Street, self).__init__()
        self.set_name('paved street')
        self.set_desc('This is a narrow paved street between a small house and '
          'a store.  The road continues south from here.')
#       self.set_exits(['east':'stirling.world.dev.room.store',
#         'south':'stirling.world.dev.room.clearing'])
