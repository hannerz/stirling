"""
/lib/std/room.py
emsenn@Stirling 190411

    The base room inheritable
"""

from stirling.lib.std.object import MasterObject

class Room(MasterObject):
    def def__init__(self):
        super(Room, self).__init__()
        self.exits = []
    def write(self, data):
        """
        write(text)
        
        Outputs the string text to everything in the room's inventory.
        """
        # Need to add a link to the microsyntax interpretter when we have it.
        for item in self.inventory:
            item.tell(data+'\n')
    
