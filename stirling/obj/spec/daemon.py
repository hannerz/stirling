"""
/stirling/obj/spec/daemon.py
emsenn@Stirling
280411

The daemon inheritable for the MUD.
"""

from stirling.obj.object import MasterObject

class Daemon(MasterObject):
    def __init__(self):
        super(Daemon, self).__init__()
