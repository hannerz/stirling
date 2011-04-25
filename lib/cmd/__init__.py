import sys

def _find_cmd(cmd_name, cmd_modules):
    # check if given command exists in the command modules
    for module in cmd_modules:
        try:
            __import__('stirling.lib.%s.%s' % (module, cmd_name)) # try to import it
            cmd = sys.modules['stirling.lib.%s.%s' % (module, cmd_name)]
            return cmd
        except ImportError:
            continue # not here, check the next one
    else:
        # command doesn't exist
        return False
