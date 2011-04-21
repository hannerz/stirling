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
        print('parsing '+line)
        words = line.split()
        cmd_name = words[0]
        try:
            args = words[1:]
        except:
            args = None
        # check if given command exists in the command modules
        for module in self.command_modules:
            try:
                print('try to import')
                print('stirling.lib.%s.%s' % (module, cmd_name)) # try to import it
                __import__('stirling.lib.%s.%s' % (module, cmd_name)) # try to import it
                cmd = sys.modules['stirling.lib.%s.%s' % (module, cmd_name)]
                print('found')
                break
            except ImportError: 
                print('import error')
                continue # not here, check the next one
        else:   
            # command doesn't exist
            # do stuff
            print('no such')
            self.tell('No such command: %s\n' % (cmd_name,))
            return False
        try:
            print('call')
            print(cmd)
            return cmd.do_cmd(self, *args)
        except TypeError:
            self.tell('Too many/few arguments to given to %s\n' % (cmd_name,))
            return False
        except:
            print('uh..')
            pass
            return False


