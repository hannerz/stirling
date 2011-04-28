'''
A funky cigarette!  Written to celebrate April 20, 2011
from stirling.obj.object import MasterObject

class FunkyCigarette(MasterObject):
    def __init__(self):
        super(FunkyCigarette, self).__init__()
        self.set_name('funky cigarette')
        self.set_desc('This is a small hand-crafted cigarette.  The paper is so '
        'thin that the green flowers torn up and rolled inside are visible.')
