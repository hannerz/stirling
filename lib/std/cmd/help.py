import sys

from stirling.lib.std.cmd_helpers import find_cmd

def trim(docstring):
    if not docstring:
        return ''
    # Convert tabs to spaces (following the normal Python rules)
    # and split into a list of lines:
    lines = docstring.expandtabs().splitlines()
    # Determine minimum indentation (first line doesn't count):
    indent = sys.maxsize
    for line in lines[1:]:
        stripped = line.lstrip()
        if stripped:
            indent = min(indent, len(line) - len(stripped))
    # Remove indentation (first line is special):
    trimmed = [lines[0].strip()]
    if indent < sys.maxsize:
        for line in lines[1:]:
            trimmed.append(line[indent:].rstrip())
    # Strip off trailing and leading blank lines:
    while trimmed and not trimmed[-1]:
        trimmed.pop()
    while trimmed and not trimmed[0]:
        trimmed.pop(0)
    # Return a single string:
    return '\n'.join(trimmed) + '\n'

def do_help(obj, cmd_name=None):
    '''
    usage: help [command]
        returns command specific help or this help message
    '''
    if cmd_name:
        cmd = find_cmd(cmd_name, obj.cmd_modules)
        try:
            doc = getattr(cmd, 'do_%s' % (cmd_name,)).__doc__
        except:
            doc = 'No help for this command..\n'
        obj.tell(trim(doc))
    else:
        obj.tell('This is stirling mud. Try `help <command name>` for help ' +
                 'on specific commands\n')

