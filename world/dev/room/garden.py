'''
/world/dev/room/garden.py
emsenn@Stirling
250411

Part of the test suite, this is an example garden.  At the moment it simply 
demonstrates available room functions, nothing special.
'''

from stirling.lib.obj.room import Room

class Garden(Room):
    def __init__(self):
        super(Garden, self).__init__()
        self.set_name('peaceful garden')
        self.set_desc('Enclosed by the brick walls and windows of the adjacent '
          'buildings, this small grassy garden seems very private.  There is a '
          'small stone bench nestled up against the trunk of a blossoming '
          'cherry tree, short dense grass filling the rest of the area.')
