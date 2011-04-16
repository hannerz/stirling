"""
/lib/std/object.py
abzde@Stirling
150411 emsenn@Stirling

The master object of the MUD, all objects inherit it at some point
"""


class MasterObject:
    def __init__(self):
        self.name = 'object'
        self.inventory = []
        self.environment = __class__

    def set_name(self, name):
        self.name = name
        return
    def name(self):
        return name

    def move(self, destination):
        # move the object from one environment to another
        if isinstance(destination, MasterObject) == True:
            destination.add_inventory(self)
            self.environment = destination
        return
    def remove(self):
        # remove the object from the game
        return
    # This is a very simplistic way of doing inventories.  When we add in 
    # doing everything in memory via a database, this will change lots.  Oh boy!
    def add_inventory(self, item):
        if isinstance(item, MasterObject) == True:
            self.inventory.append(item)
            return
    def inventory(self, item=None):
        if item == None:
            return inventory
        else:
            if self.inventory.count(item) > 0:
                return True
            else:
                return False
    def tell(self, data):
        pass
