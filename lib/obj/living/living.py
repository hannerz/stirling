"""
/lib/living.py
emsenn@Stirling
190411

The master object of the MUD, all objects inherit it at some point
"""

import sys

import logging
logger = logging.getLogger(__name__)
logger.debug('Imported')

from stirling.lib.obj.object import MasterObject
from stirling.lib.cmd import find_cmd

class Living(MasterObject):
    def __init__(self):
        super(Living, self).__init__()
        self.cmd_modules = ['cmd']

    def parse_line(self, line):
        cmd = False
        words = line.split()
        if len(words) == 0:
            return False
        cmd_name = words[0]
        try:
            args = words[1:]
        except:
            args = None
        cmd = find_cmd(cmd_name, self.cmd_modules)
        if not cmd:
            self.tell('No such command: %s\n' % (cmd_name,))
            return False
        try:
            if args is not None:
                kwargs = {}
                normargs = []
                for arg in args:
                    if arg.startswith('--'):
                        name, value = arg[2:].split('=')
                        kwargs[name] = value
                    elif arg.startswith('-'):
                        for name in arg[1:]:
                            kwargs[name] = True
                    else:
                        normargs.append(arg)
            return getattr(cmd, 'do_%s' % (cmd_name,))(self, *normargs, **kwargs)
        except TypeError:
            self.tell('Too many/few arguments to given to %s\n' % (cmd_name,))
            return False
        except:
            pass
            return False
