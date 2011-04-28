"""
/obj/living/npc.py
emsenn@Stirling
250411

    Inheritable for NPCs.  Doesn't do anything, but we're going to need it so 
*shrug*.
"""

import logging
logger = logging.getLogger(__name__)
logger.debug('Imported')

from stirling.lib.obj.living.living import Living

class NPC(Living):
    def __init__(self):
        super(NPC, self).__init__()

    def tell(self, data):
        super(NPC, self).tell(data)
