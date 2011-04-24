"""
/lib/living.py
emsenn@Stirling
190411

The master object of the MUD, all objects inherit it at some point
"""

import sys

from stirling.lib.std.object import MasterObject

class Living(MasterObject):
    def __init__(self):
        super(Living, self).__init__()
        self.command_modules = ['std.cmd']

    def parse_line(self, line):
        words = line.split()
        cmd_name = words[0]
        try:
            args = words[1:]
        except:
            args = None
        # check if given command exists in the command modules
        for module in self.command_modules:
            try:
                __import__('stirling.lib.%s.%s' % (module, cmd_name)) # try to import it
                cmd = sys.modules['stirling.lib.%s.%s' % (module, cmd_name)]
                break
            except ImportError: 
                continue # not here, check the next one
        else:   
            # command doesn't exist
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


