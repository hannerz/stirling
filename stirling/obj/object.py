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
        self.nametags = ['object']
        self.name = 'generic thing'
        self.desc = 'This is a thing.'
        self.inventory = []
        self.environment = __class__ # This *does* make a blank class, right?
        # Initialize the object's logging
        self.logger = logging.getLogger(self.__module__)

    
    def debug(self, message):
        self.logger.debug(message)
        return
    def info(self, message):
        self.logger.info(message)
        return
    def warning(self, message):
        self.logger.warning(message)
        self.tell('You have caused a minor error.  Please report:\n'+message)
        return
    def error(self, message):
        self.logger.error(message)
        self.tell('++ERROR++ Please report the following:\n'+message) 
        return

    def add_nametag(self, tag):
        if isinstance(tag, str):
            if self.nametags.count(tag) is 0:
                self.nametags.append(tag)
                return
    def rm_nametag(self, tag):
        if isinstance(tag, str):
            if self.nametags.count(tag) is 0:
                return
            else:
                self.nametags.remove(tag)
                return
    def has_nametag(self, tag):
        if isinstance(tag, str):
            if self.nametag.count(tag) >= 1:
                return True
            else:
                return False


    def set_name(self, name):
        ''' set_name(name)
            Sets the object's name to string 'name'.  An object's name acts as 
            its main displayed identity.  For example, a man named Fat Sally 
            might use set_name('Fat Sally')
        '''
        if isinstance(name, str):
            self.rm_nametag(self.name)
            self.add_nametag(name.lower())
            self.name = name
        else:
            self.warning('set_name() passed incorrect type; expecting string')
        return

    def set_desc(self, desc):
        if isinstance(desc, str):
            self.desc = desc

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
