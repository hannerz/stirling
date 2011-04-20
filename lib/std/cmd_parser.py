class CommandParser(object):
    def __init__(self, parent_obj, search_modules):
        self.parent_obj = parent_obj
        self.search_modules = search_modules

    def parse(self, line):
        print('parsing '+line)
        words = line.split()
        cmd_name = words[0]
        try:
            args = words[1:]
        except:
            args = None
        # check if given command exists
        for module in self.search_modules:
            try:
                print('try to import')
                print(module, cmd_name)
                cmd = __import__('stirling.lib.%s.%s' % (module, cmd_name)) # try to import it
                print('found')
                break
            except ImportError: 
                print('import error')
                continue # not here, check the next one
        else:   
            # command doesn't exist
            # do stuff
            print('no such')
            self.parent_obj.tell('No such command: %s' % (cmd_name,))
            return False
        try:
            print('call')
            return cmd.do_cmd(self.parent_obj, *args)
        except TypeError:
            self.parent_obj.tell('Too many/few arguments to given to %s' % (cmd_name,))
            return False
        except:
            print('uh..')
            pass
            return False

