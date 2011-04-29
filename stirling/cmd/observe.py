def do_observe(obj, target='here'):
    '''
    usage: observe [target]
        returns the description of the target, defaulting to current environment
    '''
    near = []
    if target in ['room','here','environment']:
        obj.tell(obj.environment.desc+'\n')
        return
    elif target in ['self','me',obj.name]:
        obj.tell(obj.desc+'\n')
        return
    else:
        for item in obj.environment.inventory+obj.inventory:
            if target in item.nametags:
                obj.tell(item.desc+'\n')
            return
        obj.tell("Sorry, invalid syntax.")
        return
