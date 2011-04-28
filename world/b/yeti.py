'''
/world/dev/npc/yeti.py
ploosk@Stirling
280411

The yeti. The Yeti.
'''

from stirling.obj.living.npc import NPC

class Yeti(NPC):
    def __init__(self):
        super(Yeti, self).__init__()
        self.set_name('unrapeable yeti')
        self.set_desc('This is a large, white yeti. It stares at you through '
          'a coating of ice which has formed on its fur. It looks like it '
          'would be pretty hard to rape.')

