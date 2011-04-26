'''
/world/dev/obj/toothpick.py
emsenn@Stirling
250411

Part of the test suite, this is an example toothpick.
'''

from stirling.lib.obj.object import MasterObject

class Toothpick(MasterObject):
    def __init__(self):
        super(Toothpick, self).__init__()
        self.set_name('toothpick')
        self.set_desc('A small sliver of pale wood, about two inches long.')
