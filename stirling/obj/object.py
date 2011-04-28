"""
/lib/std/object.py
abzde@Stirling
280411 emsenn@Stirling

The master object of the MUD, all objects inherit it at some point
"""

import logging
logging.basicConfig(level=logging.DEBUG)

class MasterObject:
    def __init__(self):
        # Any variable which should be persistent needs to be set to default 
        # values in the __init__ of the library inheritable
        # (NOTE: Does this actually work?  I've read that [] is == None, which 
        # makes this kind of null and void.  Can we overwrite that if it's 
        # the proper approach?
        self.name = 'object'
        self.desc = 'This is a thing.'
        self.inventory = []
        self.environment = __class__ # This *does* make a blank class, right?
        self.logger = logging.getLogger(self.__module__)
        self.logger.debug('Initalized')

    def debug(self, message):
        self.logger.debug(message)
    def info(self, message):
        self.logger.info(message)
    # The two most basic functions: give an object a name and query it.
    def set_name(self, name):
        if isinstance(name, str):
            self.name = name
        return
    def name(self):
        return name

    def set_desc(self, desc):
        if isinstance(desc, str):
            self.desc = desc
    def desc(self):
        return desc


    # Move and remove
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
    

    def tell(self, message):
        if isinstance(message, str):
            pass
        pass
    
    # Implement some sort of error handling
