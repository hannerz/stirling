"""
/lib/std/object.py
abzde@Stirling
150411 emsenn@Stirling

The master object of the MUD, all objects inherit it at some point
"""

from stirling.lib.std.object import MasterObject

class Living(MasterObject):
    def __init__(self):
        super(Living, self).__init__()

    def tell(self, data):
        super(Living, self).tell(data)
