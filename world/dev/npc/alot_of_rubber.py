'''
/world/dev/room/alot.py
emsenn@Stirling
250411

Part of the test suite, this is an alot.
'''

from stirling.obj.living.npc import NPC

class Alot(NPC):
    def __init__(self):
        super(Alot, self).__init__()
        self.set_name('alot of rubber')
        self.set_desc('This squeaky fellow is an alot of rubber.  Matte black '
          'eyes are inset in his smooth polymer body.')
