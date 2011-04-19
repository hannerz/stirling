"""
/lib/living.py
emsenn@Stirling
190411

The master object of the MUD, all objects inherit it at some point
"""

from stirling.lib.std.object import MasterObject

class Living(MasterObject):
    def __init__(self):
        super(Living, self).__init__()
