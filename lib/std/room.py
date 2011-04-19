"""
/lib/std/room.py
emsenn@Stirling 190411

    The base room inheritable
"""

from stirling.lib.std.object import MasterObject

class Room(MasterObject):
    def __init__(self):
        super(Room, self).__init__()

    def write(self, data):
        for item in self.inventory:
            item.tell(data+'\n')

