def do_observe(obj, target='here', v=False, t=False, s=False, n=False):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    near = []
    output = ''
    if target in ['room','here','environment']:
        if n is True:
            output += '['+obj.environment.name+']\n'
        output += obj.environment.desc+'\n'
    elif target in ['self','me',obj.name]:
        if n is True:
            output += '['+obj.name+']\n'
        output += obj.desc+'\n'
    else:
        for item in obj.environment.inventory+obj.inventory:
            if target in item.nametags:
                if n is True:
                    output += '['+item.name+']\n'
                output += item.desc+'\n'
    obj.tell(output)
    return
