'''
/world/dev/room/alot_of_yetis.py
emsenn@Stirling
280411

Part of the test suite, this is an alot.
'''

from stirling.lib.obj.living.npc import NPC

class Alot(NPC):
    def __init__(self):
        super(Alot, self).__init__()
        self.set_name('alot of yetis')
        self.set_desc('This abominable fuzzball is an alot made entirely from '
          'yetis.')
